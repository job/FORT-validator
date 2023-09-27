/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "SignedObjectSyntax"
 * 	found in "rfc6488.asn1"
 * 	`asn1c -Werror -fcompound-names -fwide-types -D asn1/asn1c -no-gen-PER -no-gen-example`
 */

#include "asn1/asn1c/BinarySigningTime.h"

int
BinarySigningTime_constraint(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const BinaryTime_t *st = (const BinaryTime_t *)sptr;
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Check if the sign bit is present */
	value = st->buf ? ((st->buf[0] & 0x80) ? -1 : 1) : 0;
	
	if((value >= 0)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

/*
 * This type is implemented using BinaryTime,
 * so here we adjust the DEF accordingly.
 */
static asn_oer_constraints_t asn_OER_type_BinarySigningTime_constr_1 CC_NOTUSED = {
	{ 0, 1 }	/* (0..MAX) */,
	-1};
static const ber_tlv_tag_t asn_DEF_BinarySigningTime_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (2 << 2))
};
asn_TYPE_descriptor_t asn_DEF_BinarySigningTime = {
	"BinarySigningTime",
	"BinarySigningTime",
	&asn_OP_INTEGER,
	asn_DEF_BinarySigningTime_tags_1,
	sizeof(asn_DEF_BinarySigningTime_tags_1)
		/sizeof(asn_DEF_BinarySigningTime_tags_1[0]), /* 1 */
	asn_DEF_BinarySigningTime_tags_1,	/* Same as above */
	sizeof(asn_DEF_BinarySigningTime_tags_1)
		/sizeof(asn_DEF_BinarySigningTime_tags_1[0]), /* 1 */
	{ &asn_OER_type_BinarySigningTime_constr_1, 0, BinarySigningTime_constraint },
	0, 0,	/* No members */
	0	/* No specifics */
};
