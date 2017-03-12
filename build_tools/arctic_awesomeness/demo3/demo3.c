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
  SysTick->LOAD  = (uint32_t)8000000;                               /* set reload register */
  NVIC_SetPriority (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL); /* set Priority for Systick Interrupt */
  SysTick->VAL   = 0UL;                                             /* Load the SysTick Counter Value */
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                   SysTick_CTRL_TICKINT_Msk   |
                   SysTick_CTRL_ENABLE_Msk;                         /* Enable SysTick IRQ and SysTick Timer */
}

/*
  This function shall be called from within the SysTick ISR (Interrupt Service Routine):
 */

void cpu_periodic_callback(void)
{
  board_led_toggle(LED1);
  board_led_toggle(LED2);
}

void SysTick_Handler(void)
{
  cpu_periodic_callback();  
}

int main()
{
  // No PLL init, just use default 8 MHz internal RC clock...

  /*
    Initialize the GPIO (General-Purpose I/O) subsystem pins that are connected to the LEDs on the board:
   */
  board_led_init();
  board_led_on(LED1);
  board_led_off(LED2);

  /*
    Initialize a periodic Systick interrupt (NOTE: We're now doing this INDEPENDENTLY of the HAL-provided SysTick init driver!)
   */
  cpu_periodic_task_init();

  /*
    Do a whole lot of nothing here...
   */
  while(1);

  return 0; // Getting here is a violation of intergalactic law and probably means we've been hit by cosmic rays...
}
