/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CryptographicMessageSyntax2004"
 * 	found in "rfc5652-12.1.asn1"
 * 	`asn1c -Werror -fcompound-names -fwide-types -D asn1/asn1c -no-gen-PER -no-gen-example`
 */

#ifndef	_SignatureValue_H_
#define	_SignatureValue_H_

#include "asn1/asn1c/OCTET_STRING.h"

/* SignatureValue */
typedef OCTET_STRING_t	 SignatureValue_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SignatureValue;
asn_struct_free_f SignatureValue_free;
asn_struct_print_f SignatureValue_print;
asn_constr_check_f SignatureValue_constraint;
ber_type_decoder_f SignatureValue_decode_ber;
der_type_encoder_f SignatureValue_encode_der;
xer_type_encoder_f SignatureValue_encode_xer;

#endif	/* _SignatureValue_H_ */
