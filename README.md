# rpi-labs

Embedded programing on Rpi3 

## 1. Download the image
https://www.raspberrypi.org/software/operating-systems/
	
## 2. Flash image to SD card
```
sudo dd if=raspberrypios-image.img of=/dev/sdb bs=4M conv=fsync status=progress
sdb
   sdb1
   sdb2
```
https://www.raspberrypi.org/documentation/installation/installing-images/linux.md

## 3. Download CROSS_COMPILE
```
$ wget https://releases.linaro.org/components/toolchain/binaries/latest-7/aarch64-linux-gnu/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu.tar.xz
$ tar -xf gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu.tar.xz -C ~/tools
$ export PATH=~/tools/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin:$PATH
```
## 4. Build raspberrypi u-boot
```
$ git clone git://git.denx.de/u-boot.git # v2021.01-rc2-121-g5b8991c667f7
$ cd u-boot
$ make ARCH=arm CROSS_COMPILE=aarch64-linux-gnu- rpi_3_b_plus_defconfig
$ make ARCH=arm CROSS_COMPILE=aarch64-linux-gnu-
```
https://www.thegoodpenguin.co.uk/blog/build-boot-linux-on-raspberry-pi-3-model-b/

## 5. Buil your rapsberrpi kernel
```
$ git clone --depth=1 https://github.com/raspberrypi/linux
$ cd linux
$ KERNEL=kernel8
$ make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- bcmrpi3_defconfig
$ make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- Image modules dtbs -j$(nproc)
```
https://www.raspberrypi.org/documentation/linux/kernel/building.md

## 6. Flash SD card
#copy u boot binary </br>
```
cd u-boot
cp u-boot.bin /media/binhht/boot
```
#copy linux binary </br>
```
cd linux
sudo cp /media/binhht/boot/$KERNEL.img /media/binhht/boot/$KERNEL-backup.img
sudo cp arch/arm64/boot/Image /media/binhht/boot/$KERNEL.img
sudo cp arch/arm64/boot/dts/broadcom/*.dtb /media/binhht/boot/
sudo cp arch/arm64/boot/dts/overlays/*.dtb* /media/binhht/boot/overlays/
sudo cp arch/arm64/boot/dts/overlays/README /media/binhht/boot/overlays/
```
## 7. Configure boot image
Add following cmd to config.txt
```
#kernel image
arm_64bit=1
#kernel=kernel8.img
kernel=u-boot.bin
```
https://www.raspberrypi.org/documentation/configuration/config-txt/boot.md

## 8. Configure uart
Add following cmd to config.txt
```
#uart enable
enable_uart=1
core_freq=250
```
https://www.raspberrypi.org/documentation/configuration/uart.md

## 9. Connect terminal
```
sudo screen -m /dev/ttyUSB0 115200
Login: pi
Passwork: raspberry
```

## 10. Enable wlan
```
sudo raspi-config
```
https://www.raspberrypi.org/documentation/configuration/wireless/wireless-cli.md

## 11. Enable ssh
```
sudo raspi-config
```
https://www.raspberrypi.org/documentation/remote-access/ssh/

## 12. Add newuser
```
sudo adduser binhht
sudo usermod -aG sudo binhht
```
