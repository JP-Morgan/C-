#include <iostream>
using namespace std;
int main()
{
	// ʧ�ܷ���null
	char* A1 = (char*)malloc(1024u * 1024u * 1024u - 1);//1024u��uΪ�޷���
	//cout << A1 << endl;//ע��cout��Ҫ��ӡchar*
	printf("%p\n", A1);

	//newʧ�����쳣,����Ҫ��鷵��ֵ
	char* A2 = new char[1024u * 1024u * 1024u -1];
	printf("%p\n", A2);
	
	return 0;
}