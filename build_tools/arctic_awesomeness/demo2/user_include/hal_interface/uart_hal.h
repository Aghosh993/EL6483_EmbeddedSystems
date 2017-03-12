#ifndef UART_HAL_H_
#define UART_HAL_H_		1

#include "hal_common_includes.h"

typedef enum {
	UART_PORT1
} uart_port;

void uart_hal_init(uart_port port);

void uart_hal_send_byte_blocking(uart_port port, uint8_t data);
uint8_t uart_hal_get_byte_blocking(uart_port port);

#endif