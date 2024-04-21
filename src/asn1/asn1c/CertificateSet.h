/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CryptographicMessageSyntax2004"
 * 	found in "rfc5652-12.1.asn1"
 * 	`asn1c -Werror -fcompound-names -fwide-types -D asn1/asn1c -no-gen-PER -no-gen-example`
 */

#ifndef	_CertificateSet_H_
#define	_CertificateSet_H_


#include "asn1/asn1c/asn_application.h"

/* Including external dependencies */
#include "asn1/asn1c/ANY.h"
#include "asn1/asn1c/asn_SET_OF.h"
#include "asn1/asn1c/constr_SET_OF.h"

/* CertificateSet */
typedef struct CertificateSet {
	A_SET_OF(ANY_t) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CertificateSet_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CertificateSet;
extern asn_SET_OF_specifics_t asn_SPC_CertificateSet_specs_1;
extern asn_TYPE_member_t asn_MBR_CertificateSet_1[1];

#endif	/* _CertificateSet_H_ */
#include "asn1/asn1c/asn_internal.h"
