# $NetBSD$

BUILDLINK_TREE+=	go-xid

.if !defined(GO_XID_BUILDLINK3_MK)
GO_XID_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-xid=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-xid?=		build

BUILDLINK_API_DEPENDS.go-xid+=	go-xid>=20201019
BUILDLINK_PKGSRCDIR.go-xid?=	../../wip/go-xid
.endif	# GO_XID_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-xid