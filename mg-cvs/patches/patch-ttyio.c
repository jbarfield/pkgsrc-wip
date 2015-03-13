$NetBSD: patch-ttyio.c,v 1.1 2015/03/13 22:08:53 krytarowski Exp $

SunOS needs sys/filio.h for FIONREAD.

--- ttyio.c.orig	2008-12-11 08:59:08.000000000 +0000
+++ ttyio.c
@@ -14,6 +14,9 @@
 #include <sys/types.h>
 #include <sys/time.h>
 #include <sys/ioctl.h>
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 #include <fcntl.h>
 #include <termios.h>
 #include <term.h>
