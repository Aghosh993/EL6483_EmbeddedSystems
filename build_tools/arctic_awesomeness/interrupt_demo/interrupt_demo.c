/*
	This is the main user software application
	In this case, we have below the code necessary to toggle a set of LEDs on a	STM32 F3 Discovery PCB at 20 Hz.

	(c) Abhimanyu Ghosh, 2017
 */

#include "cpu.h"
#include "board_led.h"

#include "foo.h"

/*
  This function initializes the SysTick interrupt so that we get a SysTick interrupt at 1 Hz:
 */

static void cpu_periodic_task_init(void)
{

}

/*
  This function shall be called from within the SysTick ISR (Interrupt Service Routine):
 */

void cpu_periodic_callback(void)
{

}

int main()
{
  /*
    Initialize the PLL, clock tree to all peripherals:
   */
  cpu_init();
  /*
    Initialize the GPIO (General-Purpose I/O) subsystem pins that are connected to the LEDs on the board:
   */
  board_led_init();

  /*
    Initialize a periodic Systick interrupt (NOTE: We're now doing this INDEPENDENTLY of the HAL-provided SysTick init driver!)
   */
  cpu_periodic_task_init();

  /*
    Do a whole lot of nothing here...
   */
  while(1);

  return 0;
}
