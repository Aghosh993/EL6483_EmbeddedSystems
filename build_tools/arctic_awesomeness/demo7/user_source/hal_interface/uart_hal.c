#include "uart_hal.h"

UART_HandleTypeDef UartHandle;

static void UART1_Init(void)
{
	UartHandle.Instance        = USART1;

	UartHandle.Init.BaudRate     = 115200;
	UartHandle.Init.WordLength   = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits     = UART_STOPBITS_1;
	UartHandle.Init.Parity       = UART_PARITY_NONE;
	UartHandle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode         = UART_MODE_TX_RX;
	UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;
	UartHandle.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;

	HAL_UART_DeInit(&UartHandle);

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
			while((__HAL_UART_GET_FLAG(&UartHandle, UART_FLAG_TXE) ? SET : RESET) == RESET);
			UartHandle.Instance->TDR = (uint16_t)data;
			break;
		default:
			break;
	}
}

uint8_t uart_hal_get_byte_blocking(uart_port port)
{
	switch(port)
	{
		case UART_PORT1:
			while((__HAL_UART_GET_FLAG(&UartHandle, UART_FLAG_RXNE) ? SET : RESET) == RESET);
			return UartHandle.Instance->RDR;
		default:
			return 0;
	}
}