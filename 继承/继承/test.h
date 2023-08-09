#pragma once
#include<iostream>
#include <string>
using namespace std;
class A
{
public:
	int _a;
};
class B : virtual public A
{
public:
	int _b;
};
class C : virtual public A
{
public:
	int _c;
}; 
class D :public C,public B
{
public:
	int _d;
};