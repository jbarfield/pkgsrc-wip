# $NetBSD: options.mk,v 1.1 2009/08/18 15:26:29 plunky Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.hcidump
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CPPFLAGS+=	-DINET6
.endif
