/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IPAddrAndASCertExtn"
 * 	found in "rfc3779.asn1"
 * 	`asn1c -Werror -fcompound-names -fwide-types -D asn1/asn1c -no-gen-PER -no-gen-example`
 */

#ifndef	_IPAddressOrRange_H_
#define	_IPAddressOrRange_H_


#include "asn1/asn1c/asn_application.h"

/* Including external dependencies */
#include "asn1/asn1c/IPAddress.h"
#include "asn1/asn1c/IPAddressRange.h"
#include "asn1/asn1c/constr_CHOICE.h"

/* Dependencies */
typedef enum IPAddressOrRange_PR {
	IPAddressOrRange_PR_NOTHING,	/* No components present */
	IPAddressOrRange_PR_addressPrefix,
	IPAddressOrRange_PR_addressRange
} IPAddressOrRange_PR;

/* IPAddressOrRange */
typedef struct IPAddressOrRange {
	IPAddressOrRange_PR present;
	union IPAddressOrRange_u {
		IPAddress_t	 addressPrefix;
		IPAddressRange_t	 addressRange;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} IPAddressOrRange_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_IPAddressOrRange;
extern asn_CHOICE_specifics_t asn_SPC_IPAddressOrRange_specs_1;
extern asn_TYPE_member_t asn_MBR_IPAddressOrRange_1[2];

#endif	/* _IPAddressOrRange_H_ */
#include "asn1/asn1c/asn_internal.h"
