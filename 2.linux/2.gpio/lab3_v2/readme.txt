Edit rpi3 dts file:

diff --git a/arch/arm/boot/dts/bcm2837.dtsi b/arch/arm/boot/dts/bcm2837.dtsi
index 0199ec9..412f370 100644
--- a/arch/arm/boot/dts/bcm2837.dtsi
+++ b/arch/arm/boot/dts/bcm2837.dtsi
@@ -72,6 +72,23 @@
                        cpu-release-addr = <0x0 0x000000f0>;
                };
        };
+               
+       gpio1: gpio1 {
+               gpio_controller;
+               #gpio-cells = <2>;
+       };
+       led_sample_2 {
+               compatible = "my-led-2";
+               led-gpios = <&gpio1 17 GPIO_ACTIVE_HIGH>;
+               status = "okay";
+       };
 };

