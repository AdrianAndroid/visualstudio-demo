#include "chapter01.h"
#include <iostream>


namespace c01
{
	void test1()
	{
		int i = 0;
		int x = 0;
		i++;
		++i;
		x = i++;
		x = ++i;
	}
}

void testChapter01()
{
	c01::test1();
	getchar();
}