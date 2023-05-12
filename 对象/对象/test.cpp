#include <iostream>
using namespace std;
////宏函数  
//#define ADD(x,y) (((x)+(y))*10)
////内联函数：可读性强，不建立栈，提高效率，可以调试
//inline int add(int x, int y)
//{
//	return x + y;
//}
////适用于短小的频繁调用的的函数
////默认debug版本下无法使用内联函数
//int main()
//{
//
//	return 0;
//}
//
//struct Stack
//{
//	int add(int a) 
//	{
//		return a+10;
//	}
//	int a;
//};
//
//class CLASS
//{
//public://公共
//
//
//private://私有
//
//};
//
//
//int main()
//{
//	Stack a1;//c++版
//	struct Stack a2;//c兼容
//	return 0;
//}

class add
{
public:
	add(int sum = 0)
	{
		_add = nullptr;
		_siz = nullptr;
		_sum = sum;
	}
private:
	int* _add;
	int* _siz;
	int _sum;
};

int main()
{
	add q(4);
	return 0;
}
