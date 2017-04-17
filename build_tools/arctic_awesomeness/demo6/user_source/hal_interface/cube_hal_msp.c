#include "hal_common_includes.h"

void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef* htim_pwm)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	if(htim_pwm->Instance == TIM1)
	{
		__HAL_RCC_TIM1_CLK_ENABLE();

		GPIO_InitStruct.Pin = GPIO_PIN_9 | GPIO_PIN_11;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF2_TIM1;
		
		__HAL_RCC_GPIOE_CLK_ENABLE();
		HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
	}
}