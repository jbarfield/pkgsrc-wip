# $NetBSD: buildlink3.mk,v 1.1 2004/05/02 21:08:22 blef Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PHLIB_BUILDLINK3_MK:=	${PHLIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	phlib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nphlib}
BUILDLINK_PACKAGES+=	phlib

.if !empty(PHLIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.phlib+=	phlib>=1.20
BUILDLINK_PKGSRCDIR.phlib?=	../../wip/phlib
.endif	# PHLIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
