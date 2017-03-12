/*
	A simple demonstration of a purely algorithmic library that can be run on either an embedded platform or
	one that is hosted on an operating system on a PC such as Linux or Windows.

	(c) Abhimanyu Ghosh, 2017
 */

#include "foo.h"

int foo(int i)
{
	return i+1;
}

int TEST_FOO(int vector_input, int vector_output)
{
	if(foo(vector_input) != vector_output)
	{
		return -1;
	}
	return 0;
}