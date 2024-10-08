/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CryptographicMessageSyntax2004"
 * 	found in "rfc5652-12.1.asn1"
 * 	`asn1c -Werror -fcompound-names -fwide-types -D asn1/asn1c -no-gen-PER -no-gen-example`
 */

#ifndef	_CMSSubjectKeyIdentifier_H_
#define	_CMSSubjectKeyIdentifier_H_

#include "asn1/asn1c/OCTET_STRING.h"

/* CMSSubjectKeyIdentifier */
typedef OCTET_STRING_t	 CMSSubjectKeyIdentifier_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CMSSubjectKeyIdentifier;
asn_struct_free_f CMSSubjectKeyIdentifier_free;
asn_struct_print_f CMSSubjectKeyIdentifier_print;
asn_constr_check_f CMSSubjectKeyIdentifier_constraint;
ber_type_decoder_f CMSSubjectKeyIdentifier_decode_ber;
der_type_encoder_f CMSSubjectKeyIdentifier_encode_der;
xer_type_encoder_f CMSSubjectKeyIdentifier_encode_xer;

#endif	/* _CMSSubjectKeyIdentifier_H_ */
