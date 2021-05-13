#Run with uboot

1. Copy binary to sdcard
```sudo cp build/kernel8.uimg /media/${user}/boot```

2. Start Raspberry

```
U-Boot 2021.07-rc1-dirty (May 11 2021 - 21:49:57 +0700)

DRAM:  948 MiB
RPI 3 Model B (0xa02082)
MMC:   mmc@7e202000: 0, sdhci@7e300000: 1
Loading Environment from FAT... OK
In:    serial
Out:   vidconsole
Err:   vidconsole
Net:   No ethernet found.
starting USB...
Bus usb@7e980000: USB DWC2
scanning bus usb@7e980000 for devices... 
Error: smsc95xx_eth address not set.
2 USB Device(s) found
       scanning usb for storage devices... 0 Storage Device(s) found
Hit any key to stop autoboot:  0 
U-Boot>
```

3. Load kernel image by uboot

```
U-boot> fatload mmc 0 0x80000 kernel8.uimg
U-Boot> bootm 0x80000
## Booting kernel from Legacy Image at 00080000 ...
   Image Name:   
   Image Type:   AArch64 Linux Kernel Image (uncompressed)
   Data Size:    292 Bytes = 292 Bytes
   Load Address: 00080000
   Entry Point:  00080000
   Verifying Checksum ... OK
   Loading Kernel Image

Starting kernel ...
```
