#pragma once
#include<iostream>
#include <string>
using namespace std;
class Person
{
public:
	Person(string name = " ", size_t age = 18, string id = "0000000000", string speciality = " ",int num = 10)
		:_Name(name)
		, _Age(age)
		, _Id(id)
		, _Speciality(speciality)
		, _num(num)
	{}
	void print_aeg()
	{
		cout << _Age << " ";
	}
	void print_naem()
	{
		cout << _Name << " ";
	}
	void num()
	{
		cout << _num << endl;
	}
//protected:
	string _Name;
	size_t _Age;
	string _Id;
	string _Speciality;
	int _num;

	
};
	/*派生类(子类)*//*继承方式*//*基类(父类)*/
class Student:public Person
{
public:
	Student(string college = "XXXXXXX", int dormitory = 0000, int num = 20)
		:_College(college)
		,_Dormitory(_Dormitory)
		,_num(num)
	{

	}
	void num()
	{
		cout << _num << endl;
	}
protected:
	string _College;
	int _Dormitory;
	int _num;
};
//基类和派生对象赋值转换
