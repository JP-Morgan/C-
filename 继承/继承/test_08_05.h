#pragma once
#include<iostream>
#include <string>
using namespace std;
class Person
{
public:
	Person(string name = " ", size_t age = 18, string id ="0000000000", string speciality = " ")
		:_Name(name)
		,_Age(age)
		,_Id(id)
		,_Speciality(speciality)
	{

	}
	void print_aeg()
	{
		cout << _Age << " ";
	}
	void print_naem()
	{
		cout << _Name << " ";
	}
protected:
	string _Name;
	size_t _Age;
	string _Id;
	string _Speciality;

	
};
	/*派生类(子类)*//*继承方式*//*基类(父类)*/
class Student:public Person
{
public:
	Student(string college = "XXXXXXX", int dormitory = 0000)
		:_College(college)
		,_Dormitory(_Dormitory)
	{

	}

protected:
	string _College;
	int _Dormitory;
};
