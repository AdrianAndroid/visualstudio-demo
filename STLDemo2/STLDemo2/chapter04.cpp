#include "chapter04.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

namespace c04 
{
	// itoa()  将整型值转化为字符串
	// ltoa()  将长整型值转换为字符串
	// ultoa() 将无符号长整型转换为字符串
	// gcvt()  将浮点型转化为字符串，取四舍五入
	// ecvt()  将双精度浮点型值转换为字符串，转换结果中不包含十进制小数点
	// fcvt()  以指定位数为转换精度，其余同ecvt()
	void test01()
	{
		int num_int = 435;
		double num_double = 435.10f;
		char str_int[30];
		char str_double[30];

		itoa(num_int, str_int, 10);
		gcvt(num_double, 8, str_double);

		printf("str_int:%s\n", str_int);
		printf("str_double:%s\n", str_double);
	}

	void int2str(int n, char *str)
	{
		char buf[10] = "";
		int i = 0;
		int len = 0;
		int temp = n < 0 ? -n : n;       //temp 为n的绝对值
		if (str == NULL)
		{
			return;
		}
		while (temp)
		{
			buf[i++] = (temp % 10) + '0'; // 把temp的每一位上的数存入buf
			temp = temp / 10;
		}
		len = n < 0 ? ++i : i;            //如果n时负数，则多需要一位来存储负号
		str[i] = 0;
		while (1)
		{
			i--;
			if(buf[len-i-1] == 0)
			{
				break;
			} 
			str[i] = buf[len - i - 1];   //把buf数组里的字符拷贝到字符串
		}
		if (i == 0)
		{
			str[i] = '-';                //如果时负数，添加一个负号
		}
	}

	void test02()
	{
		int nNum;
		char p[10];

		cout << "Please input an integer:";
		cin >> nNum;
		cout << "output:";
		int2str(nNum, p);                // 整型整数转换成字符串
		cout << p << endl;
	}

	// 面试题3 使用库函数将字符串转换为数字
	// atof()    将字符串转换为双精度浮点型值
	// atoi()    将字符串转换为整型值
	// atol()    将字符串转换为长整型值
	// strtod()	 将字符串转换为双精度浮点型值，并报告不能被转换的所有剩余数字
	// strtol()  将字符串转换为长整型值，并报告不能被转换啊的所有剩余数字
	// strtoul() 将字符串转换为无符号长整型值，并报告不能被转换的所有剩余数字。
	void test03()
	{
		int num_int;
		double num_double;
		char str_int[30] = "435";
		char str_double[30] = "435.55";

		num_int = atoi(str_int);
		num_double = atof(str_double);

		printf("num_int:%d\n", num_int);
		printf("num_double:%lf\n", num_double);
	}

	int str2int(const char *str)
	{
		int temp = 0;
		const char *ptr = str;
		if (*str == '-' || *str == '+')
		{
			str++;
		}
		while (*str != 0)
		{
			if ((*str < '0') || (*str > '9'))
			{
				break; //如果不是数字，则退出循环
			}
			temp = temp * 10 + (*str - '0');
			str++;
		}
		if (*ptr == '-')
		{
			temp = -temp;
		}
		return temp;
	}

	void test04()
	{
		int n = 0;
		char p[10] = "";
		cin.getline(p, 20);
		n = str2int(p);
		cout << n << endl;
	}

	class Test
	{
	public:
		char * const strcpy2(char *strDest, const char * strSrc) const;
		char * test() {}
	};
	class TestBase :public Test
	{
		char * const strcpy2(char *strDest, const char * strSrc) const {}

		void test() {}
	};


	char * strcpy(char *strDest, const char * strSrc) 
	{
		if ((strDest == NULL) || (strSrc == NULL))
		{
			return NULL;
		}
		char *strDestCopy = strDest;
		while ((*strDest++ = *strSrc++) != '\0');
		return strDestCopy;
	}

	int getStrLen(const char * srcSrc)
	{
		int len = 0;
		while (*srcSrc++ != '\0') len++;
		return len;
	}

	void test05()
	{
		char strSrc[] = "Hello World!";
		char strDest[20];
		int len = 0;

		len = getStrLen(strcpy(strDest, strSrc));
		printf("strDest:%s\n", strDest);
		printf("Length of strDest:%d\n", len);
	}
#include<assert.h>
	void *mempcpy2(void *memTo, const void *memFrom, size_t size)
	{
		assert((memTo != NULL) && (memFrom != NULL));
		char *tempFrom = (char *)memFrom;
		char *tempTo = (char *)memTo;
		while (size-- > 0) *tempTo++ = *tempFrom++;
		return memTo;
	}

	void test06()
	{
		char strSrc[] = "Hello World!";
		char strDest[20];
		mempcpy2(strDest, strSrc, 4); //复制前4个字符
		strDest[4] = '\0';
		printf("strDest:%s\n", strDest);
	}

	void test10()
	{
		int a[5] = { 0,1,2,3,4 }, *p;
		p = a;
		printf("%d\n", *(p + 4 * sizeof(int)));
	}

	void RevStr( char *src)
	{
		 char *start = src, *end = src, *ptr = src;
		while (*ptr++ != '\0');
		end = ptr - 2; //找到字符串的末尾
		while (start < end) swap(*start++, *end--);
		start = src, end = ptr - 2;
		ptr = start;
		while (*ptr++ != '\0')
		{
			if (*ptr == ' ' || *ptr == '\0')
			{
				end = ptr - 1;
				while (start < end) swap(*start++,*end--);
				start = end = ptr + 1;
			}
		}
	}
	void test13()
	{
		char src[] = "I am from Shanghai";
		cout << src << endl;
		RevStr(src);
		cout << src << endl;
	}

	int mystrcmp(const char* src, const char* dst)
	{
		int ret = 0;

		while (!(ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst)
		{
			++src;
			++dst;
		}
		if (ret < 0)
			ret = -1;
		else if (ret > 0)
			ret = 1;
		return ret;
	}

	void test15()
	{
		char str[10] = "1234567";
		char str1[10] = "1234567";
		char str2[10] = "12345678";
		char str3[10] = "1234566";

		int test1 = mystrcmp(str, str1);
		int test2 = mystrcmp(str, str2);
		int test3 = mystrcmp(str, str3);

		cout << "test1 = " << test1 << endl;
		cout << "test2 = " << test2 << endl;
		cout << "test3 = " << test3 << endl;
	}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	char* commonstring(char *str1, char* str2)
	{
		int i, j;
		char *shortstr, *longstr;
		char *substr;
		if (NULL == str1 || NULL == str2)
		{
			return NULL;
		}
		if (strlen(str1) <= strlen(str2))
		{
			shortstr = str1;
			longstr = str2;
		} else {
			shortstr = str2;
			longstr = str1;
		}
		if (strstr(longstr, shortstr) != NULL)
		{
			return shortstr;
		}
		substr = (char *)malloc(sizeof(char) * (strlen(shortstr) + 1));
		for (i = strlen(shortstr) - 1; i > 0; i--)
		{
			for (j = 0; j <= strlen(shortstr) - i; j++)
			{
				memcpy(substr, &shortstr[j], i);
				substr[i] = '\0';
				if (strstr(longstr, substr) != NULL) return substr;
			}
		}
		return NULL;
	}

	void test16()
	{
		char *str1 = (char *)malloc(256);
		char *str2 = (char *)malloc(256);

		char *common = NULL;
		gets_s(str1, sizeof(str1));
		gets_s(str2, sizeof(str2));
		common = commonstring(str2, str1);
		printf("the longest common string is:%s\n", common);
	}

	char *get2String(long num)
	{
		int i = 0;
		char* buffer;
		char* temp;

		buffer = (char*)malloc(33);
		temp = buffer; //temp
		for (i = 0; i < 32; i++)
		{
			temp[i] = num & (1 <<(31 -i));
			temp[i] = temp[i] >> (31-i);
			temp[i] = (temp[i] == 0) ? '0' : '1';
		}
		buffer[32] = '\0';
		return buffer;
	}

	char* get16String(long num)
	{
		int i = 0;
		char* buffer = (char *)malloc(11);
		char *temp;
		buffer[0] = '0';//0x
		buffer[1] = 'x';
		buffer[10] = '\0';
		temp = buffer + 2;

		for (i = 0; i < 8; i++)
		{
			temp[i] = (char)(num<< 4 * i >> 28);
			temp[i] = temp[i] >= 0 ? temp[i] : temp[i] + 16;
			temp[i] = temp[i] < 10 ? temp[i] + 48 : temp[i] + 55;
		}
		return buffer;
	}

	void test17()
	{
		char *p = NULL;
		char *q = NULL;
		int num = 0;
		printf("input num: ");
		scanf("%d", &num);

		p = get16String(num);
		q = get2String(num);

		printf("%s\n", p);
		printf("%s\n", q);
	}

#define MAXCOUNT 2*100
	char *transformation(char *str)
	{
		int len = strlen(str);
		char *buf = new char[len + 1];

		char *p = str;
		char *q = p + 1;
		int count = 1;
		while (*q)
		{
			if (*p == *q)
			{
				count++;
				p++;
				q++;
			}
			else {
				itoa(count, buf, 10);
				int nbits = strlen(buf);
				strcat(buf, q);
				*q = 0;
				strcat(str, buf);
				q += nbits;
				p = q;
				q = p + 1;
				count = 1;
			}
		}
		itoa(count, buf, 10);
		strcat(str, buf);

		delete[]buf;
		buf = NULL;
		return str;
	}

	void test19()
	{
		char str[MAXCOUNT];

		printf("Please input a string;");
		scanf("%s", &str);
		printf("before transformation:%s\n", str);
		char *pstr = transformation(str);
		printf("after transformation:%s\n", pstr);
	}
}

struct SPoint
{
	int x;
	int y;
	void print()
	{

	}
	SPoint(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
private/*:
	void print1()
	{

	}*/
};

void testChapter04()
{
	c04::test17();
	//c04::test15();
	//c04::test13();
	//c04::test10();
	//c04::test06();
	//c04::test05();
	//c04::test04();
	//c04::test03();
	//c04::test02();
	//c04::test01();
	getchar();
}