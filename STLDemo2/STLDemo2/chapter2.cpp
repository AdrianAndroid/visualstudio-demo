#include "chapter2.h"

// 预处理、const、stati、sizeof
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//#define DEBUG

//define最大值，最小值
//在宏中需要把参数小心地用括号括起来。因为宏只是简单的文本替换，如果不注意，很容易引起歧义
#define MAX(x,y) (((x) > (y)) ? (x) : (y))
#define MIN(x,y) (((x) < (y)) ? (x) : (y))
#define SQR(x) (x*x)
#define SQR(x) ((x) * (x))

int testIfdefEndIf();
void testDefine()
{
	int a = 1;
	int b = 2;
	printf("max 1,2 = %d", MAX(1, 2));
	printf("min 1,2 = %d", MIN(1, 2));
	getchar();
}

void testDefine2()
{
	int a, b = 3;
	a = SQR(b + 2); //==> 3 + 2 * 3 + 2
	printf("a = %d\n", a);
	getchar();
}


// 面试题4-看代码写输出--宏参数的连接
// # 是替换  ## 连接
#define STR(s) #s
#define CONS(a, b) (int)(a##e##b)
void testDefine3()
{
	printf(STR(vck));
	printf("\n");
	printf("%d\n", CONS(2, 3));
	printf("%d\n", 2e3);
	getchar();
}
//面试题5-=用宏定义得到一个子的高位和低位字节
#define WOLD_LO(xxx) ((byte)((word)(xxx)&255))
#define WOLD_HI(xxx) ((byte)((word)(xxx)>>8))

// 面试题6-用宏定义得到一个数组所含的元素个数
#define ARR_SIZE(a) (sizeof((a)) / sizeof((a[0])))



void testDefine5(){
	int a[10] = { 0 };
	char b[6] = {'a'};
	printf("%d\n", ARR_SIZE(a));
	printf("%d\n", ARR_SIZE(b));
	for (int i = 0; i < ARR_SIZE(b); i++) {
		printf("%d ", b[i]);
	}
	getchar();
}

// 面试题7-找错-const的使用
void testConst()
{
	const int x = 1;
	int b = 10;
	int c = 20;

	const int* a1 = &b;
	int * const a2 = &b;
	const int* const a3 = &b;

	// x = 2; //由于变量x为整型常量，因此不能改变x的值

	a1 = &c; //定义为const int* 类型, 用修饰指针所指向的变量,即指针指向为常量
	//*a1 = 1;

	//a2 = &c; //const在int*的右侧，它是用修饰指针本身，即指针本身不能修改
	*a2 = 1;

	//a3 = &c;
	//*a3 = 1;
}

// 面试题9 C++中const有什么作用
// 1.const用于定义常量：const定义的常量编译器可以对其进行数据静态类型安全检查
// 2.const修饰函数形式参数：当输入参数为用户自定义类型和抽象数据类型时，应该将”值传递“改为"const&传递"，可以提高效率
//      void fun(A a);
//      void fun(A const &a);
// 3.const修饰函数的返回值：如给”指针传递“的函数返回值加const，则返回值不能被直接修改，且该返回值只能被
//      赋值给加const修饰的同类型指针。例如：
//      const char *GetChar(void){};
//      char *ch = GetChar(); //error
//      const char *ch = GetChar();
// 4.const修饰类型的成员函数(函数定义体):任何不会修改数据成员的函数都应用const修饰，这样，当不小心修改了数据成员或调用了
//      非const成员函数时，编译器就会报错
//      int GetCount(void) const;
class TestConst
{
public:
	int GetCount(void) const {}
	int SetCount(void) const
	{
		//num = 2; //error
		//num2 = 2;//error
		GetCount();
		//SetCount2();//error
	}
	int SetCount2(void)
	{
		num = 2;
		//num2 = 2;//error
	}
private:
	int num = 0;
	const int num2 = 0;
};

void testTestConst()
{
	TestConst tc();

}

// 面试题10 static有什么作用
// 1 在函数体内，一个被声明为静态的变量在这一函数被调用的过程中维持其值不变
// 2 在模块内（但在函数体内），一个被声明为静态的变量可以被模块内所有函数访问，
//		但不能被模块外其他函数访问。它是一个本地的全局变量
// 3 在模块内，一个被声明为静态的函数只可被这一模块的其他函数调用。那就是这个函数被限制
//		在生命它的本地范围内使用

// 面试题11 static全局变量与普通的全局变量有什么区别
// 1. static全局变量与普通全局变量的区别是，static全局变量只初始化一次，防止在其他文件中被引用。
// 2. static局部变量与普通局部变量的区别是，static局部变量只被初始化一次，下一次依据上一次结果值
// 3. static函数与普通函数的区别是，static函数在内存中只有一份，普通函数在每个被调用中维持一份复制品

///面试题12 
#include<iostream>
class widget
{
public:
	widget()
	{
		count++;
	}
	~widget()
	{
		count--;
	}
	static int num()
	{
		return count;
	}
private:
	static int count;
};

int widget::count = 0;


void testWidget()
{
	widget x, y;
	std::cout << "The Num.is" << widget::num() << std::endl;
	if (widget::num() > 1)
	{
		widget x, y, z;
		std::cout << "The Num.is"<< widget::num() << std::endl;
	}
	widget z;
	std::cout << "The Num.is" << widget::num() << std::endl;
	getchar();
}

// 面试题13 使用sizeof计算普通变量所占空间大小
void PrintInt(char* str, int num)
{
	printf("%s -> %d\n", str, num);
}

void Func(char str[100])
{
	PrintInt("Func ", sizeof(str));
}
void test13()
{
	char str[] = "Hello";
	char *p = str;
	int n = 10;
	PrintInt("str", sizeof(str));
	PrintInt("p", sizeof(p));
	PrintInt("n", sizeof(n));
	char c[100] = { ' ' };
	Func(c);
	void *p2 = malloc(100);
	PrintInt("p", sizeof(p2));
	getchar();
}

class A
{
public:
	int i;
};

class B
{
public:
	char ch;
};

class C
{
public:
	int i; // 4
	short j; //2
};

class D
{
public:
	int i; //4
	short j;//2
	char ch;//1
};

class E
{
public:
	int i;     //4
	int ii;    //4
	short j;   //2
	char ch;   //1 
	char chr;  //1 
};

class F
{
public:
	int i;    //4
	int ii;   //4
	int iii;  //4
	short j;  //2
	char ch;  //1
	char chr; //1
};
void testSizeof()
{
	std::cout <<"sizeof(int)"<< sizeof(int) << std::endl;
	std::cout<< "sizeof(short)"<< sizeof(short) << std::endl;
	std::cout << "sizeof(char)"<<sizeof(char) << std::endl;
	std::cout << std::endl;
	std::cout << "" << std::endl;
	std::cout << "sizeof(A)" << sizeof(A) << std::endl;
	std::cout << "sizeof(B)" << sizeof(B) << std::endl;
	std::cout << "sizeof(C)" << sizeof(C) << std::endl;
	std::cout << "sizeof(D)" << sizeof(D) << std::endl;
	std::cout << "sizeof(E)" << sizeof(E) << std::endl;
	std::cout << "sizeof(F)" << sizeof(F) << std::endl;
	getchar();
}

class Base
{
public:
	Base(int x) :a(x)
	{

	}
	void print()
	{
		cout << "base" << endl;
	}
private:
	int a;
};

class Derived : public Base
{
public:
	Derived(int x) :Base(x - 1), b(x)
	{}
	void print()
	{
		cout << "derived" << endl;
	}
private:
	int b;
};

// 还有包括一个隐含的虚表指针成员，一共是8个字节
class AA
{
public:
	AA(int x) :a(x)
	{}
	virtual void print()
	{
		cout << "A" << endl;
	}
private:
	int a;
};

class BB :public AA
{
public:
	BB(int x) :AA(x - 1), b(x)
	{}
	virtual void print()
	{
		cout << "BB" << endl;
	}
private :
	int b;
};


void testSizeof2()
{
	Base obj1(1);
	cout << "size of Base obj is " << sizeof(obj1) << endl;
	Derived obj2(2);
	cout << "size of Derived obj is " << sizeof(obj2) << endl;

	AA a(1);
	cout << "size of A obj is " << sizeof(a) << endl;
	BB b(2);
	cout << "size of A obj is " << sizeof(b) << endl;
	getchar();
}


namespace c16 {
	class A {};
	class B {};
	class C :public A, public B {};
	class D :virtual public A {};
	class E :virtual public A, virtual public B {};
	class F 
	{
	public :
		int a;
		static int b;
	};
	int F::b = 10;
	static void testc16() {
		std::cout << "testc16" << std::endl;
		std::cout << "sizeof(A)"<< sizeof(A)<< endl;
		std::cout << "sizeof(B)" << sizeof(B) << endl;
		std::cout << "sizeof(C)" << sizeof(C) << endl;
		std::cout << "sizeof(D)" << sizeof(D) << endl;
		std::cout << "sizeof(E)" << sizeof(E) << endl;
		std::cout << "sizeof(F)" << sizeof(F) << endl;
		getchar();
	}
}

// 面试18 sizeof有哪些用途
// 1. 与存储分配和IO系统那样的例程进行通信。例如：
//			void* malloc(size_t size);
//			size_t fread(void* ptr, size_t size, size_t nmemb, FILE* stream);
// 2. 查看某个类型的对象在内存中所占的单元字节。例如,
//			void* memset(void*s, int c, sizeof(s));
// 3. 在动态分配一对象时，可以让系统知道要分配多少内存。
// 4. 便于一些类型的扩充，在Windows中很多结构类型就有一个专用的字段是用来放该类型的字节大小的
// 5. 用于操作数的字节数在实现时可能出现变化，建议在设计操作数字节大小时用sizeof来代替常量计算
// 6. 如果操作数时函数中的数组形参或函数类型的形参，则sizeof给出其指针的大小.

namespace c20 {
	union u
	{
		double a;
		int b;
	};
	union u2
	{
		char a[13];
		int b;
	};
	union u3
	{
		char a[13];
		char b;
	};

	void testUnion() {
		cout << sizeof(u) << endl;
		cout << sizeof(u2) << endl;
		cout << sizeof(u3) << endl;
	}
};

void testChapter2() 
{
	c20::testUnion();
	//c16::testc16();
	//testSizeof2();
	//testSizeof();
	//test13();
	//testWidget();
	//testConst();
	//testDefine5();
	//testDefine3();
	//testDefine2();
	//testDefine();
	//testIfdefEndIf();
	getchar();
}

int testIfdefEndIf()
{
	int i = 0;
	char c;
	while (1) {
		i++;
		c = getchar();
		if (c != '\n') {
			getchar();
		}
		if (c == 'q' || c == 'Q') {
#ifdef DEBUG
			printf("we got:%c, about to exit.\n", c);
#endif
			break;
		}
		else {
			printf("i = %d", i);
#ifdef DEBUG
			printf(", we got:%c", c);
#endif
			printf("\n");
		}
	}
	return 0;
}