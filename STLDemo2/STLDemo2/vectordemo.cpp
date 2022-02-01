//template<class _Ty, class _A = allocator<_Ty>>
//class vector {
//	...
//};
#include "vectordemo.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <memory>

using namespace std;

void vectorCapcity2()
{
	vector<int> v;                //��ʼʱ��Ԫ�أ�����Ϊ0
	cout << v.capacity() << endl; //0
	v.push_back(1);               //��������������1��Ԫ���ڴ�
	cout << v.capacity() << endl; //1
	v.push_back(2);               //��������������2��Ԫ���ڴ�
	cout << v.capacity() << endl; //2
	v.push_back(3);               //��������������4��Ԫ���ڴ�
	cout << v.capacity() << endl; //3
	v.push_back(4);
	v.push_back(5);               //��������������8��Ԫ���ڴ�
	cout << v.capacity() << endl; //6
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);               //��������������16��Ԫ���ڴ�
	cout << v.capacity() << endl; //9
	//0
	//1
	//2
	//3
	//6
	//9
	// ��ô��Ԥ�ƵĽ����һ����?
}

void vectorIterator()
{
	vector<int> array;
	array.push_back(1);
	array.push_back(2);
	array.push_back(3);
	// �������array����
	for (vector<int>::size_type i = array.size() - 1; i >= 0; --i) {

		cout << i << "   " << endl;
	}
	cout << "===============" << endl;
	for (vector<int>::size_type j = array.size(); j > 0; j--) 
	{
		cout << array[j-1] << endl;
	}
}

// ���������
void vectorIterator2()
{
	typedef vector<int> IntArray;
	IntArray array;
	array.push_back(1);
	array.push_back(2);
	array.push_back(2);
	array.push_back(3);
	IntArray::iterator itor;
	for (itor = array.begin(); itor != array.end(); itor++) {
		if(2 == *itor)
		{
			array.erase(itor);
			//--itor;
		}
	}

	for (itor = array.begin(); itor != array.end(); ++itor) {
		cout << *itor << endl;
	}
}

// ��data�����е�����Ԫ�ؽ���ð������
void Order(vector<int>& data)
{
	int count = data.size(); //���vector�еĶ�Ԫ�ظ���
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (data[j] > data[j + 1]) //�����ǰԪ�ر���һ��Ԫ�ش��򽻻�
			{
				// ����
				int temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}

void vectorOrder() {
	vector<int> data;
	ifstream in("c:\\data.txt");
	if (!in)
	{
		cout << "infile error!" << endl;
		return;
	}
	int temp;
	while (!in.eof())
	{
		in >> temp;//���ļ���ȡ����
		data.push_back(temp); //�Ѷ�ȡ����������data������
	}
	in.close();
	Order(data);
	ofstream out("c:\\result.txt");
	if (!out) {
		cout << "outfile error!" << endl;
		return;
	}
	//for (int i = 0; i < data.size(); i++)
	//{
	//	out << data[i] << " ";//��data�����е�����Ԫ��������ļ�
	//}
	out.close();
	return;
}

/*
vector �������Ŀռ�
list ��һ������
*/
void vectorVectorAndList() 
{
	vector<int> v;
	list<int> l;
	//���Ԫ��
	for (int i = 0; i < 8; i++)
	{
		v.push_back(i);
		l.push_back(i);
	}
	cout << "v[2]" << v[2] << endl;
	//cout << "l[2]" << l[2] << endl; //�������listû������[]
	cout << (v.begin() < v.end()) << endl;
	//cout << (l.begin() < l.end()) << endl; //�������list:iterator û������<��>
	cout << *(v.begin() + 1) << endl;
	vector<int>::iterator itv = v.begin();
	list<int>::iterator itl = l.begin();
	itv = itv + 2;
	//itl = itl + 2;//�������list:iterator û������+
	itl++; itl++;//ֻ�ܽ��е�������
	cout << *itv << endl;
	cout << *itl << endl;
}

void  vectorList1()
{
	list<int> list1;
	for (int i = 0; i < 8; i++)
	{
		list1.push_back(i);
	}
	for (list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
	{
		if (*it % 2 == 0)
		{
			list1.erase(it);
			it--; //����������
		}
	}
	for (list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
	{
		cout << *it << endl;
	}
}

void testStackQueue() 
{
	stack<int, vector<int>> s;
	queue<int, vector<int>> q;
	for (int i = 1; i < 10; i++)
	{
		s.push(i);
		q.push(i);
	}
	
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
	cout << " == " << endl;

	/*while(!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}*/
}

void testSet()
{
	set<string> strset;
	set<string>::iterator si;
	strset.insert("cantaloupes");//����6��Ԫ�أ�����������grapes
	strset.insert("apple");
	strset.insert("orange");
	strset.insert("banana");
	strset.insert("grapes");
	strset.insert("grapes");
	strset.insert("banana");
	for (si = strset.begin(); si != strset.end(); si++)
	{
		cout << *si << " "; 
	}
	cout << endl;
}

void testMap()
{
	map<int, string> mapstring; //��λint���ͣ�ֵΪstring����
	mapstring.insert(pair<int, string>(1, "one"));
	mapstring.insert(pair<int, string>(4, "four"));
	mapstring.insert(pair<int, string>(3, "three"));
	mapstring.insert(pair<int, string>(2, "two"));
	mapstring.insert(pair<int, string>(4, "four*four")); //4�Ѿ����ڣ�����ʧ��
	
	mapstring[1] = "one*one";
	mapstring[5] = "five";
	cout << mapstring[1] << endl;

	mapstring.erase(2);
	map<int, string>::iterator f = mapstring.find(2);
	if (f != mapstring.end())
	{
		mapstring.erase(f);
	}

	map<int, string>::iterator it = mapstring.begin();
	while (it != mapstring.end())
	{
		cout << (*it).first << " " << (*it).second << endl;
		it++;
	}
}

void testAlgorithm()
{
	int a[4] = { 1,2,3,4 };
	vector<string> v;
	v.push_back("one");
	v.push_back("two");
	v.push_back("three");
	for (vector<string>::iterator itor = v.begin(); itor != v.end(); ++itor)
	{
		cout << *itor << endl;
	}
	cout << "=====" << endl;
	reverse<vector<string>::iterator>(v.begin(), v.end());
	for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " "; //���v��Ԫ��
	}
	cout << endl;
	reverse<int[4]>(a, a + 4);
	for (int i = 0; i < 4; i++)
	{
		cout << a[i] << " ";
	}
}

void print(int elem)
{
	cout << elem << " ";
}

void testAlgorithm2()
{
	deque<int> coll;
	for (int i = 1; i <= 9; ++i)
	{
		coll.push_back(i);
	}
	for (int i = 0; i < coll.size(); i++) {
		cout << coll[i] << " ";
	}
	cout << endl;
	deque<int>::iterator pos1; 
	pos1 = find(coll.begin(), coll.end(), 2);
	deque<int>::iterator pos2;
	pos2 = find(coll.begin(), coll.end(), 7);
	for_each(pos1, pos2, print);
	cout << endl;

	deque<int>::reverse_iterator rpos1(pos1);
	deque<int>::reverse_iterator rpos2(pos2);
	for_each(rpos2, rpos1, print);
	cout << endl;
}

template<class T>
void print3(vector<T> &a)
{
	// ��ӡ
	for (vector<T>::iterator it = a.begin(); it != a.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void testAlgorithm3()
{
	vector<int> array;

	array.push_back(1);
	array.push_back(2);
	array.push_back(3);
	array.push_back(3);
	array.push_back(4);
	array.push_back(5);

	print3(array);

	array.erase(array.begin()); //ɾ��1
	print3(array);
	vector<int>::iterator pos;
	pos = remove(array.begin(), array.end(), 2);
	print3(array);
	if ((pos + 1) == array.end())
	{
		cout << "(pos+1) == array.end()" << endl;
	}
	remove(array.begin(), array.end(), 3);
	print3(array);
	// 1.vector��erase������ɾ����Ԫ�أ������������ܷ�����
	// 2. ��algorithm�е�removeֻ�Ǽ򵥵ذ�ҩremove��Ԫ���Ƶ�����������棬���������ǿ��Է��ʵ��ġ�������Ϊalgorithm��ͨ����������������֪���������ڲ��ṹ�������޷���������ɾ��

}
class Test
{
public:
	Test() { name == NULL; }
	Test(const char* strname)
	{
		name = new char[strlen(strname) + 1];
		strcpy(name, strname);
	}
	Test& operator = (const char *namestr)
	{
		if (name != NULL)
		{
			delete name;
		}
		name = new char[strlen(namestr)+1];
		strcpy(name, namestr);
		return *this;
	}
	void showName() { cout << name << endl; }
	~Test()
	{
		if (name != NULL)
		{
			delete name;
		}
		cout << "delete name" << endl;
	}
public:
	char *name;
};

void stlTest()
{
	auto_ptr<Test> TestPtr(new Test("Terry"));
	//auto_ptr<Test> TestPtr = new Test("Terry");
	TestPtr->showName();
	*TestPtr = "David";
	TestPtr->showName();

	int y = 1;
	int x = 0;
	y = y / x;
}


void vectorTest()
{
	stlTest();
	//testAlgorithm3();
	//testAlgorithm2();
	//testAlgorithm();
	//testMap();
	//vectorCapcity2();
	//vectorIterator();
	//vectorIterator2(); // ���������
	//vectorOrder();
	//vectorVectorAndList();
	//vectorList1();
	//testStackQueue();
	//testSet();
}

