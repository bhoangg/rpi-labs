#HIDL

1. Legacy hal
	device/raspberry/rpi3/userled
2. HIDL passthrough
	hardware/interfaces/hello
3. HIDL Binder
	hardware/interfaces/simple
4. Test legacy hal
	hardware/libhardware/tests/userled

Note: don't forget to edit manifest.xml and makefile
--- a/rpi3.mk
+++ b/rpi3.mk
@@ -41,6 +41,9 @@ PRODUCT_PACKAGES += \
     Chrome \
     RPiTool
 
+PRODUCT_PACKAGES += android.hardware.hello@1.0-service
+PRODUCT_PACKAGES += android.hardware.simple@2.0-service

--- a/manifest.xml
+++ b/manifest.xml
@@ -215,6 +215,24 @@
             <instance>default</instance>
         </interface>
     </hal>
+    <hal format="hidl">
+        <name>android.hardware.hello</name>
+        <transport>hwbinder</transport>
+        <version>1.0</version>
+        <interface>
+            <name>IHello</name>
+            <instance>default</instance>
+        </interface>
+    </hal>
+    <hal format="hidl">
+        <name>android.hardware.simple</name>
+       <transport>hwbinder</transport>
+        <version>2.0</version>
+        <interface>
+            <name>ISimphw</name>
+            <instance>default</instance>
+        </interface>
+    </hal>
