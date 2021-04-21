#KDIR = /lib/modules/`uname -r`/build
KDIR = ~/workspace/linux/raspberrypi-linux/linux

CROSS_COMPILE?=aarch64-linux-gnu-
ARCH?=arm64

kbuild:
	make -C $(KDIR) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) M=`pwd` modules

clean:
	make -C $(KDIR) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) M=`pwd` clean

