#include "uart.h"

void uart_debug_init(void)
{
	uart_init(DEBUG_UART);
}

void uart_init(uart_port port)
{
	uart_hal_init(UART_PORT1);
}

uint8_t uart_get_byte_blocking(uart_port port)
{
	return uart_hal_get_byte_blocking(port);
}

void uart_send_byte_blocking(uart_port port, uint8_t data)
{
	uart_hal_send_byte_blocking(port, data);
}

void uart_get_data_blocking(uart_port port, uint8_t* data, uint8_t len)
{
	uint8_t i = 0U;

	for(i=0U; i<len; ++i)
	{
		data[i] = uart_hal_get_byte_blocking(port);
	}

}

void uart_send_data_blocking(uart_port port, uint8_t* data, uint8_t len)
{
	uint8_t i = 0U;

	for(i=0U; i<len; ++i)
	{
		uart_hal_send_byte_blocking(port, data[i]);
	}
}