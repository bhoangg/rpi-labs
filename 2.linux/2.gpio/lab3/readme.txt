Edit rpi3 dts file:

diff --git a/arch/arm/boot/dts/bcm2837.dtsi b/arch/arm/boot/dts/bcm2837.dtsi
index 0199ec9..d55d3830 100644
--- a/arch/arm/boot/dts/bcm2837.dtsi
+++ b/arch/arm/boot/dts/bcm2837.dtsi
@@ -72,6 +72,14 @@
                        cpu-release-addr = <0x0 0x000000f0>;
                };
        };
+               
+       led_sample{
+               compatible = "my-led";
+               #address-cells = <1>;
+               #size-cells = <1>;
+               reg = <0x3F200000 0x100>;
+               status = "okay";
+       };
 };
 
 /* Make the BCM2835-style global interrupt controller be a child of the
