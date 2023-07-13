#include <iostream>
using namespace std;
class Date
{
public:
	//拷贝构造
	Date(const Date& D)
	{
		_year = D._year;
		_month = D._month;
		_day = D._day;
	}

	//打印
	inline void print() const
	{
		cout << _year << " " << _month << " " << _day << endl;
	}

	//初始化
	Date(int year = 0, int month = 0, int day = 0)
		:_year(year)
		, _month(month)
		, _day(day)
	{
	}
private:
	int _year;
	int _month;
	int _day;
};

