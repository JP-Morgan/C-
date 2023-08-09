#pragma once
#include<iostream>
#include <string>
using namespace std;
class Person
{
public:
	Person(string name = " ", size_t age = 18, string id = "0000000000", string speciality = " ",int num = 10)
	/*Person(string name)*/
		: _Name(name)
		, _Age(age)
		, _Id(id)
		, _Speciality(speciality)
		, _num(num)
	{}
	void print_aeg()
	{
		cout << _Age << " ";
	}
	void num()
	{
		cout << _num << endl;
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
	int _num;

	
};
	/*派生类(子类)*//*继承方式*//*基类(父类)*/	
class Student:public Person
{
public:
	Student(string college = "XXXXXXX", int dormitory = 0000, int num = 20,string name = "zhang")
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
class teacher:public Person
{
public:
	teacher(string name = "zhang")
		: _position("xxxx") 
	{
	}
	teacher(const teacher& P)
		: Person(P)
		, _position(P._position)
	{

	}
	~teacher()
	{
		//由于多态的原因，析构函数被特殊处理了
		// 为了同一处理成destructor
		//Person::~Person();他会自动调用先子后父的析构
	}
protected:
	string _position;
};

//基类和派生对象赋值转换
