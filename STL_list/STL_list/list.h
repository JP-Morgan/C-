#pragma once
#include<iostream>
namespace List
{
	template<class T>//����ģ��
	struct list_node//
	{
		list_node<T>* _next;//T��������ָ��
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
		//����һ���ڵ㹹��һ��������Ϊɶ��������Ϊ���ǿ�����һ����ַ���ı�������ײ���淨����������string��vectorһ����
		__list_iterator(Node* node)
			:_node(node){}
		T& operator*()//�����TΪ
		{
			return _node->_val;
		}
		//Ԥ���������(++)�ķ�������
			//����Ϊ��ͬ�ĵ���������
				//�� __list_iterator<T>&�� ����ѭ C++ ��Ԥ�����������Լ����
		__list_iterator<T>& operator++()
		{
			 _node = _node->_next;
			 return *this;
		}

		bool operator!=(const/*end�����г���*/ __list_iterator<T>& it)
		{
			return _node != it._node;
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
			_head = new Node;
			//ǰ��ͷ˫������
			_head->_prev = _head;
			_head->_next = _head;
		}
		typedef __list_iterator<T> iterator;//����ʹ��ʱ�����struct __list_iterator
		iterator begin()
		{
			//����������ʽ����ת������Ϊɶ����Ϊ_head��>_next��__list_iterator(Node* node)������ͬ���͵�
			return _head->_next;
		}
		iterator end()//������ʱ���󡪡�����
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
		Node* _head;//Ϊtypedef list_node<T> Node;
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
	while (lt != it.end())
	{
		std::cout << *lt << " ";
		++lt;
	}
	std::cout << std::endl;
}