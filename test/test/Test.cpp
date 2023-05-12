/*
* 初始化列表
* 每一个成员变量在初始化列表中只可以初始化一次
* 引用成员变量
* const成员变量
* 自定义类型成员(并且没有默认构造的函数)
*/
#include <iostream>
using namespace std;
class AAA
{
public:
	AAA(int a)
		:_A(a)
	{}
private:
	int _A;
};

class MyClass
{
public:
	//初始化列表：对象的成员定义的位置
	MyClass(int a, int ref)
		:_asd(a)
		, _ref(ref)
		, _n(10)
	{}
private:
	//是声明的地方
	AAA _asd;//默认构造（只要不传值的都是默认构造）

	//特征:必须是在定义时初始化(引用与const)
	int& _ref;//引用
	const int _n;//const
	int x = 10;//这里表示的是缺省
};
int main()
{
	//对象整体定义的地方
	MyClass a(10, 20);
	return 0;
}