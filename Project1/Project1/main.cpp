#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
#include<iterator>
#include<string>
#include<iterator>
using namespace std;

#include<iomanip>

#define _CRT_SECURE_NO_WARNINGS

/*function pointer*/
int max(int x, int y)
{
	return x > y ? x : y;
}
void populate_array(int *array, size_t arraySize, int(*getNextValue)(void));
void testsize();
void testmax();
void testcallbackfunc();
void testmacro();
void testUnsigned();
void testRandom();
void testStew();
void testTime();
void testVector();
void testArray();

int main(){
	//testsize();
	//testmax();
	//testcallbackfunc();
	//testmacro();
	//testUnsigned();
	//testRandom();
	//testStew();
	//testTime();
	//testVector();
	testArray();
	getchar();
	return 0;
}

void testArray(){
	array<int, 3> a1{ { 1, 2, 3 } };
	array<int, 3> a2 = { 1, 2, 3 };
	array<string, 2> a3 = { string("a"), "b" };

	//sort(a1.begin(), a2.begin());
	//reverse_copy(a2.begin(), a2.end(), ostream_iterator<int>(cout, " "));
	cout << '\n';
	for (const auto& s : a3)
		cout << s << ' ';

	array<float, 3> a4 = {3.0, 1.0, 4.0};
}

void testVector()
{
	vector<int> a;
	for (int i = 0; i < 10; i++)
		a.push_back(i);
	a.resize(100);
	a[90] = 100;
	//a.clear();
	//a.resize(20, -1);
	cout << &a << endl;
	vector<int>::iterator itor;
	for (itor = a.begin(); itor != a.end(); itor++)
	{
		std::cout << *itor << " ";
	}
		
}

void testTime()
{
	time_t now = time(0);
	char* dt = ctime(&now);
	cout << "local time" << dt << endl;
	tm *gmtm = gmtime(&now);
	dt = asctime(gmtm);
	cout << "UTC " << dt << endl;
}

void testStew()
{
	int n[10];
	for (int i = 0; i < 10; i++){
		n[i] = i + 100;
	}
	cout << "Eelement" << setw(13) << "Value" << endl;
	for (int j = 0; j < 10; j++)
	{
		cout << setw(7) << j << setw(13) << n[j] << endl;
	}
}


void testRandom()
{
	int i, j;
	srand((unsigned)time(NULL));
	for (i = 0; i < 10; i++)
	{
		j = rand();
		cout << j << endl;
	}
}


void testUnsigned()
{
	short int i;
	short unsigned int j;
	j = 50000;
	i = j;
	printf("%d,%d", i, j);
}

void testmacro()
{
	printf("%s\n", __FILE__);
	printf("%s\n", __DATE__);
	printf("%s\n", __TIME__);
	printf("%d\n", __LINE__);
	//printf("%s\n", __STDC_SECURE_LIB__);
}

int getNextRandomValue(void)
{
	return rand();
}

void testcallbackfunc()
{
	int myarray[10];
	populate_array(myarray, 10, getNextRandomValue);
	for (int i = 0; i < 10; i++){
		printf("%d ", myarray[i]);
	}
	printf("\n");
}


void populate_array(int *array, size_t arraySize, int(*getNextValue)(void))
{
	for (size_t i = 0; i < arraySize; i++)
	{
		array[i] = getNextValue();
	}
}

void testmax()
{
	// p is a function pointer
	int(*p)(int, int) = &max;
	int a, b, c, d;
	printf("please input three numbers:");
	scanf_s("%d %d %d", &a, &b, &c);
	d = p(p(a,b), c);
	printf("\n%d\n", d);
	getchar();
}

enum DAY
{
	MON = 1,TUE
};
enum DAY day;

void testsize(){
	int a = 4;
	short b;
	double c;
	int* ptr;

	/*sizeof meta-operator example*/
	printf("sizeof(a) = %lu\n", sizeof(a));
	printf("sizeof(a) = %lu\n", sizeof(b));
	printf("sizeof(a) = %lu\n", sizeof(c));
}



