#include <iostream>
#include <string>
using namespace std;
//int main()
//{
//
//    string s1;
//    string s2("张三");
//    string s3("hello world");
//    string s4(10,'*');
//    string s5(s2);
//    string s6(s3, 6, 5);
//    cout << s4 << endl;
//    cout << s6 << endl;
//    cout << s5 << endl;
//	return 0;
//}
int main()
{
	string A1("nihao");
	//插入一个字符
	A1.push_back(' ');
	//插入一个字符串
	A1.append("wolld");
	cout << A1 << endl;
	size_t x = 0;
	cin >> x;
	string xstr;
	while (x)
	{
		size_t val = x % 10;
		xstr += ('0' + val);
		x /= 10;
	}
	return 0;
}