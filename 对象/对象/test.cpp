#include <iostream>
using namespace std;
////�꺯��  
//#define ADD(x,y) (((x)+(y))*10)
////�����������ɶ���ǿ��������ջ�����Ч�ʣ����Ե���
//inline int add(int x, int y)
//{
//	return x + y;
//}
////�����ڶ�С��Ƶ�����õĵĺ���
////Ĭ��debug�汾���޷�ʹ����������
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
//public://����
//
//
//private://˽��
//
//};
//
//
//int main()
//{
//	Stack a1;//c++��
//	struct Stack a2;//c����
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
