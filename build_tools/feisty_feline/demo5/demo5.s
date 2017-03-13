/*
	This is an example Assembly application that implements a Fibonacci Series calculator.
	For those who are unfamiliar, the Fibonacci Series is a set of numbers such that for 
	any 3 consecutive terms a, b, c in the series, the following relationship is true:

	c = a + b (Where the order is a, b, c in the Series)

	(c) Abhimanyu Ghosh, 2017
 */

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
	b Fibonacci

Fibonacci:
	mov R0, #0
	mov R1, #1
FibLoop:
	add R2, R0, R1
	mov R0, R1
	mov R1, R2
	b FibLoop
