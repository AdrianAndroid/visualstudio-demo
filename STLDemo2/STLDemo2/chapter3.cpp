#include "chapter3.h"

#include <iostream>
#include <string>
using namespace std;

// ������1 һ�����ñ���������
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
		int* &pa = p; //����p��һ��ָ������pa��

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
	//���ô�ָ������ʵ���ַ��������ġ�����swap����ʱָ���������ͣ���˴��뺯���ľ���ʵ�Σ��������βΡ�
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
	// ������4 ��ν��������ַ���
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
		float f1(float = 5); //��������f1()��Ĭ�ϲ������ã���Ĭ�ϲ���ֵΪ5
		float& f2(float = 5); //��������f2()��Ĭ�ϲ������ã���Ĭ�ϲ���ֵΪ5
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

	//������6 �������õĳ�������
	void test6()
	{
		int a = 7;
		const int b = 10;
		//int &c = b; //����ʹ�ó������ͱ�������ǳ���������
		const int &d = a;

		int y = 1;
		int& x = a;
		cout << "x=" << x << endl;
		x = y;
		cout << "x=" << x << endl;


		a++;
		//d++; //����ʹ�ó��������޸ı�����ֵ

		Test test;
		test.f(a);
		cout << "a = " << a << endl;
	}

	//������7 ָ���������ʲô����
	// 1. ��ʼ��Ҫ��ͬ�������ڴ�����ͬʱ�����ʼ���������õ�һ����Ч�Ķ��󣻶�ָ���ڶ����ʱ��
	//		���س�ʼ���������ڶ��������κεط����¸�ֵ
	// 2.�����޸��Բ�ͬ������һ������ʼ��Ϊָ��һ���������Ͳ��ܱ��ı�Ϊ��һ����������ã�
	//		��ָ�����κ�ʱ�򶼿��Ըı�Ϊָ����һ�����󡣸����ø��Ʋ����Ǹı�����ԭʼ����İ󶨹�ϵ
	// 3.������NULL���ã����ò���ʹ��ָ���ֵ�����ã�����������ָ��ĳ�����󣻶�ָ���������NULL������Ҫ
	//		����ָ��ĳЩ���󣬿��԰�ָ��ָ������Ķ�������ָ�������Ҳ���׳���
	// 4.������Ҫ�������������ò���ָ���ֵ������ζ��ʹ������֮ǰ����Ҫ�������ĺϷ��ԣ���ָ������Ҫ
	//		�������в��ԡ����ʹ�����õĴ���Ч�ʱ�ʹ��ָ���Ҫ��
	// 5.Ӧ�õ����������ָһ��ָ��һ�������Ͳ���ı�ָ����ôӦ��ʹ�����á�����д���ָ��NULL
	//		����ָ���κζ����κζ��󣩻��ڲ�ͬ��ʱ��ָ��ͬ�Ķ�����Щ�����ԣ�Ӧ��ʹ��ָ��

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

	// ������15 ָ�볣���볣��ָ�������
	// ����ָ�룺����Ϊ���ǳ�����ָ�롱��������Ӧ����һ��ָ��
	// ָ�볣��������Ϊ����ָ��ĳ�������������Ӧ����һ������

	//���constλ��*�ŵ���࣬��const������������ָ����ָ��ı�������ָ��ָ��Ϊ������
	//���constλ��*�ŵ��Ҳ࣬const��������ָ�뱾����ָ�뱾����ǳ�����

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

	// ������37 �ڴ�ķ��䷽ʽ�м���
	// 1. �Ӿ�̬�洢������䡣�ڴ��ڳ�������ʱ����Ѿ�����ã�����ڴ��ڳ�������������ڼ�
	//		�����ڣ�����ȫ�ֱ�����
	// 2. ��ջ�Ϸ��䡣��ִ�к���ʱ�������ھֲ������Ĵ洢��Ԫ��������ջ�ϴ���������ִ�н���ʱ
	//		��Щ�洢��Ԫ�Զ����ͷš���������ָ����й���ջ�ڴ�ķ������㣬���Ч�ʺܸߣ�����
	//		������ڴ���������
	// 3. �Ӷ��Ϸ��䡣��ƶ�̬�ڴ���䡣���������е�ʱ����malloc��new���������ٵ��ڴ棬����Ա�Լ�����
	//		�ں�ʱ��free��delete�ͷ��ڴ档��̬�ڴ�������������Ǿ�����ʹ�÷ǳ���������Ҳ��ࡣ
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