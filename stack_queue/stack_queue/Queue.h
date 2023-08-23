#pragma once
#include <vector>
#include <list>
namespace Queue
{
	//容器适配器
	template<class T, class Container = vector<T>>
	class Queue
	{
	public:
		void Push(const T& x)
		{
			_con.push_back(x);
		}
		void Pop()
		{
			_con.pop_back();
			//_con.erase(_con.begin());
		}
		T& front()
		{
			return _con.front();
		}
		T& back()
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
void test_Queue()
{	//Queu不支持vector是头删浪费很大
	Queue::Queue<int, list<int>> st1;
	st1.Push(1);
	st1.Push(2);
	st1.Push(3);
	st1.Push(4);
	while (!st1.empty())
	{
		cout << st1.front() << " ";
		st1.Pop();
	}
}