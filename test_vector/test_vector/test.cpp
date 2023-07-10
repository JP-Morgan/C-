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
void test2()
{
	//vector的初始化
	string s1("hello world");
	//贼6的初始化
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
	//算法排序
	//默认为升序less<>
	sort(a, a + 4);
	for (auto e:a)
	{
		cout << e << " ";
	}
	cout << endl;
	//降序
	//greater
	greater<int> gt;
	//sort(a, a + 4,gt);
	//匿名对象
	sort(a, a + 4, greater<int>());
	for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;
	vector<int> v1 = {1,3,4,5,87,7,6,5,0};
	sort(v1.rbegin(), v1.rend());
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

}
void test3()
{
	//正确的使用方法
	vector<int> v1;
	v1.reserve(10);
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	//错误的使用
	/*vector<int> v1;
	v1.reserve(10);
	for (size_t i = 0; i < 10; i++)
	{
		v1[i]=i;
	}*/
	//或者可以这样使用
	vector<int> v2;
	v2.resize(10);
	for (size_t i = 0; i < 10; i++)
	{
		v2[i]=i;
	}
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;
	//头删
	v2.erase(v2.begin()+2);
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;
	//头插
	v2.insert(v2.begin(), 99);
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;
}
void test4()
{
	class Solution {
		int singleNumber(vector<int>& nums) {
			int singleIndex = 0;
			for (int v : nums)
			{
				singleIndex ^= v;
			}
			return singleIndex;
		}
		
		
	};
	vector<int> a = { 1,2,3,1,2,3,4 };
	int singleNumber(vector<int> a);
}
int main()
{
	test4();
	return 0;
}