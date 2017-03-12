# Recitation/Demo 4: LED blink on STM32 F3 Discovery board in ARM Assembly

This example blinks an LED purely in ARM assembly. The ONLY STMicroelectronics code used is the startup code, located in the "arch/stm32/f3/src/CMSIS/startup_stm32f303xc.s" file within arctic_awesomeness. That code performs some basic setup of the CPU, setting the stack pointer, and populating the vector table, after which it jumps to the main application located in the ".s" file in thsi example.

(c) Abhimanyu Ghosh, 2017