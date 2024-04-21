/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "PKIX1Explicit88"
 * 	found in "rfc5280-a.1.asn1"
 * 	`asn1c -Werror -fcompound-names -fwide-types -D asn1/asn1c -no-gen-PER -no-gen-example`
 */

#ifndef	_RelativeDistinguishedName_H_
#define	_RelativeDistinguishedName_H_


#include "asn1/asn1c/asn_application.h"

/* Including external dependencies */
#include "asn1/asn1c/asn_SET_OF.h"
#include "asn1/asn1c/constr_SET_OF.h"

/* Forward declarations */
struct AttributeTypeAndValue;

/* RelativeDistinguishedName */
typedef struct RelativeDistinguishedName {
	A_SET_OF(struct AttributeTypeAndValue) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RelativeDistinguishedName_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RelativeDistinguishedName;
extern asn_SET_OF_specifics_t asn_SPC_RelativeDistinguishedName_specs_1;
extern asn_TYPE_member_t asn_MBR_RelativeDistinguishedName_1[1];

/* Referred external types */
#include "asn1/asn1c/AttributeTypeAndValue.h"

#endif	/* _RelativeDistinguishedName_H_ */
#include "asn1/asn1c/asn_internal.h"
