// pointer_demo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	// 使用步长
	char *p1 = (char *)1;
	printf("%d", p1);
	int *p2 = (int *) p1;
	printf("%d", p2);
	getchar();
	return 0;
}

