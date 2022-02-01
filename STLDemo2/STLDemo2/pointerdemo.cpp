#include "pointerdemo.h"
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//生成随机数
int * getRandom()
{
	static int r[10];
	int i;

	// rand
	srand((unsigned)time(NULL));
	for (i = 0; i < 10; ++i)
	{
		r[i] = rand();
		printf("%d\n", r[i]);
	}
	return r;
}

void test1()
{
	int *p;
	int i;
	p = getRandom();
	for (i = 0; i < 10; i++)
	{
		printf("*(p + [%d]) -> %p : %d\n", i, &p + i, *(p + i));
	}
}


const int MAX = 3;

void test2()
{
	int var[] = { 10, 100, 200 };
	int i, *ptr;

	ptr = var;
	for (i = 0; i < MAX; i++)
	{
		printf("存储地址：var[%d] = %p\n", i, ptr);
		printf("存储值：var[%d] = %d\n", i, *ptr);
		ptr++;
	}
}

void test3()
{
	int var[] = { 10, 100, 200 };
	int i;
	for ( i = 0; i < MAX; i++)
	{
		printf("Value of var[%d] = %d\n", i, var[i]);
	}
}

void test4()
{
	int var[] = { 10,100,200 };
	int i, *ptr[MAX];
	for (i = 0; i < MAX; i++)
	{
		ptr[i] = &var[i];
	}
	for (i = 0; i < MAX; i++)
	{
		printf("Value of var[%d] = %d\n", i, *ptr[i]);
	}
}

void test5()

{
	int MAX = 4;
	const char *names[] = {
		"Zara Ali",
		"Hina Ali",
		"Nuha Ali",
		"Sara Ali",
	};
	char _name[] = "ZHAO jian";
	printf("Value of names[%d] = %s\n", -1, _name);
	int i;
	for (i = 0; i < MAX; i++)
	{
		printf("Value of names[%d] = %s\n", i, names[i]);
	}
}

void getSeconds(unsigned long *ptr)
{
	*ptr = time(NULL);
	return;
}

void test6()
{
	unsigned long sec;
	getSeconds(&sec);

	printf("Number of seconds:%ld\n", sec);
}


double getAverage(int *arr, int size)
{
	int i, sum = 0;
	double avg;

	for ( i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	avg = (double)sum / size;
	return avg;
}

void getAverage2(int *arr, int size, double* result)
{
	int i, sum = 0;
	double avg;

	for (i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	avg = (double)sum / size;
	*result = avg;
}

void test7()
{
	int balance[5] = { 1000, 2, 3, 17, 50 };
	double avg;

	avg = getAverage(balance, 5);
	printf("Average value is : %f \n", avg);

	double result;
	getAverage2(balance, 5, &result);
	printf("Average value is : %f \n", result);
}

void pointerdemo()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test7();
}
