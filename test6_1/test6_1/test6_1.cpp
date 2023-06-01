#include <iostream>
#include <string>
using namespace std;
/*
* string();				创建一个空字符串
* string(const char* s);使用字符串是来初始化
* string(const string& str);使用一个string对象初始化另外一个string对象
* string(int n,char c);		使用n个字符c初始化你
* string(const char* s, size_t n);  //复制s所指字符序列的前n个字符
* string(const string& str, size_t pos, size_t len = npos);  //复制str中从字
* 符位置pos开始并跨越len个字符的部分
*/
//string构造函数
//void test1()
//{
//	string s1;
//	const char* str= "hello world";
//	cout << "s1=" << str << endl;
//	string s2(str);
//	cout << "s2=" << s2 << endl;
//	string s3(str);
//	cout << "s3=" << s3 << endl;
//	string s4(10, 'z');
//	cout << "s4=" << s4 << endl;
//	string s5(s2, 0, 4);           //复制s2中从字符位置0开始并跨越4个字符的部分
//	cout << "s5=" << s5 << endl;
//	string s6("hello string", 3);  //复制"hello string"的前3个字符
//	cout << "s6=" << s6 << endl;
//}
//
//int main()
//{
//	test1();
//	return 0;
//}
/*
string& operator+=(const char* str); //重载+=操作符

string& operator+=(const char C);//重载+=操作符

string& operator+=(const string& str);//重载+=操作符

string& append(const char *s);//把字符串s连接到当前字符串结尾

string& append(const char *s， int n);//把字符串s的前n个字符连接到当前字符串结尾

string& append(const string &s);//同operator+=(const string& str)

string& append(const string &s，int pos, int n); //字符串s中从pos开始的n个字符连接到字符串结尾

*/

int main()
{

	return 0;
}