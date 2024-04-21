/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IPAddrAndASCertExtn"
 * 	found in "rfc3779.asn1"
 * 	`asn1c -Werror -fcompound-names -fwide-types -D asn1/asn1c -no-gen-PER -no-gen-example`
 */

#ifndef	_IPAddress_H_
#define	_IPAddress_H_


#include "asn1/asn1c/asn_application.h"

/* Including external dependencies */
#include "asn1/asn1c/BIT_STRING.h"

/* IPAddress */
typedef BIT_STRING_t	 IPAddress_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_IPAddress;
asn_struct_free_f IPAddress_free;
asn_struct_print_f IPAddress_print;
asn_constr_check_f IPAddress_constraint;
ber_type_decoder_f IPAddress_decode_ber;
der_type_encoder_f IPAddress_encode_der;
xer_type_encoder_f IPAddress_encode_xer;

#endif	/* _IPAddress_H_ */
#include "asn1/asn1c/asn_internal.h"
