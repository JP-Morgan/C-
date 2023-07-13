#include <iostream>
using namespace std;
class Date
{
public:
	//��������
	Date(const Date& D)
	{
		_year = D._year;
		_month = D._month;
		_day = D._day;
	}

	//��ӡ
	inline void print() const
	{
		cout << _year << " " << _month << " " << _day << endl;
	}

	//��ʼ��
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

