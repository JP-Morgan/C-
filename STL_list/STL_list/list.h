#pragma once
#include<iostream>
#include <assert.h>
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
	//����������
	//template<class T>
	//struct __list_const_iterator
	//{
	//	typedef list_node<T> Node;
	//	Node* _node;
	//	//����һ���ڵ㹹��һ��������Ϊɶ��������Ϊ���ǿ�����һ����ַ���ı�������ײ���淨����������string��vectorһ����
	//	__list_iterator(Node* node)
	//		:_node(node){}
	//	const T& operator*()//�����TΪ
	//	{
	//		return _node->_val;
	//	}
	//	//Ԥ���������(++)�ķ�������
	//	//����Ϊ��ͬ�ĵ���������
	//	//�� __list_iterator<T>&�� ����ѭ C++ ��Ԥ�����������Լ����
	//	//ǰ��++
	//	__list_iterator<T>& operator++()
	//	{
	//		 _node = _node->_next;
	//		 return *this;
	//	}
	//	//���������� �� operator++(int)����
	//	//�������������ص�ǰֵ��Ȼ�������ֵ����ͨ������һ�����������ͨ����Ϊ  int ���κ��������ʵ����ƣ����Խ�����ǰ������������ֿ�����
	//	//������ֵ�����ں�������ʹ�ã������Ĵ��������ڱ�����ȷ������ʹ���ĸ��������
	//	//����++
	//	__list_iterator<T> operator++(int)
	//	{
	//		__list_iterator<T> tmp(*this);
	//		_node = _node->_next;
	//		return tmp;
	//	}
	//	
	//	bool operator!=(const/*end�����г���*/ __list_iterator<T>& it)
	//	{
	//		return _node != it._node;
	//	}
	//	bool operator==(const/*end�����г���*/ __list_iterator<T>& it)
	//	{
	//		return _node == it._node;
	//	}
	//};
	
	//������
	/*typedef __list_iterator<T, T&, T*> iterator;
	typedef __list_iterator<T, const T&, const T*> const_iterator;*/
	template<class T,class Ref,class Ptr>
	struct __list_iterator
	{
		
		typedef __list_iterator<T, Ref, Ptr> self;
		typedef list_node<T> Node;
		Node* _node;
		//����һ���ڵ㹹��һ��������Ϊɶ��������Ϊ���ǿ�����һ����ַ���ı�������ײ���淨����������string��vectorһ����
		__list_iterator(Node* node)
			:_node(node) {}
		Ref operator*()//�����TΪ
		{
			return _node->_val;
		}

		Ptr operator->()//�����������������е�����
		{
			return &_node->_val;
		}
		//Ԥ���������(++)�ķ�������
		//����Ϊ��ͬ�ĵ���������
		//�� __list_iterator<T>&�� ����ѭ C++ ��Ԥ�����������Լ����
		//ǰ��++
		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		//���������� �� operator++(int)����
		//�������������ص�ǰֵ��Ȼ�������ֵ����ͨ������һ�����������ͨ����Ϊ  int ���κ��������ʵ����ƣ����Խ�����ǰ������������ֿ�����
		//������ֵ�����ں�������ʹ�ã������Ĵ��������ڱ�����ȷ������ʹ���ĸ��������
		//����++
		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const/*end�����г���*/  self& it) const
		{
			return _node != it._node;
		}
		bool operator==(const/*end�����г���*/  self& it) const
		{
			return _node == it._node;
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
			_szie = 0;
		}
		//��������
		list(const list<T>& lt)
		{
			/*this->*/_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;
			_szie = 0;
			for (auto e : lt)
			{
				/*this->*/push_back(e);
			}
		}
		//���ƺ���
		list<T>& operator=(list<T>& it)
		{
			SWAP(it);
			return *this;
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		typedef __list_iterator<T, T&, T*> iterator;//����ʹ��ʱ�����struct __list_iterator
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		iterator begin()
		{
			//����������ʽ����ת������Ϊɶ����Ϊ_head��>_next��__list_iterator(Node* node)������ͬ���͵�
			return iterator(_head->_next);
		}

		iterator end()//������ʱ���󡪡�����
		{
			return iterator(_head);
		}
		
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}
		//β��
		void push_back(const T& x)
		{
		/*	Node* tail = _head->_prev;
			Node* newhead = new Node(x);

			
			tail ->_next = newhead;
			newhead->_prev = tail;

			newhead->_next = _head;
			_head->_prev = newhead;
			newhead->_val = x;*/
			insert(end(), x);
		}
		//ͷ��
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		//βɾ
		void pop_back()
		{
			erase(--end());
		}
		//ͷɾ
		void pop_front()
		{
			erase(begin());
		}
		//���
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
			_szie = 0;
		}
		//�������
		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			prev->_next = newnode;
			newnode->_next = cur;
			
			cur->_prev = newnode;
			newnode->_prev = prev;
			_szie++;
			return newnode;
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* cur = pos._node;
			Node* prve = cur->_prev;
			Node* next = cur->_next;

			prve->_next = next;
			next->_prev = prve;

			delete cur;
			_szie--;
			return next;
		}

		void SWAP(list<T>& it)
		{
			std::swap(_szie, it._szie);
			std::swap(_head, it._head);
		}
		int szie()
		{
			return _szie;
		}
		
	private:
		Node* _head;//Ϊtypedef list_node<T> Node;
		int _szie;
	};
}





//void print(const List::list<int>& it)
//{
//	List::list<int>::const_iterator lt = it.begin();
//	while (lt != it.end())
//	{
//		std::cout << *lt << " ";
//		++lt;
//	}
//	std::cout << std::endl;
//}
//void test1()
//{
//	List::list<int> it;
//	it.push_back(1);
//	it.push_back(2);
//	it.push_back(3);
//	it.push_back(4);
//	it.push_back(5);
//	List::list<int>::iterator lt = it.begin();
//	while (lt != it.end())
//	{
//		std::cout << *lt << " ";
//		++lt;
//	}
//	std::cout << std::endl;
//} 
void test3()
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

	it.insert(it.begin(), 50);
	it.insert(it.begin(), 40);
	it.insert(it.begin(), 30);
	it.insert(it.begin(), 20);
	it.insert(it.end(), 10);
	it.insert(it.end(), 20);
	it.push_front(100);
	it.push_front(99);
	it.push_front(98);
	it.push_front(97);
	it.push_back(00);
	it.push_back(99);
	it.push_back(88);
	it.push_back(77);

	List::list<int> it2(it);
	for (auto e : it2)
	{
		std::cout << e << " . ";
	}
	std::cout << std::endl;

	for (auto e : it)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
	
	it.pop_front();
	it.pop_back();
	for (auto e : it)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
	std::cout << it.szie() << std::endl;
	it.clear();
	for (auto e : it)
	{
		std::cout << e << "xyz ";
	}
	std::cout << "ttc" << "xyz "<<std::endl;
	std::cout << it.szie() << std::endl;

}
void test_list3()
{
	List::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_front(5);
	lt.push_front(6);
	lt.push_front(7);
	lt.push_front(8);
	for (auto e : lt)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	lt.pop_front();
	lt.pop_back();

	for (auto e : lt)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	lt.clear();
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(40);
	for (auto e : lt)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

}

