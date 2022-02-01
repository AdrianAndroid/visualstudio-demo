// const_demo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>


using namespace std;

// 三、const参数传递和函数返回值
///////////////////////////////////////
//对于const修饰函数参数可以分为三种情况
///////////////////////////////////////
//A、值传递的const修饰传递，一般这种情况不需要const修饰，因为函数会自动产生临时变量复制实参值
void Cpf(const int a)
{
	cout << a;
	//++a; 是错误的，a不能被改变
}
//B、当const参数为指针时，可以防止指针被恶意篡改
void Cpf(int *const a)
{
	cout << *a << "";
	*a = 9;
	//a = (int *)9; // const修饰的指针不能被修改
}
//C、自定义类型的参数传递，需要临时对象复制参数，对于临时对象的构造，需要调用构造函数，因此我们采取const外加引用传递的方法
class Test
{
private:
	int _cm;
public:
	Test(){}
	Test(int _m):_cm(_m) {}
	int get_cm() const
	{
		return _cm;
	}
};
void Cmf(const Test& _tt)
{
	cout << _tt.get_cm();
}

///////////////////////////////////////
//对于const修饰函数的返回值
///////////////////////////////////////
// A：const修饰内置类型的返回值，修饰与不修饰返回值作用一样
const int Cmf2()
{
	return 1;
}
int Cpf2()
{
	return 0;
}
void main2(void)
{
	int _m = Cmf2();
	int _n = Cpf2();
	cout << _m << " " << _n;
}
// B: const修饰自定义类型的作为返回值，此时返回的值不能作为左值使用，既不能被赋值，也不能被修改
// C: const修饰返回的指针或者引用，是否返回一个指向const的指针，取决于我们想让用户干什么


// 四、const修饰成员函数
// 下面的get_cm()const函数用到了const成员函数
class Test2
{
private:
	int _cm;
public:
	Test2(){}
	Test2(int _m) :_cm(_m) {}
	int get_cm() const
	{
		return _cm;
	}
};
void Cmf3(const Test& _tt)
{
	cout << _tt.get_cm();
}

// 容易改变，被mutable关键字修斯和的成员可以处于不断变化中， 
class Test3
{
private:
	int _cm;
	mutable int _ct;
public:
	Test3(int _m, int _t) :_cm(_m), _ct(_t) {}
	void Kf() const
	{
		//++cm; //error
		++_ct; //ok
	}
};


int main()
{
	using namespace std;
	cout << "Hello world!" << endl;
	
	// const修饰指针变量有以下三种情况
	// A const修饰指针指向的内容，则内容为不可变量
	// B const修饰指针，则指针为不可变量
	// C const修饰指针和指针指向的内容，则指针和指针指向的内容都为不可变量

#ifdef DEBUG
	//const int *p = 8;
	int a = 8;
	int* const p = &a;
	*p = 9;
	int b = 7;
	p = &b;//error
	int a = 8;
	// const p 的指向的内容和指向的内存地址都已固定，不可改变
	// 左定值，右定向，const修饰不变量
	const int * const p = &a;
#endif // DEBUG

	cin.get();
    return 0;
}

