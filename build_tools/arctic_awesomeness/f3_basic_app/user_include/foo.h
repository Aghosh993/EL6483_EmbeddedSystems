#ifndef FOO_H
#define FOO_H	1

/*
	A simple demonstration of a purely algorithmic library that can be run on either an embedded platform or
	one that is hosted on an operating system on a PC such as Linux or Windows.

	(c) Abhimanyu Ghosh, 2017
 */

/*
	A boilerplate function declaration of something really simple...
	Note: Do NOT name functions in such a nondescript way!!
 */

int foo(int i);

/*
	A simple "unit test" routine to test if the function above passes or fails our requirement
	for a set of inputs and outputs...

	Returns 0 on SUCCESS, or a negative integer on a FAILURE
 */

int TEST_FOO(int vector_input, int vector_output);

#endif