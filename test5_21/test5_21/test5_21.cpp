#include <iostream>
using namespace std;
//����ģ��
//T����ת��Ϊ�������Ͱ����Զ�������
template <typename T>
void Swap(T& x1,T& x2)
{
	T tmp = x1;
	x1 = x2;
	x2 = tmp;
}
int main()
{
	int a = 0, b = 10;
	double c = 1.1, d = 9.9;
	Swap(a, b);
	Swap(c, d);
	return 0;
}