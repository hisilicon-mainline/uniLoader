#!/bin/bash

make ARCH=aarch64 CROSS_COMPILE=aarch64-linux-gnu- clean
make ARCH=aarch64 CROSS_COMPILE=aarch64-linux-gnu- stanford_defconfig
make ARCH=aarch64 CROSS_COMPILE=aarch64-linux-gnu-

mkbootimg \
    --header_version 1 \
    --os_version 9.0.0 \
    --os_patch_level 2019-07 \
    --kernel uniLoader.gz \
    --ramdisk /dev/null \
    --pagesize 0x00000800 \
    --base 0x00078000 \
    --kernel_offset 0x00008000 \
    --ramdisk_offset 0x07b88000 \
    --second_offset 0x00e88000 \
    --tags_offset 0x07988000 \
    --board '' \
    --cmdline 'loglevel=4 initcall_debug=n page_tracker=on slub_min_objects=16 unmovable_isolate1=2:192M,3:224M,4:256M printktimer=0xfff0a000,0x534,0x538 androidboot.selinux=enforcing buildvariant=user' \
    -o uniLoader.img

fastboot flash kernel uniLoader.img erase rrecord erase misc reboot
