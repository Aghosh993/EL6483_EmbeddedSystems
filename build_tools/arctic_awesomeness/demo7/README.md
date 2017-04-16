# Demo 7: Redirection of STDIO to UART

This example shows how to set up UART1 using PA9 and PA10 on the STM32F3 Discovery board. The UART is configured at 115200 baud, 8n1 (8-bit data, no stop bit) and a set of functions is written in "newlib_stubs.c" in user_source, where a set of "driver" functions is written, overriding the "weak" default prototypes provided by "newlib" which is a reduced version of the C standard I/O library. 

One is usually familiar with the typical C "hello world" program where a string is printed to the console:

```C
#include <stdio.h>

int main(int argc, char** argv)
{
	printf("Hello World!!");
	return 0;
}
```

On a standard PC with an operating system, this is only possible because the C standard library is configured to interact with facilities provided by the underlying operating system (Windows, Linux, BSD, etc.) and write/read text to/from the console (usually when the program is being run from the command line.) For obvious reasons, we need to ourselves implement some of these facilities when we are running on an embedded platform (especially one where we're not usually running an RTOS or Real-Time Operating System). Thus, we must implement certain basic functions such as _sbrk() (this allocates memory on the heap, so that calls to malloc/calloc work), _read() (to read characters from the standard input) and _write() (to write characters to the standard output). This is what we do in the "newlib_stubs.c" file where we provide definitions of these functions to implement the ability to format input/output using our STM32's UART peripheral.

## Using this demo

This demo not only prints "Hello world" but also implements a simple command shell where the user can enter a number and set the states of two of the LEDs on the STM32 F3 Discovery Board. Users are encouraged to extend the demo and add the capability to command more LEDs and add more functionality.

## Hardware Note

This example requires a UART-USB converter to talk to the typical PC. One can use an FTDI cable such as [this](https://www.sparkfun.com/products/9873). Companies like Prolific and Silicon Labs also produce similar ICs that create a virtual UART COM port over USB. 

Students with an STM32 Interface board do not need a seperate USB-UART converter since it is built in to the PCB provided. One simply needs to load this demo and connect a micro=USB cable to the port on the PCB. On most modern versions of Windows, OS X and Linux the drivers should be found and load automatically.

(c) Abhimanyu Ghosh, 2017