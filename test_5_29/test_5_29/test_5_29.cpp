#include <iostream>
#include <string>
using namespace std;
//string
int main()
{
	string s1;
	//���ռ�
	s1.reserve(16);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << endl;
	//���ռ�+��ֵ��ʼ��
	s1.resize(100);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	return 0;
}