/*
* 知识点：
* 用已经存在的对象初始化另一个对象--构造函数
* 已经经存在的两个对象互相拷贝--运算符重载函数 
*/
#include <iostream>
using namespace std;
class Date
{
public:
	Date(int yaer = 1, int month = 1, int day = 1);
	void Print();

	bool operator<(const Date& x);
	bool operator>(const Date& x);
	bool operator==(const Date& x);
	bool operator!=(const Date& x);
	bool operator<=(const Date& x);
	bool operator>=(const Date& x);

	int GetMonthDay(int yaer, int month);
	Date& operator+=(int day);
	Date operator+(int day);
	Date& operator-=(int day);
	Date operator-(int day);
private:
	int _yaer;
	int _month;
	int _day;
};