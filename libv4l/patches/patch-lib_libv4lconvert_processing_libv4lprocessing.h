$NetBSD$

--- lib/libv4lconvert/processing/libv4lprocessing.h.orig	2017-01-22 17:33:34.000000000 +0000
+++ lib/libv4lconvert/processing/libv4lprocessing.h
@@ -22,7 +22,7 @@
 #define __LIBV4LPROCESSING_H
 
 #include "../libv4lsyscall-priv.h"
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
