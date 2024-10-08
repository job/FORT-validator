/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CryptographicMessageSyntax2004"
 * 	found in "rfc5652-12.1.asn1"
 * 	`asn1c -Werror -fcompound-names -fwide-types -D asn1/asn1c -no-gen-PER -no-gen-example`
 */

#ifndef	_SignatureAlgorithmIdentifier_H_
#define	_SignatureAlgorithmIdentifier_H_

#include "asn1/asn1c/AlgorithmIdentifier.h"

/* SignatureAlgorithmIdentifier */
typedef AlgorithmIdentifier_t	 SignatureAlgorithmIdentifier_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SignatureAlgorithmIdentifier;
asn_struct_free_f SignatureAlgorithmIdentifier_free;
asn_struct_print_f SignatureAlgorithmIdentifier_print;
asn_constr_check_f SignatureAlgorithmIdentifier_constraint;
ber_type_decoder_f SignatureAlgorithmIdentifier_decode_ber;
der_type_encoder_f SignatureAlgorithmIdentifier_encode_der;
xer_type_encoder_f SignatureAlgorithmIdentifier_encode_xer;

#endif	/* _SignatureAlgorithmIdentifier_H_ */
