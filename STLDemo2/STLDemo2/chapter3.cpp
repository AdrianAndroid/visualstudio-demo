#include "chapter3.h"

#include <iostream>
#include <string>
using namespace std;

// 面试题1 一般引用变量的引用
namespace c3{
	void test1()
	{
		int a = 10;
		int b = 20;
		int &rn = a;
		int equal;

		rn = b;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;

		rn = 100;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;

		equal = (&a == &rn) ? 1 : 0;
		cout << "equal = " << equal << endl;
	}

	void test2()
	{
		int a = 1;
		int b = 10;
		int* p = &a;
		int* &pa = p; //声明p的一个指针引用pa。

		(*pa)++;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cout << "p = " << *p << endl;

		pa = &b;
		(*pa)++;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cout << "p = " << *p << endl;


	}
	//利用传指针引用实现字符串交换的。由于swap函数时指针引用类型，因此传入函数的就是实参，而不是形参。
	void swap(char* &x, char* &y)
	{
		char *temp;
		temp = x;
		x = y;
		y = temp;
	}
	void swap2(char **x, char **y)
	{
		char *temp;
		temp = *x;
		*x = *y;
		*y = temp;
	}
	// 面试题4 如何交换两个字符串
	void test4()
	{
		char *ap = "hello";
		char *bp = "how are you?";

		cout << "ap:" << ap << endl;
		cout << "bp:" << bp << endl;
		
		swap(ap, bp);
		cout << "swap ap, bp" << endl;
		cout << "ap:" << ap << endl;
		cout << "bp:" << bp << endl;
	}

	const float pi = 3.14f;
	float f;
	float f1(float r)
	{
		f = r*r*pi;
		return f;
	}

	float& f2(float r)
	{
		f = r*r*pi;
		return f;
	}

	void test5()
	{
		float f1(float = 5); //声明函数f1()的默认参数调用，其默认参数值为5
		float& f2(float = 5); //声明函数f2()的默认参数调用，其默认参数值为5
		float a = f1();
		//float& b = f1();
		float c = f2();
		float& d = f2();

		d += 1.0f;
		cout << "a = " << a << endl;
		//cout << "b = " << b << endl;
		cout << "c = " << c << endl;
		cout << "d = " << d << endl;
		cout << "f = " << f << endl;
	}

	class Test
	{
	public:
		void f(const int& arg);
	private:
		int value;
	};


	void Test::f(const int& arg)
	{
		//arg = 10;
		cout << "arg = " << arg << endl;
		value = 20;
	}

	//面试题6 参数引用的常见错误
	void test6()
	{
		int a = 7;
		const int b = 10;
		//int &c = b; //不能使用常量类型变量定义非常量的引用
		const int &d = a;

		int y = 1;
		int& x = a;
		cout << "x=" << x << endl;
		x = y;
		cout << "x=" << x << endl;


		a++;
		//d++; //不能使用常量引用修改变量的值

		Test test;
		test.f(a);
		cout << "a = " << a << endl;
	}

	//面试题7 指针和引用有什么区别
	// 1. 初始化要求不同。引用在创建的同时必须初始化，即引用到一个有效的对象；而指针在定义的时候
	//		不必初始化，可以在定义后面的任何地方重新赋值
	// 2.可以修改性不同。引用一旦被初始化为指向一个对象，它就不能被改变为另一个对象的引用；
	//		而指针在任何时候都可以改变为指向另一个对象。给引用复制并不是改变它和原始对象的绑定关系
	// 3.不存在NULL引用，引用不能使用指向空值的引用，它必须总是指向某个对象；而指针则可以是NULL，不需要
	//		总是指向某些对象，可以把指针指向任意的对象，所以指针更加灵活，也容易出错
	// 4.测试需要的区别。由于引用不会指向空值，这意味着使用引用之前不需要测试它的合法性；而指针则需要
	//		经常进行测试。因此使用引用的代码效率比使用指针的要高
	// 5.应用的区别。如果是指一旦指向一个对象后就不会改变指向，那么应该使用引用。如果有存在指向NULL
	//		（不指向任何对象任何对象）或在不同的时刻指向不同的对象这些可能性，应该使用指针

	void test12()
	{
		char str1[] = "abc;";
		char str2[] = "abc";
		const char str3[] = "abc";
		const char str4[] = "abc";
		const char * str5 = "abc";
		const char * str6 = "abc";
		char* str7 = "abc";
		char* str8 = "abc";
		cout << (str1 == str2) << endl;
		cout << (str3 == str4) << endl;
		cout << (str5 == str6) << endl;
		cout << (str6 == str7) << endl;
		cout << (str7 == str8) << endl;
	}

	void test13()
	{
		char a;
		char *str1 = &a;
		char* str2 = "AAA";
		strcpy(str1, "hello");
		cout << str1 << endl;
		str2[0] = 'B';
		cout << str2 << endl;
	}

	void test14()
	{
		int ival = 1024;
		int ival2 = 2048;
		int *pi1 = &ival;
		int *pi2 = &ival2;
		int **pi3 = 0;

	/*	ival = *pi3;
		*pi2 = *pi3;
		ival = pi2;
		pi2 = *pi1;
		pi1 = *pi3;
		ival = *pi1;
		pi1 = ival;
		pi3 = &pi2;*/

	}

	// 面试题15 指针常量与常量指针的区别
	// 常量指针：表述为“是常量的指针”，它首先应该是一个指针
	// 指针常量：表述为“是指针的常量”，它首先应该是一个常量

	//如果const位于*号的左侧，则const就是用来修饰指针所指向的变量，即指针指向为常量；
	//如果const位于*号的右侧，const就是修饰指针本身，即指针本身就是常量。

	void test17()
	{
		const char* node1 = "abc";
		char *const node2 = "abc";

		//node1[2] = 'k';
		//*node1[2] = 'k';
		//*node1 = "xyz";
		node1 = "xyz";

		//node2[2] = 'k';
		//*node2[2] = 'k';
		//*node2 = "xyz";
		//node2 = "xyz";
	}

	class Obj 
	{
	public:
		Obj(void)
		{
			cout << "Initialization" << endl;
		}
		~Obj(void)
		{
			cout << "Destroy" << endl;
		}
	};

	void UseMallocFree(void)
	{
		cout << "in UseMallocFree()..." << endl;
		Obj *a = (Obj *)malloc(sizeof(Obj));
		free(a);
	}

	void UseNewDelete(void)
	{
		cout << "in UseNewDelete()" << endl;
		Obj *a = new Obj;
		delete a;
	}

	void test30()
	{
		UseMallocFree();
		UseNewDelete();
	}

	void GetMemory(char *p, int num)
	{
		p = (char *)malloc(sizeof(char) * num);
	}

	void getMemory2(char **p, int num)
	{
		*p = (char *)malloc(sizeof(char) * num);
	}

	void GetMemory3(char* &p, int num)
	{
		p = (char *)malloc(sizeof(char) * num);
	}

	char* GetMemory4(int num)
	{
		char *p = (char *)malloc(sizeof(char) * num);
		return p;
	}

	void test34()
	{
		char *str1 = NULL;
		char *str2 = NULL;
		char *str3 = NULL;
		char *str4 = NULL;

		getMemory2(&str2, 20);
		GetMemory3(str3, 20);

		strcpy(str2, "GetMemory 2");
		strcpy(str3, "GetMemory 3");
		strcpy(str4, "GetMemory 4");

		cout << "str1 == NULL? " << (str1 == NULL ? "yes" : "no") << endl;
		cout << "str2:" << str2 << endl;
		cout << "str3:" << str3 << endl;
		cout << "str4:" << str4 << endl;

		free(str2);
		free(str3);
		free(str4);
		str2 = NULL;
		str3 = NULL;
		str4 = NULL;
	}

	char *GetMemory__()
	{
		char p[] = "hello world";
		return p;
	}

	void Test(void)
	{
		char *str = NULL;
		str = GetMemory__();
		printf(str);
	}

	void GetMemory__2(char *p)
	{
		p = (char *)malloc(100);
	}
	void Test2(void)
	{
		char *str = NULL;
		GetMemory__2(str);
		strcpy(str, "hello world");
		printf(str);
	}

	// 面试题37 内存的分配方式有几种
	// 1. 从静态存储区域分配。内存在程序编译的时候就已经分配好，这块内存在程序的整个运行期间
	//		都存在，例如全局变量。
	// 2. 从栈上分配。在执行函数时，函数内局部变量的存储单元都可以在栈上创建，函数执行结束时
	//		这些存储单元自动被释放。处理器的指令集中有关于栈内存的分配运算，因此效率很高，但是
	//		分配的内存容量有限
	// 3. 从堆上分配。亦称动态内存分配。程序在运行的时候用malloc或new申请任意少的内存，程序员自己负责
	//		在何时用free或delete释放内存。动态内存的生存期由我们决定，使用非常灵活，但问题也最多。
}



void testChapter3() 
{
	c3::test30();
	//c3::test13();
	//c3::test12();
	//c3::test6();
	//c3::test5();
	//c3::test4();
	//c3::test2();
	//c3::test1();
	getchar();
}