#!/bin/bash
openocd -f ./stm32f3discovery.cfg &
sleep 2
$1/arm-none-eabi-gdb --batch --command=runme.gdb 
echo "Killing OpenOCD..."
pkill openocd
echo "Done."