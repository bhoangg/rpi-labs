#KDIR = /lib/modules/`uname -r`/build
KDIR = ~/workspace/rpi/linux

CROSS_COMPILE?=~/tools/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-
ARCH?=arm64

kbuild:
	make -C $(KDIR) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) M=`pwd` modules

clean:
	make -C $(KDIR) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) M=`pwd` clean

