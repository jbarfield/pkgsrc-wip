$NetBSD$

Use unsigned char to work around narrowing conversion to char.
The vochdr array includes a value of 0xaa.

--- src/music.cpp.orig	2020-08-19 22:41:06.000000000 +0000
+++ src/music.cpp
@@ -65,7 +65,7 @@ void interrupt (*worxint8)(void)=NULL;
 
 void interrupt spkr_intr (void);
 
-const char vochdr[0x20]={
+const unsigned char vochdr[0x20]={
 	0x43,0x72,0x65,0x61,0x74,0x69,0x76,0x65,
 	0x20,0x56,0x6f,0x69,0x63,0x65,0x20,0x46,
 	0x69,0x6c,0x65,0x1a,0x1a,0x00,0x0a,0x01,