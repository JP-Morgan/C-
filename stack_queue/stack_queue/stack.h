#pragma once
#include <iostream>
#include <list>
#include <vector>
namespace STack
{
	//ÈÝÆ÷ÊÊÅäÆ÷
	template<class T,class Container >
	class Stack
	{
	public:
		void Push(const T& x)
		{
			_con.push_back(x);
		}
		void Pop()
		{
			_con.pop_back();
		}
		T& top()
		{
			return _con.back();
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;

	};
}
void test_stack()
{
	STack::Stack<int, list<int>> st1;
	st1.Push(1);
	st1.Push(2);
	st1.Push(3);
	st1.Push(4);
	while (!st1.empty())
	{
		cout << st1.top() << " ";
		st1.Pop();
	}
	cout << endl;
	STack::Stack<int, vector<int>> st2;
	st2.Push(1);
	st2.Push(2);
	st2.Push(3);
	st2.Push(4);
	while (!st2.empty())
	{
		cout << st2.top() << " ";
		st2.Pop();
	}
}