# $NetBSD: buildlink3.mk,v 1.10 2020/10/12 21:51:57 bacon Exp $

BUILDLINK_TREE+=	blas64

.if !defined(BLAS64_BUILDLINK3_MK)
BLAS64_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.blas64+=	blas64>=3.9.0
BUILDLINK_ABI_DEPENDS.blas64+=	blas64>=3.9.0nb1
BUILDLINK_PKGSRCDIR.blas64?=	../../wip/blas64
.endif # BLAS64_BUILDLINK3_MK

BUILDLINK_TREE+=	-blas64