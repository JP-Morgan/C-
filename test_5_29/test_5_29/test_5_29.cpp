#include <iostream>
#include <string>
using namespace std;
//string
//int main()
//{
//	string s1;
//	//���ռ�
//	s1.reserve(16);
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	cout << endl;
//	//���ռ�+��ֵ��ʼ��
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
	if (pos1 != string::npos)//nposΪ��̬��Ա���������Կ���ʹ��string::npos��ȡ
	{
		protocol = url.substr(0, )
	}
	return 0;
}