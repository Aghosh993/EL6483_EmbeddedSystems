/*
	This is the main user software application
	In this case, we have below the code necessary to toggle a set of LEDs on a	STM32 F3 Discovery PCB at 1 Hz.

	(c) Abhimanyu Ghosh, 2016
 */

#include "cpu.h"
#include "board_led.h"

int main()
{
  cpu_init();
  board_led_init();

	while(1)
	{
    board_led_on(LED1);
    board_led_off(LED2);
    
    cpu_sw_delay(50U);  

    board_led_off(LED1);
    board_led_on(LED2);

    cpu_sw_delay(50U);
	}

	return 0;
}