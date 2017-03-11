/*
	This is an example Assembly application that implements a "Hello World" in the 
	form of blinking an LED on the STM32F3 Discovery Board.

	(c) Abhimanyu Ghosh, 2017
 */

/* Define some possibly-useful constants */

.equ RCC_base, 0x40021000
.equ RCC_AHB_reg, 0x40021014

.equ GPIO_base, 0x48001000
.equ GPIO_MODE, 0x48001000
.equ GPIO_OTYPE, 0x48001004
.equ GPIO_OSPEED, 0x48001008
.equ GPIO_ODR, 0x48001014
.equ GPIO_PUPD, 0x4800100C
.equ GPIO_BSRR, 0x48001018

.equ DELAY_RELOAD_VAL, 0xFF00

/* 
	We tell the assembler/linker that this code goes in the "text"
	section, as defined in the linker.ld file
*/

    .section	.text.main
	.weak	main
	.type	main, %function
	.syntax unified

main:
	cpsid i
	ldr R0, =RCC_AHB_reg
	ldr R1, [R0]
	orr R1, R1, #(0x01 << 21)
	str R1,[R0]

	ldr R0, =GPIO_MODE
	ldr R1, [R0]
	orr R1, R1, #(0x01 << 18)
	str R1, [R0]

	ldr R0, =GPIO_ODR
	ldr R1, [R0]
	orr R1, R1, #(0x01 << 9)
	str R1, [R0]

SimpleInfLoop:
	mov R1, DELAY_RELOAD_VAL
Delay1:
	sub R1, R1, #0x1
	cbnz R1, jmp_Delay1
	b TogglePin
jmp_Delay1:
	b Delay1
TogglePin:
	ldr R0, =GPIO_ODR
	ldr R1, [R0]
	eor R1, R1, #(0x01 << 9)
	str R1, [R0]
	b SimpleInfLoop
