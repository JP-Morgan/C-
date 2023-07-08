#include <iostream>
#include <vector>
using namespace std;
void test()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	//三种循环方式
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
int main()
{
	test();
	return 0;
}