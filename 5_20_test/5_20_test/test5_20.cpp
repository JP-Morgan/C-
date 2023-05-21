#include <iostream>
using namespace std;
int main()
{
	// 失败返回null
	char* A1 = (char*)malloc(1024u * 1024u * 1024u - 1);//1024u加u为无符号
	//cout << A1 << endl;//注意cout不要打印char*
	printf("%p\n", A1);

	//new失败抛异常,不需要检查返回值
	char* A2 = new char[1024u * 1024u * 1024u -1];
	printf("%p\n", A2);
	
	return 0;
}