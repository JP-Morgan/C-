#include <iostream>
#include <string>
using namespace std;
/*
* string();				����һ�����ַ���
* string(const char* s);ʹ���ַ���������ʼ��
* string(const string& str);ʹ��һ��string�����ʼ������һ��string����
* string(int n,char c);		ʹ��n���ַ�c��ʼ����
* string(const char* s, size_t n);  //����s��ָ�ַ����е�ǰn���ַ�
* string(const string& str, size_t pos, size_t len = npos);  //����str�д���
* ��λ��pos��ʼ����Խlen���ַ��Ĳ���
*/
//string���캯��
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
//	string s5(s2, 0, 4);           //����s2�д��ַ�λ��0��ʼ����Խ4���ַ��Ĳ���
//	cout << "s5=" << s5 << endl;
//	string s6("hello string", 3);  //����"hello string"��ǰ3���ַ�
//	cout << "s6=" << s6 << endl;
//}
//
//int main()
//{
//	test1();
//	return 0;
//}
/*
string& operator+=(const char* str); //����+=������

string& operator+=(const char C);//����+=������

string& operator+=(const string& str);//����+=������

string& append(const char *s);//���ַ���s���ӵ���ǰ�ַ�����β

string& append(const char *s�� int n);//���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β

string& append(const string &s);//ͬoperator+=(const string& str)

string& append(const string &s��int pos, int n); //�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β

*/

int main()
{

	return 0;
}