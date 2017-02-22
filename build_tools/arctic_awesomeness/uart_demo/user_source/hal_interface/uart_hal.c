#include "uart_hal.h"

static UART_HandleTypeDef UartHandle;

static void UART1_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;

	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_USART2_CLK_ENABLE();
	/* UART TX GPIO pin configuration  */
	GPIO_InitStruct.Pin       = GPIO_PIN_5;
	GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull      = GPIO_PULLUP;
	GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF7_USART2;

	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	/* UART RX GPIO pin configuration  */
	GPIO_InitStruct.Pin = GPIO_PIN_6;
	GPIO_InitStruct.Alternate = GPIO_AF7_USART2;

	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	UartHandle.Instance        = USART2;

	UartHandle.Init.BaudRate     = 115200;
	UartHandle.Init.WordLength   = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits     = UART_STOPBITS_1;
	UartHandle.Init.Parity       = UART_PARITY_NONE;
	UartHandle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode         = UART_MODE_TX_RX;
	UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;
	UartHandle.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;

	if(HAL_UART_Init(&UartHandle) != HAL_OK)
	{
		while(1);
	}
}

void uart_hal_init(uart_port port)
{
	switch(port)
	{
		case UART_PORT1:
			UART1_Init();
			break;
		default:
			break;
	}
}

void uart_hal_send_byte_blocking(uart_port port, uint8_t data)
{
	switch(port)
	{
		case UART_PORT1:
			HAL_UART_Transmit(&UartHandle, &data, 1U, 5000);
			break;
		default:
			break;
	}
}

uint8_t uart_hal_get_byte_blocking(uart_port port)
{
	uint8_t ret;

	switch(port)
	{
		case UART_PORT1:
			HAL_UART_Receive(&UartHandle, &ret, 1U, 5000);
			break;
		default:
			break;
	}
}