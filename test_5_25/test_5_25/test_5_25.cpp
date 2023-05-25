#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;
//int main()
//{
	//string a1("dididididididididi");
	// char ch[] = "qwerqwerqwer";
	// ch[1]++;//*(ch+1);
	// a1[1]++;//a1.operator[](1);
	//cout << a1 << endl;
	//for (size_t i = 0; i < a1.size(); i++)
	//{
	//	a1[i]++;
	//}
	//cout << endl;
	////迭代器(像指针)
	//string::iterator it = a1.begin();
	//while (it != a1.end())
	//{
	//	(*it)++;
	//	it++;
	//}
	//it = a1.begin();
	//while (it != a1.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//for (auto ch : a1)
	//{
	//	cout << ch << " ";
	//}
	//cout << endl;
	//任何容器都支持迭代器，并且用发是类似的
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	vector<int>::iterator vit = v.begin();
//	while (vit != v.end())
//	{
//		cout << *vit << " ";
//		++vit;
//	}
//	cout << endl;
//
//	list<int> it;
//	it.push_back(1);
//	it.push_back(2);
//	it.push_back(3);
//	it.push_back(4);
//	 list<int>::iterator lit = it.begin();
//	 while (lit != it.end())
//	 {
//		 cout << *lit << " ";
//		 lit++;
//	 }
//	 cout << endl;
//
//	 //reverse函数模版
//	 reverse(v.begin(), v.end());
//	 reverse(it.begin(), it.end());
//	 for (auto ch :v)
//	 {
//		 cout << ch << " ";
//	 }
//	 cout << endl;
//	 for (auto ch : v)
//	 {
//		 cout << ch << " ";
//	 }
//	
//	return 0;
//}
void Fan(const string& s)
{
	string::const_iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	//string::const_reverse_iterator rit = s.rbegin();
	auto rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}
//int main()
//{
//	string s1("hello world");
//	//string::reverse_iterator rit = s1.rbegin();
//	auto rit = s1.rbegin();
//	while (rit != s1.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//	Fan(s1);
//	return 0;
//}
int main()
{
	string s1("hello world");
	cout << s1.size() << endl;//数据长度
	cout << s1.length() << endl;//数据个数
	cout << s1.max_size() << endl;//毫无意义
	size_t old = s1.capacity();
	for (size_t i = 0; i < 100; i++)
	{
		s1 += "i";
		if (old != s1.capacity())
		{
			cout << "扩容：" << s1.capacity() << endl;
			old = s1.capacity();
		}
	}

	cout << s1.capacity() << endl;
	cout << s1.size() << endl;
	s1.clear();

	cout << s1.capacity() << endl;
	cout << s1.size() << endl;                 
}