#include <iostream>
#include <string>
using namespace std;
//string
//int main()
//{
//	string s1;
//	//开空间
//	s1.reserve(16);
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	cout << endl;
//	//开空间+填值初始化
//	s1.resize(100);
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//
//	return 0;
//}
int main()
{
	string url = "https://legacy.cplusplus.com/reference/string/string/insert/";
	size_t pos1 = url.find("://");
	string protocol;
	if (pos1 != string::npos)//npos为静态成员变量！所以可以使用string::npos来取
	{
		protocol = url.substr(0, )
	}
	return 0;
}