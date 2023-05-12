/*
* ֪ʶ�㣺
* ���Ѿ����ڵĶ����ʼ����һ������--���캯��
* �Ѿ������ڵ����������࿽��--��������غ��� 
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