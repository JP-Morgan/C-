#pragma once
#include<iostream>
namespace List
{
	template<class T>//����ģ��
	struct list_node//
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _val;
		//���캯��
		//���캯��ʹ���˲���Ĭ��ֵ T()������ζ������ڴ����ڵ�ʱû���ṩ������
		//���ʹ�� T ���͵�Ĭ�Ϲ��캯������ʼ�� _val ��Ա������
		list_node(const T& val = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _val(val)
		{

		}
	};
	//������
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

	template<class T>//����ģ��
	class list
	{
		typedef list_node<T> Node;//���¶�������
	public:
		//���캯��
		list()
		{
			//������һ��ͷ�ڵ�
			_head = new _head;
			//ǰ��ͷ˫������
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
		//β��
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