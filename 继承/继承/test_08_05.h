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
	/*������(����)*//*�̳з�ʽ*//*����(����)*/	
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
		//���ڶ�̬��ԭ���������������⴦����
		// Ϊ��ͬһ�����destructor
		//Person::~Person();�����Զ��������Ӻ󸸵�����
	}
protected:
	string _position;
};

//�������������ֵת��
