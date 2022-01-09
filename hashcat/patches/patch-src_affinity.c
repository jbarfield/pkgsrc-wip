$NetBSD$

Fix the build for NetBSD

--- src/affinity.c.orig	2021-11-21 15:39:01.000000000 +0000
+++ src/affinity.c
@@ -45,6 +45,12 @@ static int pthread_setaffinity_np (pthre
 typedef cpuset_t cpu_set_t;
 #endif
 
+#if defined(__NetBSD__)
+#include <pthread.h>
+#include <sched.h>
+typedef cpuset_t cpu_set_t;
+#endif
+
 int set_cpu_affinity (MAYBE_UNUSED hashcat_ctx_t *hashcat_ctx)
 {
 #if defined (__CYGWIN__)
@@ -57,6 +63,10 @@ int set_cpu_affinity (MAYBE_UNUSED hashc
   #if defined (_WIN)
   DWORD_PTR aff_mask = 0;
   const int cpu_id_max = 8 * sizeof (aff_mask);
+  #elif defined(__NetBSD__)
+  cpuset_t * cpuset;
+  const int cpu_id_max = 8 * cpuset_size (cpuset);
+  cpuset = cpuset_create();
   #else
   cpu_set_t cpuset;
   const int cpu_id_max = 8 * sizeof (cpuset);
@@ -79,6 +89,9 @@ int set_cpu_affinity (MAYBE_UNUSED hashc
     {
       #if defined (_WIN)
       aff_mask = 0;
+      #elif defined (__NetBSD__)
+      cpuset_destroy (cpuset);
+      cpuset = cpuset_create ();
       #else
       CPU_ZERO (&cpuset);
       #endif
@@ -90,6 +103,10 @@ int set_cpu_affinity (MAYBE_UNUSED hashc
     {
       event_log_error (hashcat_ctx, "Invalid cpu_id %d specified.", cpu_id);
 
+      #if defined (__NetBSD__)
+      cpuset_destroy (cpuset);
+      #endif
+
       hcfree (devices);
 
       return -1;
@@ -97,12 +114,18 @@ int set_cpu_affinity (MAYBE_UNUSED hashc
 
     #if defined (_WIN)
     aff_mask |= ((DWORD_PTR) 1) << (cpu_id - 1);
+    #elif defined (__NetBSD__)
+    cpuset_set (cpu_id - 1, cpuset);
     #else
     CPU_SET ((cpu_id - 1), &cpuset);
     #endif
 
   } while ((next = strtok_r ((char *) NULL, ",", &saveptr)) != NULL);
 
+  #if defined (__NetBSD__)
+  cpuset_destroy (cpuset);
+  #endif
+
   hcfree (devices);
 
   #if defined (_WIN)
@@ -114,6 +137,19 @@ int set_cpu_affinity (MAYBE_UNUSED hashc
     return -1;
   }
 
+  #elif defined (__NetBSD__)
+
+  pthread_t thread = pthread_self ();
+
+  const int rc = pthread_setaffinity_np (thread, cpuset_size(cpuset), cpuset);
+
+  if (rc != 0)
+  {
+    event_log_error (hashcat_ctx, "pthread_setaffinity_np() failed with error: %d", rc);
+
+    return -1;
+  }
+
   #else
 
   pthread_t thread = pthread_self ();
