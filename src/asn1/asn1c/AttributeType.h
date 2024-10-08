/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "PKIX1Explicit88"
 * 	found in "rfc5280-a.1.asn1"
 * 	`asn1c -Werror -fcompound-names -fwide-types -D asn1/asn1c -no-gen-PER -no-gen-example`
 */

#ifndef	_AttributeType_H_
#define	_AttributeType_H_

#include "asn1/asn1c/OBJECT_IDENTIFIER.h"

/* AttributeType */
typedef OBJECT_IDENTIFIER_t	 AttributeType_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AttributeType;
asn_struct_free_f AttributeType_free;
asn_struct_print_f AttributeType_print;
asn_constr_check_f AttributeType_constraint;
ber_type_decoder_f AttributeType_decode_ber;
der_type_encoder_f AttributeType_encode_der;
xer_type_encoder_f AttributeType_encode_xer;

#endif	/* _AttributeType_H_ */
