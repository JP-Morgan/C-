#include <iostream>
using namespace std;

//int main()
//{
//    //c的玩法
//    int* b = (int*)malloc(sizeof(int));
//    free(b);
//
//    //多个
//    int* b = (int*)malloc(sizeof(int) * 10);
//    free(b);
//
//    //c++的玩法
//    int* a = new int;
//    delete a;
//
//    //多个
//    int* a = new int[10];//这里是开(申请)10个int的数组
//    delete[] a;
//
//    int* a = new int(10);//开(申请)一个int为初始化为10
//    delete a;
//
//    //数组的初始化
//    int* a = new int[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};//这里是开(申请)10个int的数组
//    delete[] a;
//    return 0;
//}

//class Date
//{
//public:
//	Date(int year)
//		:_year(year)
//	{
//		cout << "Date(int year)" << endl;
//	}
//	//explicit Date(int year)
//	//	:_year(year)
//	//{
//	//	cout << "Date(int year)" << endl;
//	//}
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//
//	}
//private:
//	int _year;
//};
////总结——若是想禁止单参数构造函数的隐式转换，可以用关键字explicit来修饰构造函数。
//int main()
//{
//	Date d1(2023);
//	Date d2 = 2023;
//	const Date& d3 = 2023;
//	return 0;
//}

//匿名函数
//class Date
//{
//public:
//	Date(int year)
//		:_year(year)
//	{
//
//	}
//private:
//	int _year;
//};
//
//int main()
//{
//	Date a1(2023);//匿名函数的生命周期只有一行，但把匿名函数拷贝给一个变量上可以延长生命周期
//	Date(2023);//
//	return 0;
//}


//static静态成员
//class A
//{
//public:
//	A()
//	{
//		++_sum;
//	}
//	A(const A& sum)
//	{
//		++_sum;
//	}
//	//静态成员函数没有this指针。不可以访问非静态成员
//	static int GitCont()
//	{
//		return _sum;
//	}
//
//private:
//	//声明
//	//静态成员变量，属于整个类，生命周期整个程序运行期间，存在静态区
//	static int _sum;
//};
//
//int A::_sum = 0;
//
//int main()
//{	
//
//	return 0;
//}


//只可以在栈定义类
class MyClass
{
public:
	//但是这种的没有办法使用那咋办呢？
	/*MyClass CreateObj()
	{
		MyClass so;
		return so;
	}*/

	//使用静态对象
	static MyClass CreateObj()
	{
		MyClass so;
		return so;
	}
private:
	MyClass(int x = 0, int y = 0)
		:_i(x)
		,_j(y)
	{

	}
private:
	int _i;
	int _j;
};

int main()
{
	MyClass A1 = MyClass::CreateObj();
	return 0;
}