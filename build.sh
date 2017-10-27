#!/bin/sh
rm -f *.o a.out b.bin
arm-none-eabi-gcc -c src/*.c -I./include -DNRF51 -mcpu=cortex-m0 -mthumb
arm-none-eabi-gcc -c src/*.s -I./include -DNRF51 -mcpu=cortex-m0 -mthumb
arm-none-eabi-gcc *.o  -mcpu=cortex-m0 -mthumb -T./nrf51_xxac.ld
arm-none-eabi-objcopy -O binary a.out b.bin

