#include "crl.h"

#include <errno.h>
#include "algorithm.h"
#include "extension.h"
#include "log.h"
#include "thread_var.h"
#include "object/name.h"

static int
__crl_load(struct rpki_uri const *uri, X509_CRL **result)
{
	X509_CRL *crl;
	BIO *bio;
	int error;

	bio = BIO_new(BIO_s_file());
	if (bio == NULL)
		return crypto_err("BIO_new(BIO_s_file()) returned NULL");
	if (BIO_read_filename(bio, uri->local) <= 0) {
		error = crypto_err("Error reading CRL '%s'", uri->local);
		goto end;
	}

	crl = d2i_X509_CRL_bio(bio, NULL);
	if (crl == NULL) {
		error = crypto_err("Error parsing CRL '%s'", uri->local);
		goto end;
	}

	*result = crl;
	error = 0;

end:
	BIO_free(bio);
	return error;
}

static int
validate_revoked(X509_CRL *crl)
{
	STACK_OF(X509_REVOKED) *revoked_stack;
	X509_REVOKED *revoked;
	ASN1_INTEGER const *serial_int;
#ifdef DEBUG
	BIGNUM *serial_bn;
#endif
	int i;

	revoked_stack = X509_CRL_get_REVOKED(crl);
	if (revoked_stack == NULL)
		return 0; /* Guess the RFC doesn't enforce this thing. */

	for (i = 0; i < sk_X509_REVOKED_num(revoked_stack); i++) {
		revoked = sk_X509_REVOKED_value(revoked_stack, i);

		serial_int = X509_REVOKED_get0_serialNumber(revoked);
		if (serial_int == NULL) {
			return pr_err("CRL's revoked entry #%d lacks a serial number.",
			    i + 1);
		}

#ifdef DEBUG
		serial_bn = ASN1_INTEGER_to_BN(serial_int, NULL);
		if (serial_bn == NULL) {
			crypto_err("Could not parse revoked serial number");
			continue;
		}

		pr_debug_prefix();
		fprintf(stdout, "Revoked: ");
		BN_print_fp(stdout, serial_bn);
		fprintf(stdout, "\n");
		BN_free(serial_bn);
#endif

		if (X509_REVOKED_get0_revocationDate(revoked) == NULL) {
			return pr_err("CRL's revoked entry #%d lacks a revocation date.",
			    i + 1);
		}
		if (X509_REVOKED_get0_extensions(revoked) != NULL) {
			return pr_err("CRL's revoked entry #%d has extensions.",
			    i + 1);
		}
	}

	return 0;
}

static int
handle_crlnum(X509_EXTENSION *ext, void *arg)
{
	/*
	 * We're allowing only one CRL per RPP, so there's nothing to do here I
	 * think.
	 */
	return 0;
}

static int
validate_extensions(X509_CRL *crl)
{
	struct extension_handler handlers[] = {
	   /* ext   reqd   handler        arg */
	    { ext_aki(), true,  handle_aki,              },
	    { ext_cn(),  true,  handle_crlnum,           },
	    { NULL },
	};

	return handle_extensions(handlers, X509_CRL_get0_extensions(crl));
}

static int
crl_validate(X509_CRL *crl)
{
	long version;
	int error;

	version = X509_CRL_get_version(crl);
	if (version != 1)
		return pr_err("CRL version (%ld) is not v2 (%d).", version, 1);

	if (X509_CRL_get_signature_nid(crl) != rpki_signature_algorithm())
		return pr_err("CRL's signature algorithm is not RSASSA-PKCS1-v1_5.");

	error = validate_issuer_name("CRL", X509_CRL_get_issuer(crl));
	if (error)
		return error;

	error = validate_revoked(crl);
	if (error)
		return error;

	return validate_extensions(crl);
}

int
crl_load(struct rpki_uri const *uri, X509_CRL **result)
{
	int error;
	pr_debug_add("CRL '%s' {", uri_get_printable(uri));

	error = __crl_load(uri, result);
	if (!error)
		error = crl_validate(*result);

	pr_debug_rm("}");
	return error;
}
