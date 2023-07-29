#pragma once
#include<iostream>
namespace List
{
	template<class T>//进行模版
	struct list_node//
	{
		list_node<T>* _next;//T任意类型指针
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
	//常量迭代器
	//template<class T>
	//struct __list_const_iterator
	//{
	//	typedef list_node<T> Node;
	//	Node* _node;
	//	//运用一个节点构造一个迭代器为啥？——因为我们可以用一个地址来改变迭代器底层的玩法，不在是像string和vector一样的
	//	__list_iterator(Node* node)
	//		:_node(node){}
	//	const T& operator*()//这里的T为
	//	{
	//		return _node->_val;
	//	}
	//	//预递增运算符(++)的返回类型
	//	//必须为相同的迭代器类型
	//	//（ __list_iterator<T>&） 以遵循 C++ 中预增量运算符的约定。
	//	//前置++
	//	__list_iterator<T>& operator++()
	//	{
	//		 _node = _node->_next;
	//		 return *this;
	//	}
	//	//后递增运算符 （ operator++(int)）：
	//	//后递增运算符返回当前值，然后递增该值。它通常重载一个虚拟参数（通常称为  int 或任何其他合适的名称），以将其与前递增运算符区分开来。
	//	//参数的值不会在函数体中使用，但它的存在有助于编译器确定正在使用哪个运算符。
	//	//后置++
	//	__list_iterator<T> operator++(int)
	//	{
	//		__list_iterator<T> tmp(*this);
	//		_node = _node->_next;
	//		return tmp;
	//	}
	//	
	//	bool operator!=(const/*end返回有常性*/ __list_iterator<T>& it)
	//	{
	//		return _node != it._node;
	//	}
	//	bool operator==(const/*end返回有常性*/ __list_iterator<T>& it)
	//	{
	//		return _node == it._node;
	//	}
	//};
	
	//迭代器
	template<class T,class Ref>
	struct __list_iterator
	{
		
		typedef __list_iterator<T, Ref> self;
		typedef list_node<T> Node;
		Node* _node;
		//运用一个节点构造一个迭代器为啥？——因为我们可以用一个地址来改变迭代器底层的玩法，不在是像string和vector一样的
		__list_iterator(Node* node)
			:_node(node) {}
		Ref operator*()//这里的T为
		{
			return _node->_val;
		}
		//预递增运算符(++)的返回类型
		//必须为相同的迭代器类型
		//（ __list_iterator<T>&） 以遵循 C++ 中预增量运算符的约定。
		//前置++
		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		//后递增运算符 （ operator++(int)）：
		//后递增运算符返回当前值，然后递增该值。它通常重载一个虚拟参数（通常称为  int 或任何其他合适的名称），以将其与前递增运算符区分开来。
		//参数的值不会在函数体中使用，但它的存在有助于编译器确定正在使用哪个运算符。
		//后置++
		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		bool operator!=(const/*end返回有常性*/  self& it)
		{
			return _node != it._node;
		}
		bool operator==(const/*end返回有常性*/  self& it)
		{
			return _node == it._node;
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
			_head = new Node;
			//前后头双向链接
			_head->_prev = _head;
			_head->_next = _head;
		}
		typedef __list_iterator<T, T&> iterator;//这里使用时会调用struct __list_iterator
		iterator begin()
		{
			//单参数的隐式类型转换——为啥？因为_head—>_next和__list_iterator(Node* node)参数是同类型的
			return iterator(_head->_next);
		}
		iterator end()//返回临时对象——常性
		{
			return iterator(_head);
		}
		typedef __list_iterator<T, const T&> const_iterator;
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end() const
		{
			return const_iterator(_head);
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
		Node* _head;//为typedef list_node<T> Node;
	};
}
void print(const List::list<int>& it)
{
	List::list<int>::const_iterator lt = it.begin();
	while (lt != it.end())
	{
		std::cout << *lt << " ";
		++lt;
	}
	std::cout << std::endl;
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
	while (lt != it.end())
	{
		std::cout << *lt << " ";
		++lt;
	}
	std::cout << std::endl;
	
} 