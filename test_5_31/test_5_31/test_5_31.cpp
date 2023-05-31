#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//void myPrintf(int val)
//{
//	cout << val << endl;
//}
//容器：vector
//void test1()
//{
	//创建一个vector容器，数组
	//vector<int> v;
	//向容器中插入数据
	//v.push_back(10);
	//v.push_back(20);
	//v.push_back(30);
	//v.push_back(40);
	//通过迭代器访问容器中的数据
	//vector<int>::iterator itBegin = v.begin();
	//vector<int>::iterator itEnd = v.end();
	//遍历方式1
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}
	//遍历方式2
	//for (auto it = itBegin; it != itEnd; it++)
	//{
	//	cout << *it << endl;
	//}
	//遍历方式3 利用STL遍历算法！
//	for_each(v.begin(), v.end(), myPrintf);	//遍历方式4
//
//}
//int main()
//{
//	test1();
//	return 0;
//}




//自定义类——容器
//class Person
//{
//public:
//	Person(string Name = "0", int Age = 0)
//		:_Name(Name)
//		,_Age(Age)
//	{
//	}
//	void Print()
//	{
//		cout << _Name << endl;
//		cout << _Age << endl;
//	}
////private:
//	string _Name;
//	int _Age;
//};
//void test1()
//{
//	vector<Person> v;
//
//	Person p1("小米", 10);
//	Person p2("小黄", 10);
//	Person p3("小百", 10);
//	Person p4("小基", 10);
//	Person p5("小卡", 10);
//	//向容器中添加数据
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	v.push_back(p5);
//	//遍历数据
//	auto itBgin = v.begin();
//	auto itEnd = v.end();
//	while (itBgin != itEnd)
//	{
//		cout << ((*itBgin)._Name) << endl;
//		cout << ((*itBgin)._Age) << endl;
//		itBgin++;
//	}
//}
//void test2()
//{
//	//指针类型！
//	vector<Person*> v;
//
//	Person p1("小米", 10);
//	Person p2("小黄", 10);
//	Person p3("小百", 10);
//	Person p4("小基", 10);
//	Person p5("小卡", 10);
//	//向容器中添加数据
//	v.push_back(&p1);
//	v.push_back(&p2);
//	v.push_back(&p3);
//	v.push_back(&p4);
//	v.push_back(&p5);
//	//遍历数据
//	auto itBgin = v.begin();
//	auto itEnd = v.end();
//	while (itBgin != itEnd)
//	{
//		cout << ((**itBgin)._Name) << endl;
//		cout << ((**itBgin)._Age) << endl;
//		itBgin++;
//	}
//}
//int main()
//{
//	test2();
//	return 0;
//}



//容器嵌套容器！
int main()
{
	//大容器
	vector<vector<int>> v;
	//创建小容器
	vector<int> e1;
	vector<int> e2;
	vector<int> e3;
	vector<int> e4;
	vector<int> e5;
	//向小容器中添加数据！
	for (int i = 0; i < 10; i++)
	{
		e1.push_back(i + 1);
		e2.push_back(i + 2);
		e3.push_back(i + 3);
		e4.push_back(i + 4);
		e5.push_back(i + 5);
	}
	//将小容器存放在大容器中
	v.push_back(e1);
	v.push_back(e2);
	v.push_back(e3);
	v.push_back(e4);
	v.push_back(e5);
	//通过大容器遍历小容器
	for (auto it = v.begin(); it != v.end(); it++)
	{
		for (auto itt = (*it).begin(); itt != (*it).end(); itt++)
		{
			cout << *itt << " ";
			
		}
		cout << endl;
	}
	//	}
	//}
	//auto itBgin = v.begin();
	//auto itEnd = v.end();
	//while (itBgin != itEnd)
	//{
	//	auto Bgin = (*itBgin).begin();
	//	auto End = (*itEnd).end();
	//	while (Bgin != End)
	//	{
	//		cout << *Bgin << endl;
	//	}
	//	itBgin++;
	//}

	return 0;
}