#include "Date.h"
Date::Date(int yaer, int month, int day)
{
	_yaer = yaer;
	_month = month;
	_day = day;
}

void Date::Print()
{
	cout << _yaer << "Äê"
		 << _month << "ÔÂ"
		 << _day << "ÈÕ" << endl;
}

bool Date::operator==(const Date& x)
{
	return _yaer == x._yaer
		&& _month == x._month
		&& _day == x._day;
}

bool Date::operator!=(const Date& x)
{
	return !(*this == x);
}

bool Date::operator<(const Date& x)
{
	if (_yaer < x._yaer)
	{
		return true;
	}
	else if (_yaer == x._yaer && _month < x._month)
	{
		return true;
	}
	else if (_yaer == x._yaer && _month == x._month && _day < x._day)
	{
		return true;
	}
	return false;
}

bool Date::operator<=(const Date& x)
{
	return *this < x || *this == x;
}

bool Date::operator>=(const Date& x)
{
	return !(*this < x);
}

bool Date::operator>(const Date& x)
{
	return !(*this <= x);
}

int Date::GetMonthDay(int yaer, int month)
{
	//static int DayArr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	//if (month !=2)
	//{
	//	return DayArr[month];
	//	
	//}
	//else if (((yaer % 4 == 0 && yaer % 100 == 0) || yaer % 400 == 0) && month == 2)
	//{
	//	return 29;
	//}
	static int DayArr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (((yaer % 4 == 0 && yaer % 100 == 0) || yaer % 400 == 0) && month == 2)
	{
		return 29;
	}
	else
	{
		return DayArr[month];
	}
}

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= day;
	}
	_day += day;
	while (_day > GetMonthDay(_yaer, _month))
	{
		int month = GetMonthDay(_yaer, _month);
		_day = _day - month;
		++_month;
		if (_month > 12)
		{
			++_yaer;
			_month = 1;
		}
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp += day;
	return tmp;
	/*Date tmp(*this);
	tmp._day += day;
	while (tmp._day > GetMonthDay(tmp._yaer, tmp._month))
	{
		int month = GetMonthDay(tmp._yaer, tmp._month);
		tmp._day = tmp._day - month;
		++tmp._month;
		if (tmp._month > 12)
		{
			++tmp._yaer;
			tmp._month = 1;
		}
	}
	return tmp;*/
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			_month = 12;
			--_yaer;
		}
		int MMonth=GetMonthDay(_yaer, _month);
		_day = _day + MMonth;
	}                                                                                                                                                                                                            
	return *this;
}

Date Date::operator-(int day)
{
	Date _Date = *this;
	_Date -= day;
	return _Date;
}
