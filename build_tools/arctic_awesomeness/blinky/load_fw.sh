#!/bin/bash
$1/openocd -f ./stm32f3discovery.cfg &
$2/arm-none-eabi-gdb --batch --command=runme.gdb 
pkill openocd