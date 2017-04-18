#include "button_hal.h"

static volatile int button_pressed_flag; 	// Holds whether or not a RISING edge has been detected
											// @wWarning: Access shared between EXTI0 ISR and user code!!

static void button_gpio_init(void)
{
	static GPIO_InitTypeDef  GPIO_InitStruct;
	/*
		PA0 Init
		Detect both edges, and route to the EXTI module so we can raise an interrupt accordingly
	 */

	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	__HAL_RCC_GPIOA_CLK_ENABLE(); // Enable clock to GPIOA so PA0 works

	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct); // Done
}

/*
	Performs EXTI initialization of PA0 <-> EXTI0
	Also initializes the button_pressed_flag to 0
 */

void button_init(void)
{
	button_pressed_flag = 0;
	button_gpio_init();	// set up the PA0 GPIO pin so it can connect to the edge detection subsystem

	HAL_NVIC_SetPriority(EXTI0_IRQn, 3, 4); // Set the priority according to the application needs
	HAL_NVIC_EnableIRQ(EXTI0_IRQn); // Enable (un-mask) the EXTI0 interrupt in the NVIC
}

int button_pressed(button b)
{
	int ret = button_pressed_flag; 	// Atomically save a copy of the button flag
	button_pressed_flag = 0; 		// Zero it atomically before returning
	return ret; 
}

/*
	EXTI IRQ Handlers. These call the generic EXTI IRQ handler from the Cube
	HAL, which in turn call the user-defined generic EXTI Callback function 
	defined further below:
 */

void EXTI0_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0); 	// This function will first clear the IRQ on EXTI0
											// It will then call the HAL_GPIO_EXTI_Callback below
}

/*
	User code section of the EXTI IRQ, called from HAL_GPIO_EXTI_IRQHandler
	after interrupt flags are cleared:
 */

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == GPIO_PIN_0) // This means we're sure we've gotten an EXTI event on pin 0
	{
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET) // If the pin is high now, it must've been a
																// RISING edge we captured
																// I.e. the button was PRESSED
		{
			button_pressed_flag = 1; // Set the flag since we've detected a button press event
		}
	}
}