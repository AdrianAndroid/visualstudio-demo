// pointer_demo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int main()
{
	// ʹ�ò���
	char *p1 = (char *)1;
	printf("%d", p1);
	int *p2 = (int *) p1;
	printf("%d", p2);
	getchar();
	return 0;
}

