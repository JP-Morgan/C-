//友元
/*
* 突破访问限定符的限制
*/
#include <iostream>
using namespace std;
//class Time
//{
//	// 声明日期类为时间类的友元类，则在日期类中就直接访问Time
//	friend class Date; 
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// 直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//int main()
//{
//	
//	return 0;
//}





//内部类
/*
* 在类里面创建一个类
* 内部类为两种
* 1.共有内部类
* 2.私有内部类
*/
//class A
//{
//public:
//	//内部类是外部类的友元
//	class B
//	{
//	public:
//		void fn()
//		{
//
//		}
//	private:
//		int a;
//
//	};
//	void aaaa(int a)
//	{
//		_h = a;
//	}
//private:
//	int _h;
//	static int k;//不在类里面所以不用计算大小
//
//};
//int A::k = 1;
//int main()
//{
//	cout << sizeof(A) << endl;
//	A::B a;
//	a.fn();
//	
//	
//	return 0;
//}