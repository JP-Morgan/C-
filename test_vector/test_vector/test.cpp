#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void test()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	//����ѭ����ʽ
	//1
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	//2
	vector<int>::iterator it = v.begin();
	while (it!=v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//3
	for (auto e : v)
	{
		cout << e << " ";
	}
}
void test2()
{
	//vector�ĳ�ʼ��
	string s1("hello world");
	//��6�ĳ�ʼ��
	vector<char> vc(s1.begin(), s1.end());
	for (auto e:vc)
	{
		cout << e << " ";
	}
	cout << endl;
	int a[] = { 9,2,8,1 };
	vector<int> vi(a, a + 4);
	for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;
	//�㷨����
	//Ĭ��Ϊ����less<>
	sort(a, a + 4);
	for (auto e:a)
	{
		cout << e << " ";
	}
	cout << endl;
	//����
	//greater
	greater<int> gt;
	//sort(a, a + 4,gt);
	//��������
	sort(a, a + 4, greater<int>());
	for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	test2();
	return 0;
}