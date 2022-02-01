#include<iostream>
#include<stdlib.h>
#include"common.h"

int main()
{
	PRINT("hello");
	WARNING_PRINT("warning_print");
	DEBUG_PRINT("debug_print");
	ERROR_PRINT("error_print");
	int *p = NULL;
	NULL_POINTER(p);
	getchar();
	return 0;
}