#include "chapter2.h"

// Ԥ����const��stati��sizeof
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//#define DEBUG

//define���ֵ����Сֵ
//�ں�����Ҫ�Ѳ���С�ĵ�����������������Ϊ��ֻ�Ǽ򵥵��ı��滻�������ע�⣬��������������
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


// ������4-������д���--�����������
// # ���滻  ## ����
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
//������5-=�ú궨��õ�һ���ӵĸ�λ�͵�λ�ֽ�
#define WOLD_LO(xxx) ((byte)((word)(xxx)&255))
#define WOLD_HI(xxx) ((byte)((word)(xxx)>>8))

// ������6-�ú궨��õ�һ������������Ԫ�ظ���
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

// ������7-�Ҵ�-const��ʹ��
void testConst()
{
	const int x = 1;
	int b = 10;
	int c = 20;

	const int* a1 = &b;
	int * const a2 = &b;
	const int* const a3 = &b;

	// x = 2; //���ڱ���xΪ���ͳ�������˲��ܸı�x��ֵ

	a1 = &c; //����Ϊconst int* ����, ������ָ����ָ��ı���,��ָ��ָ��Ϊ����
	//*a1 = 1;

	//a2 = &c; //const��int*���Ҳ࣬����������ָ�뱾����ָ�뱾�����޸�
	*a2 = 1;

	//a3 = &c;
	//*a3 = 1;
}

// ������9 C++��const��ʲô����
// 1.const���ڶ��峣����const����ĳ������������Զ���������ݾ�̬���Ͱ�ȫ���
// 2.const���κ�����ʽ���������������Ϊ�û��Զ������ͺͳ�����������ʱ��Ӧ�ý���ֵ���ݡ���Ϊ"const&����"���������Ч��
//      void fun(A a);
//      void fun(A const &a);
// 3.const���κ����ķ���ֵ�������ָ�봫�ݡ��ĺ�������ֵ��const���򷵻�ֵ���ܱ�ֱ���޸ģ��Ҹ÷���ֵֻ�ܱ�
//      ��ֵ����const���ε�ͬ����ָ�롣���磺
//      const char *GetChar(void){};
//      char *ch = GetChar(); //error
//      const char *ch = GetChar();
// 4.const�������͵ĳ�Ա����(����������):�κβ����޸����ݳ�Ա�ĺ�����Ӧ��const���Σ�����������С���޸������ݳ�Ա�������
//      ��const��Ա����ʱ���������ͻᱨ��
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

// ������10 static��ʲô����
// 1 �ں������ڣ�һ��������Ϊ��̬�ı�������һ���������õĹ�����ά����ֵ����
// 2 ��ģ���ڣ����ں������ڣ���һ��������Ϊ��̬�ı������Ա�ģ�������к������ʣ�
//		�����ܱ�ģ���������������ʡ�����һ�����ص�ȫ�ֱ���
// 3 ��ģ���ڣ�һ��������Ϊ��̬�ĺ���ֻ�ɱ���һģ��������������á��Ǿ����������������
//		���������ı��ط�Χ��ʹ��

// ������11 staticȫ�ֱ�������ͨ��ȫ�ֱ�����ʲô����
// 1. staticȫ�ֱ�������ͨȫ�ֱ����������ǣ�staticȫ�ֱ���ֻ��ʼ��һ�Σ���ֹ�������ļ��б����á�
// 2. static�ֲ���������ͨ�ֲ������������ǣ�static�ֲ�����ֻ����ʼ��һ�Σ���һ��������һ�ν��ֵ
// 3. static��������ͨ�����������ǣ�static�������ڴ���ֻ��һ�ݣ���ͨ������ÿ����������ά��һ�ݸ���Ʒ

///������12 
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

// ������13 ʹ��sizeof������ͨ������ռ�ռ��С
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

// ���а���һ�����������ָ���Ա��һ����8���ֽ�
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

// ����18 sizeof����Щ��;
// 1. ��洢�����IOϵͳ���������̽���ͨ�š����磺
//			void* malloc(size_t size);
//			size_t fread(void* ptr, size_t size, size_t nmemb, FILE* stream);
// 2. �鿴ĳ�����͵Ķ������ڴ�����ռ�ĵ�Ԫ�ֽڡ�����,
//			void* memset(void*s, int c, sizeof(s));
// 3. �ڶ�̬����һ����ʱ��������ϵͳ֪��Ҫ��������ڴ档
// 4. ����һЩ���͵����䣬��Windows�кܶ�ṹ���;���һ��ר�õ��ֶ��������Ÿ����͵��ֽڴ�С��
// 5. ���ڲ��������ֽ�����ʵ��ʱ���ܳ��ֱ仯����������Ʋ������ֽڴ�Сʱ��sizeof�����泣������
// 6. ���������ʱ�����е������βλ������͵��βΣ���sizeof������ָ��Ĵ�С.

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