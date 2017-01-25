#!/bin/bash
openocd -f ./stm32f3discovery.cfg &
$1/arm-none-eabi-gdb --batch --command=runme.gdb 
pkill openocd