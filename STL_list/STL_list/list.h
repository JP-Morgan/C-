#pragma once
#include<iostream>
namespace List
{
	template<class T>//进行模版
	struct list_node//
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _val;
		//构造函数
		//构造函数使用了参数默认值 T()，这意味着如果在创建节点时没有提供参数，
		//则会使用 T 类型的默认构造函数来初始化 _val 成员变量。
		list_node(const T& val = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _val(val)
		{

		}
	};
	//迭代器
	template<class T>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		Node* _node;
		__list_iterator(Node* node)
			:_node(node)

		{}
		T& operator*()
		{
			return _node->_val;
		}
	};

	template<class T>//进行模版
	class list
	{
		typedef list_node<T> Node;//从新定义名字
	public:
		//构造函数
		list()
		{
			//产生了一个头节点
			_head = new _head;
			//前后头双向链接
			_head->_prev = _head;
			_head->_next = _head;
		}
		typedef __list_iterator<T> iterator;
		iterator begin()
		{
			return _head->_next;
		}
		iterator end()
		{
			return _head;
		}
		//尾插
		void push_back(const T& x)
		{
			Node* tail = _head->_prev;
			Node* newhead = new Node(x);

			
			tail ->_next = newhead;
			newhead->_prev = tail;

			newhead->_next = _head;
			_head->_prev = newhead;
			newhead->_val = x;

		}

	private:
		Node* _head;
	};
}
void test1()
{
	List::list<int> it;
	it.push_back(1);
	it.push_back(2);
	it.push_back(3);
	it.push_back(4);
	it.push_back(5);
	List::list<int>::iterator lt = it.begin();
	while (it != it.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}