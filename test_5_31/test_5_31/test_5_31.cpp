#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//void myPrintf(int val)
//{
//	cout << val << endl;
//}
//������vector
//void test1()
//{
	//����һ��vector����������
	//vector<int> v;
	//�������в�������
	//v.push_back(10);
	//v.push_back(20);
	//v.push_back(30);
	//v.push_back(40);
	//ͨ�����������������е�����
	//vector<int>::iterator itBegin = v.begin();
	//vector<int>::iterator itEnd = v.end();
	//������ʽ1
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}
	//������ʽ2
	//for (auto it = itBegin; it != itEnd; it++)
	//{
	//	cout << *it << endl;
	//}
	//������ʽ3 ����STL�����㷨��
//	for_each(v.begin(), v.end(), myPrintf);	//������ʽ4
//
//}
//int main()
//{
//	test1();
//	return 0;
//}




//�Զ����ࡪ������
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
//	Person p1("С��", 10);
//	Person p2("С��", 10);
//	Person p3("С��", 10);
//	Person p4("С��", 10);
//	Person p5("С��", 10);
//	//���������������
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	v.push_back(p5);
//	//��������
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
//	//ָ�����ͣ�
//	vector<Person*> v;
//
//	Person p1("С��", 10);
//	Person p2("С��", 10);
//	Person p3("С��", 10);
//	Person p4("С��", 10);
//	Person p5("С��", 10);
//	//���������������
//	v.push_back(&p1);
//	v.push_back(&p2);
//	v.push_back(&p3);
//	v.push_back(&p4);
//	v.push_back(&p5);
//	//��������
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



//����Ƕ��������
int main()
{
	//������
	vector<vector<int>> v;
	//����С����
	vector<int> e1;
	vector<int> e2;
	vector<int> e3;
	vector<int> e4;
	vector<int> e5;
	//��С������������ݣ�
	for (int i = 0; i < 10; i++)
	{
		e1.push_back(i + 1);
		e2.push_back(i + 2);
		e3.push_back(i + 3);
		e4.push_back(i + 4);
		e5.push_back(i + 5);
	}
	//��С��������ڴ�������
	v.push_back(e1);
	v.push_back(e2);
	v.push_back(e3);
	v.push_back(e4);
	v.push_back(e5);
	//ͨ������������С����
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