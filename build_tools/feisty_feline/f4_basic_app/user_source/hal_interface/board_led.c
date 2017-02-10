#include "board_led.h"

void board_led_init(void)
{
	static GPIO_InitTypeDef  GPIO_InitStruct;

	GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	__HAL_RCC_GPIOD_CLK_ENABLE();

	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
}

void board_led_on(led led_id)
{
	switch(led_id)
	{
		case LED1:
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
			break;
		case LED2:
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			break;
	}
}

void board_led_off(led led_id)
{
	switch(led_id)
	{
		case LED1:
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
			break;
		case LED2:
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
			break;
	}
}

void board_led_toggle(led led_id)
{
	switch(led_id)
	{
		case LED1:
			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
			break;
		case LED2:
			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
			break;
	}
}