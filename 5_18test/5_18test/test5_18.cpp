#include <iostream>
using namespace std;

//友元
/*
* 友元不具备有传递性
* A是B的友元B是C的友元，不能表示A是B的友元
* 总结 你的是我的我的还是我的
*/
//class MyClass1
//{
//	friend class MyClass2;
//public:
//	MyClass1(int time = 1)
//		:_time(time)
//	{
//
//	}
//private:
//	int _time;
//
//};
//class MyClass2
//{
//public:
//	MyClass2(int year = 0, int month = 0,int day = 0)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	void Git(int time = 10)
//	{
//		_t._time = time;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	MyClass1 _t;
//};
//int main()
//{
//
//	return 0;
//}


//内部类
/*
* 内部类是外部类的友元：解释内部的可以调外部的私有但外部的不可以调内部的
*
*/
//class outside
//{
//public:
//	//inside在outside的里面
//	//1.受A的类域限制，访问限定符
//	//2.inside是outside的友元
//	class inside
//	{
//	public:
//		inside(int x = 10, int y = 10, int z = 10)
//			: _q(x)
//			, _w(y)
//			, _e(z)
//			, _zzz(x)
//		{
//		}
//		void Git()
//		{
//			cout << _zzz._x << _zzz._y << _zzz._z << endl;
//		}
//	private:
//		int _q;
//		int _w;
//		int _e;
//		const outside& _zzz;
//
//	};
//public:
//	outside(int x = 0, int y = 0, int z = 0)
//		: _x(x)
//		, _y(y)
//		, _z(z)
//	{
//
//	}
//private:
//	int _x;
//	int _y;
//	int _z;
//};
//int main()
//{
//	outside::inside a;
//	a.Git();
//	return 0;
//}


class A
{
public:
	A(int a = 0)//构造函数
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)//拷贝构造
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}
		A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a = aa._a;
		}
		return *this;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

void f1(A a)
{

}

void f2(const A& a)
{

}

A f3()
{
	A ret;
	return ret;
}
//void test1()
//{
//	A a1;
//	f1(a1);
//	f2(a1);
//	cout << endl << endl;
//	f1(A());
//
//	cout << endl << endl;
//}


A f(A a)
{
	A v(a);
	A w = a;
	return w;
}
int main()
{

	A x;
	A y = f(f(x));
	cout << endl << endl;

	A ww;
	ww = f3();//一次拷贝 一次构造 一次赋值

//	test1();
	//f3();
	//cout << endl << endl;
	//A a1 = f3();

	return 0;
}