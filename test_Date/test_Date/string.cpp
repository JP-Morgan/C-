#include<iostream>
#include <cassert>
#pragma warning(disable:4996)
using namespace std;
namespace Mystring
{
	class String
	{
	private:
		char* _str;
		size_t _size;
		size_t _capasity;
	public:
	//��������
		//��ʼ������
		String(const char* str = "")
		{
			_str = new char[strlen(str) + 1];//����һ�仰+1Ϊ��\0��λ��
			_size = strlen(str);
			_capasity = strlen(str);
			strcpy(_str, str);
		}
		//��������
		~String()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capasity = 0;
		}
		//��������
		String(const String& str)
			//: _str(new char[str._capasity])û��+1���������������ʱ�������Ҫԭ����Ī��¼��\0������������
			//��Ҫԭ����delete������free���ͷ��ַ�����ʱ����Ҫʶ��\0
			: _str(new char[str._capasity+1])
			, _size(str._size)
			, _capasity(str._capasity)
		{
			strcpy(_str, str._str);
		}
		//���ƿ�������(ע��һ�����ĵ㸴�ƿ�������Ҫ��const char& strΪɶ�����ӵ�ַ��)
		String& operator = (const String& str)
		{
			if (this == &str) { return *this; }
			delete[]_str;
			_str = nullptr;
			_str = new char[strlen(str._str) + 1];
			_size = str._size;
			_capasity = str._capasity;
			strcpy(_str, str._str);
			return *this;
		}
		//�鿴����
		const char* c_str() const
		{
			return _str;
		}
		//�������
		char& operator[](const size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}
		//������
		typedef const char* const_iterator;
		const_iterator end() const
		{
			return _str + _size;//��_str�ƶ���ĩβ���أ�
		}
		const_iterator bigen() const
		{
			return _str;
		}
		//��ȡ����
		size_t size() const
		{
			return _size;
		}
		size_t capasity() const
		{
			return _capasity;
		}
	//���ӹ���
		//����
		void reserve(const char n)
		{
			if (n > _capasity)
			{
				//��Ϊ_str��char*�������ԣ�
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;//delete����_str�е�����
				_str = tmp;
				_capasity = n;
			}
		}
		//β��
		void push_back(char ch)
		{
			if (_size == _capasity)
			{
				reserve(_capasity == 0 ? 4 : _capasity * 2);
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}
		//β��
		String& operator+=(const char str)
		{
			push_back(str);
			return *this;
		}

	};
	void test()
	{
		String s1("123456");
		String s2(s1);
		s1.push_back('1');
		s1.push_back('2');
		s1.push_back('3');
		s1.push_back('4');
		cout << s1.c_str() << endl;
		cout << endl;
		for (size_t i = 0; i < s2.size(); i++)
		{
			cout << s1[i] << " ";
		}
		cout << endl;
	}
}
int main()
{
	Mystring::test();
	return 0;
}