/*
	This is the main user software application
	In this case, we have below the code necessary to toggle a set of LEDs on a	STM32 F3 Discovery PCB at 20 Hz.

	(c) Abhimanyu Ghosh, 2017
 */

#include "cpu.h"
#include "board_led.h"

#include "foo.h"
#include "uart.h"

int main()
{
  /*
    Initialize the PLL, clock tree to all peripherals, flash and Systick 1 ms time reference:
   */
  cpu_init();
  /*
    Initialize the GPIO (General-Purpose I/O) subsystem pins that are connected to the LEDs on the board:
   */
  board_led_init();

  /*
    Initialize the debug UART port:
   */
  uart_debug_init();

  /*
    Send a single byte in blocking mode:
   */
  // uart_send_byte_blocking(UART_PORT1, 'a');

  /*
    Send a sequence of bytes over the UART:
   */
  uart_send_data_blocking(UART_PORT1, (uint8_t *)"Hello World!!\r\n", 15U);

  int i = 0;

  while(1)
  {
    /*
      Carry out a simple unit test of foo() declared in foo.h:
     */
    if(TEST_FOO(i, i+1) < 0)
    {
      /*
        If the above fails there is either a hardware, code or other undefined error.
        Now we're in an undefined state regarding processor core behavior...
       */
      while(1); // We probably have had a radiation hit or a major malfunction on the ALU of the processor...
    }
    else
    {
      board_led_on(LED1);
      board_led_off(LED2);

      cpu_sw_delay(50U);  // Invoke a simple software busy-wait routine to delay approximately 50 milliseconds

      board_led_off(LED1);
      board_led_on(LED2);

      cpu_sw_delay(50U);

      ++i; // Increment i for the next test iteration...
    }
  }

  return 0;
}