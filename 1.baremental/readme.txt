# Rpi Baremental

1. gpio
2. interrupt <- in progress
3. virtual memory <- todo

## Useful ARM instructions:

```
mrs: Load value from a system register to one of the general purpose registers (x0–x30)
and: Perform the logical AND operation. We use this command to strip the last byte from the value we obtain from the mpidr_el1 register.
cbz: Compare the result of the previously executed operation to 0 and jump (or branch in ARM terminology) to the provided label if the comparison yields true.
b: Perform an unconditional branch to some label.
adr: Load a label's relative address into the target register.
sub: Subtract values from two registers.
bl: "Branch with a link": perform an unconditional branch and store the return address in x30 (the link register). When the subroutine is finished, use the ret instruction to jump back to the return address.
mov: Move a value between registers or from a constant to a register.
```

## Run with uboot

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
