#include <iostream>
using namespace std;
//函数模板
//T可以转换为所有类型包括自定义类型
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