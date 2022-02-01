// const_demo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>


using namespace std;

// ����const�������ݺͺ�������ֵ
///////////////////////////////////////
//����const���κ����������Է�Ϊ�������
///////////////////////////////////////
//A��ֵ���ݵ�const���δ��ݣ�һ�������������Ҫconst���Σ���Ϊ�������Զ�������ʱ��������ʵ��ֵ
void Cpf(const int a)
{
	cout << a;
	//++a; �Ǵ���ģ�a���ܱ��ı�
}
//B����const����Ϊָ��ʱ�����Է�ָֹ�뱻����۸�
void Cpf(int *const a)
{
	cout << *a << "";
	*a = 9;
	//a = (int *)9; // const���ε�ָ�벻�ܱ��޸�
}
//C���Զ������͵Ĳ������ݣ���Ҫ��ʱ�����Ʋ�����������ʱ����Ĺ��죬��Ҫ���ù��캯����������ǲ�ȡconst������ô��ݵķ���
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
//����const���κ����ķ���ֵ
///////////////////////////////////////
// A��const�����������͵ķ���ֵ�������벻���η���ֵ����һ��
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
// B: const�����Զ������͵���Ϊ����ֵ����ʱ���ص�ֵ������Ϊ��ֵʹ�ã��Ȳ��ܱ���ֵ��Ҳ���ܱ��޸�
// C: const���η��ص�ָ��������ã��Ƿ񷵻�һ��ָ��const��ָ�룬ȡ�������������û���ʲô


// �ġ�const���γ�Ա����
// �����get_cm()const�����õ���const��Ա����
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

// ���׸ı䣬��mutable�ؼ�����˹�͵ĳ�Ա���Դ��ڲ��ϱ仯�У� 
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
	
	// const����ָ������������������
	// A const����ָ��ָ������ݣ�������Ϊ���ɱ���
	// B const����ָ�룬��ָ��Ϊ���ɱ���
	// C const����ָ���ָ��ָ������ݣ���ָ���ָ��ָ������ݶ�Ϊ���ɱ���

#ifdef DEBUG
	//const int *p = 8;
	int a = 8;
	int* const p = &a;
	*p = 9;
	int b = 7;
	p = &b;//error
	int a = 8;
	// const p ��ָ������ݺ�ָ����ڴ��ַ���ѹ̶������ɸı�
	// ��ֵ���Ҷ���const���β�����
	const int * const p = &a;
#endif // DEBUG

	cin.get();
    return 0;
}

