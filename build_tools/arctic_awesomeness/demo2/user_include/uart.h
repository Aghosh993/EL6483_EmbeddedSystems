#ifndef UART_H_
#define UART_H_		1

#include "uart_hal.h"

#define DEBUG_UART	UART_PORT1

void uart_debug_init(void);
void uart_init(uart_port port);

uint8_t uart_get_byte_blocking(uart_port port);
void uart_send_byte_blocking(uart_port port, uint8_t data);

void uart_get_data_blocking(uart_port port, uint8_t* data, uint8_t len);
void uart_send_data_blocking(uart_port port, uint8_t* data, uint8_t len);

#endif