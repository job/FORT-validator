/*
 * Copyright (c) 2004-2017 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include "asn1/asn1c/ANY.h"

#include <assert.h>
#include <errno.h>

#include "asn1/asn1c/asn_internal.h"
#include "asn1/asn1c/ber_decoder.h"
#include "asn1/asn1c/der_encoder.h"
#include "asn1/asn1c/json_encoder.h"
#include "asn1/asn1c/xer_encoder.h"

asn_OCTET_STRING_specifics_t asn_SPC_ANY_specs = {
	sizeof(ANY_t),
	offsetof(ANY_t, _asn_ctx),
	ASN_OSUBV_ANY
};
asn_TYPE_operation_t asn_OP_ANY = {
	OCTET_STRING_free,
	OCTET_STRING_print,
	OCTET_STRING_compare,
	OCTET_STRING_decode_ber,
	OCTET_STRING_encode_der,
	OCTET_STRING_encode_json,
	ANY_encode_xer,
	NULL	/* Use generic outmost tag fetcher */
};
asn_TYPE_descriptor_t asn_DEF_ANY = {
	"ANY",
	"ANY",
	&asn_OP_ANY,
	NULL, 0, NULL, 0,
	{ NULL, NULL, asn_generic_no_constraint },	/* No constraints */
	NULL, 0,	/* No members */
	&asn_SPC_ANY_specs,
};

#undef RETURN
#define RETURN(_code)                       \
    do {                                    \
        asn_dec_rval_t tmprval;             \
        tmprval.code = _code;               \
        tmprval.consumed = consumed_myself; \
        return tmprval;                     \
    } while(0)

asn_enc_rval_t
ANY_encode_xer(const asn_TYPE_descriptor_t *td, const void *sptr, int ilevel,
               int flags, asn_app_consume_bytes_f *cb,
               void *app_key) {
    if(flags & XER_F_CANONICAL) {
		/*
		 * Canonical XER-encoding of ANY type is not supported.
		 */
		ASN__ENCODE_FAILED;
	}

	/* Dump as binary */
	return OCTET_STRING_encode_xer(td, sptr, ilevel, flags, cb, app_key);
}

struct _callback_arg {
	uint8_t *buffer;
	size_t offset;
	size_t size;
};

static int ANY__consume_bytes(const void *buffer, size_t size, void *key);

int
ANY_fromType(ANY_t *st, asn_TYPE_descriptor_t *td, void *sptr) {
	struct _callback_arg arg;
	asn_enc_rval_t erval;

	if(!st || !td) {
		errno = EINVAL;
		return -1;
	}

	if(!sptr) {
		if(st->buf) FREEMEM(st->buf);
		st->size = 0;
		return 0;
	}

	arg.offset = arg.size = 0;
	arg.buffer = NULL;

	erval = der_encode(td, sptr, ANY__consume_bytes, &arg);
	if(erval.encoded == -1) {
		if(arg.buffer) FREEMEM(arg.buffer);
		return -1;
	}
	assert((size_t)erval.encoded == arg.offset);

	if(st->buf) FREEMEM(st->buf);
	st->buf = arg.buffer;
	st->size = arg.offset;

	return 0;
}

ANY_t *
ANY_new_fromType(asn_TYPE_descriptor_t *td, void *sptr) {
	ANY_t tmp;
	ANY_t *st;

	if(!td || !sptr) {
		errno = EINVAL;
		return NULL;
	}

	memset(&tmp, 0, sizeof(tmp));

	if(ANY_fromType(&tmp, td, sptr)) return NULL;

	st = (ANY_t *)CALLOC(1, sizeof(ANY_t));
	if(st) {
		*st = tmp;
		return st;
	} else {
		FREEMEM(tmp.buf);
		return NULL;
	}
}

int
ANY_to_type(ANY_t *st, asn_TYPE_descriptor_t *td, void **struct_ptr) {
	asn_dec_rval_t rval;
	void *newst = NULL;

	if(!st || !td || !struct_ptr) {
		errno = EINVAL;
		return -1;
	}

	if(st->buf == NULL) {
		/* Nothing to convert, make it empty. */
		*struct_ptr = (void *)0;
		return 0;
	}

	rval = ber_decode(td, (void **)&newst, st->buf, st->size);
	if(rval.code == RC_OK) {
		*struct_ptr = newst;
		return 0;
	} else {
		/* Remove possibly partially decoded data. */
		ASN_STRUCT_FREE(*td, newst);
		return -1;
	}
}

static int ANY__consume_bytes(const void *buffer, size_t size, void *key) {
	struct _callback_arg *arg = (struct _callback_arg *)key;

	if((arg->offset + size) >= arg->size) {
		size_t nsize = (arg->size ? arg->size << 2 : 16) + size;
		void *p = REALLOC(arg->buffer, nsize);
		if(!p) return -1;
		arg->buffer = (uint8_t *)p;
		arg->size = nsize;
	}

	memcpy(arg->buffer + arg->offset, buffer, size);
	arg->offset += size;
	assert(arg->offset < arg->size);

	return 0;
}

json_t *
ANY_to_json(const asn_TYPE_descriptor_t *td, ANY_t const *ber)
{
	return ber2json(td, ber->buf, ber->size);
}
