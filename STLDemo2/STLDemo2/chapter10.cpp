#include "chapter10.h"
#include <iostream>
using namespace std;

namespace c10
{
	template <class T>
	T max(T a, T b)
	{
		return a > b ? a : b;
	}

	// 1.什么是函数模板和类模板
	// 2.函数模板和类模板有什么区别
	template <class T1, class T2>
	class Point_T
	{
	public:
		T1 a;
		T2 b;
		Point_T() :a(0), b(0) {}
		Point_T(T1 ta, T2 tb) : a(ta), b(tb) {}
		Point_T<T1, T2>& operator = (Point_T<T1, T2> &pt2);
		friend Point_T<T1, T2> operator +(Point_T<T1, T2> &pt1, Point_T<T1, T2> &pt2);
	};

	template<class T1, class T2>
	Point_T<T1, T2>& Point_T<T1, T2>::operator=(Point_T<T1, T2> &pt)
	{
		this->a = pt.a;
		this->b = pt.b;
		return *this;
	}


}

