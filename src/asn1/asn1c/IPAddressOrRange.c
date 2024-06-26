/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IPAddrAndASCertExtn"
 * 	found in "rfc3779.asn1"
 * 	`asn1c -Werror -fcompound-names -fwide-types -D asn1/asn1c -no-gen-PER -no-gen-example`
 */

#include "asn1/asn1c/IPAddressOrRange.h"

asn_TYPE_member_t asn_MBR_IPAddressOrRange_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct IPAddressOrRange, choice.addressPrefix),
		(ASN_TAG_CLASS_UNIVERSAL | (3 << 2)),
		0,
		&asn_DEF_IPAddress,
		NULL,
		{ NULL, NULL, NULL },
		NULL, NULL, /* No default value */
		"addressPrefix"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct IPAddressOrRange, choice.addressRange),
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_IPAddressRange,
		NULL,
		{ NULL, NULL, NULL },
		NULL, NULL, /* No default value */
		"addressRange"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_IPAddressOrRange_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (3 << 2)), 0, 0, 0 }, /* addressPrefix */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 1, 0, 0 } /* addressRange */
};
asn_CHOICE_specifics_t asn_SPC_IPAddressOrRange_specs_1 = {
	sizeof(struct IPAddressOrRange),
	offsetof(struct IPAddressOrRange, _asn_ctx),
	offsetof(struct IPAddressOrRange, present),
	sizeof(((struct IPAddressOrRange *)0)->present),
	asn_MAP_IPAddressOrRange_tag2el_1,
	2,	/* Count of tags in the map */
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_IPAddressOrRange = {
	"IPAddressOrRange",
	"IPAddressOrRange",
	&asn_OP_CHOICE,
	NULL,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	NULL,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ NULL, NULL, CHOICE_constraint },
	asn_MBR_IPAddressOrRange_1,
	2,	/* Elements count */
	&asn_SPC_IPAddressOrRange_specs_1	/* Additional specs */
};
