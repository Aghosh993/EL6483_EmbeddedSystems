# UART Demo on the STM32 F3 Discovery

This example demos how to set up and use the UART on PD5 and PD6 on the STM32 F3 Discovery (Allocating these pins to USART2 operating in UART mode). USART2 is used in Asynchronous mode at 115200 baud, 8n1 (i.e. 8-bit data length, 1 stop bit, no parity bit) to print a "Hello World" message on a terminal emulator via a USB-Serial converter.

(c) Abhimanyu Ghosh, 2017