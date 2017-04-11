/*
	This is the main user software application
	In this case, we have below the code necessary to toggle a set of LEDs on a	STM32 F3 Discovery PCB at 20 Hz.

	(c) Abhimanyu Ghosh, 2017
 */

#include "cpu.h"
#include "board_led.h"
#include "uart.h"

#include "foo.h"

#include <stdio.h>

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
    Initialize UART1 connected to PA9 and PA10 at 115200 Baud, 8n1:
   */
  uart_debug_init();

  int i = 0;

  /*
    Test stdio redirection, after disabling buffered I/O for UART comms:
   */
  setvbuf(stdin,NULL,_IONBF,0);   // Sets stdin in unbuffered mode (normal for usart com)
  setvbuf(stdout,NULL,_IONBF,0);  // Sets stdin in unbuffered mode (normal for usart com)
  
  printf("Hello World!!\r\n");

  int led_command = 0;

  /*
    In an infinite loop, keep toggling the LEDs in an alternating pattern:
   */
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
      printf("Enter a number to command LED1 and LED2. Choices:\r\n");
      printf("0: LED1, LED2 OFF\r\n");
      printf("1: LED1 ON, LED2 OFF\r\n");
      printf("2: LED1 OFF, LED2 ON\r\n");
      printf("3: LED1, LED2 ON\r\n");

      scanf("%d", &led_command);

      switch(led_command)
      {
        case 0:
          board_led_off(LED1);
          board_led_off(LED2);
          break;
        case 1:
          board_led_on(LED1);
          board_led_off(LED2);
          break;
        case 2:
          board_led_off(LED1);
          board_led_on(LED2);
          break;
        case 3:
          board_led_on(LED1);
          board_led_on(LED2);
          break;
        default:
          printf("ERROR: Invalid Command!!\r\n");
          board_led_off(LED1);
          board_led_off(LED2);
          break;
      }
    }
  }

  return 0;
}
