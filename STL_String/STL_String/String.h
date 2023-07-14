#include <iostream>
#include <assert.h>
#include <conio.h>
#include <istream>
using namespace std;
#pragma once
#pragma warning(disable:4996)
namespace Bit
{
	class string
	{
	public:
		//������
	/*	typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _size + _str;
		}*/
	
		//string(const char* str)
		//	: _str(new char[1])//ע�⣺���ǲ����Գ�ʼΪnullptr����Ϊ�ڷ���ʱ����ַ��ʿ�ָ�룡������
		//	, _size(0)//
		//	, _capcity(0)
		//{
		//	_str[0] = '\0';
		//}
		//string(const char* str = '\0')//����string(const char* str = "")
		//	: _str(new char[strlen(str) + 1])//�������+1��ô��Ч�ַ�-1
		//	, _size(strlen(str))//strlen������\0
		//	, _capcity(strlen(str))
		//	//ע������ʹ�ó�ʼ���б�������Ҫԭ���������ʼ������������˳��ı����嶼��ı䣡
		//{
		//	strcpy(_str, str);
		//}

		//���ƿ���
		string& operator = (const string& str)
		{
			if (this == &str)//��ֹ�Լ����Լ���ֵ
				//��������ַ��ƥ�ԣ�
				return *this;
			delete[] _str;//thisָ��ָ���
			_str = nullptr;
			_str = new char[strlen(str._str)+1];
			_size = str._size;//strlen������\0
			_capcity = str._capcity;
			strcpy(_str, str._str);
			return *this;
		}

		//string& operator = (const string& str)//���ƿ���2
		//{
		//	if (this == &str)//��ֹ�Լ����Լ���ֵ
		//		//��������ַ��ƥ�ԣ�
		//		return *this;
		//	string tmp(str._str);
		//	swap(tmp);
		//	return *this;
		//}
		//
		////ֱ����str����tmp
		//string& operator = (string str)//���ƿ���3
		//{
		//	swap(str);
		//	return *this;
		//}
		//string(const string& str)//�������췽��1
		//{
		//	_str = new char[strlen(str._str) + 1];
		//	_size = str._size;
		//	_capcity = str._capcity;
		//	strcpy(_str, str._str);
		//}

		string(const string& str)//�������췽��2
			: _str(new char[str._capcity])
			, _size(str._size)
			, _capcity(str._capcity)
		{
			strcpy(_str, str._str);
		}

		//�������췽��3
		//string(const string& str)
		//	: _str(nullptr)
		//	, _size(0)
		//	, _capcity(0)
		//{
		//	string tmp(str._str);//�൱�ڵ��ù���
		//	swap(tmp);
		//}
		//string(const string& str)//�������췽��3
		//	: _str(nullptr)
		//	, _size(0)
		//	, _capcity(0)
		//{
		//	string tmp(str._str);//�൱�ڵ��ù���
		//	std::swap(_str, tmp._str);
		//	std::swap(_capcity, tmp._capcity);
		//	std::swap(_size, tmp._size);
		//}
		void reserve(size_t n)//���ݴ�С��
		{
			if (n > _capcity)
			{
				char* tmp = new char[n + 1];//��һΪ\0
				strcpy(tmp, _str);
				delete[] _str;
				//ȫ�³��ȵ�_str
				_str = tmp;
				_capcity = n;
			}
		}
		//β��һ���ַ�
		void push_back(char ch)
		{
			//���˾�����
			if (_size == _capcity)
			{
				reserve(_capcity == 0 ? 4 : _capcity * 2);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		//����һ���ַ���
		void append(const char* str)
		{
			size_t len = strlen(str);
			size_t all = _size + len;//��ʹ�ô�С���ϱ���ӵ��ַ���С��
			if (all > _capcity)
			{
				reserve(all);
			}
			// ��Ҫ������ַ�����������ǰ�ַ�����ĩβ
			strcpy(_str + _size, str);  // _str + _size ��ʾ��ǰ�ַ�����ĩβλ��
			_size += len;  // ���µ�ǰ�ַ����ĳ���  
		}

		//string& insert(size_t pos, char* ch)//����
		//{
		//	assert(pos <= _capcity);//�Ǽ�Ϊ��
		//	if (_size == _capcity)
		//	{
		//		reserve(_capcity == 0 ? 4 : _capcity * 2);
		//	}
		//	size_t end = _size;
		//	while (end >= pos)
		//	{
		//		_str[end + 1] = _str[end];
		//		--end;
		//	}
		//	_str[pos] = ch;
		//	++_size;
		//	return *this;
		//}
		
		//����λ�ò���
		string& insert(size_t pos, const char* ch)
		{
			assert(pos <= _capcity);
			size_t chLength = strlen(ch);//���ch�ĳ���
			size_t newSize = _size + chLength;//ȫ�µ��ܳ����Ѿ�ʹ�õĵĳ���+�µĳ���
			//�ж��Ƿ���Ҫ����
			if (newSize >= _capcity)
			{
				size_t newCapacity = (_capcity == 0) ? 4 : _capcity * 2;
				reserve(newCapacity);
			}
			// �ƶ������ַ�Ϊ������ַ����ڳ��ռ�
			for (int i = _size; i >= (int)pos; --i)
			{
				_str[i + chLength] = _str[i];//�������ƶ�
			}
			// ���ַ��������ַ������Ƶ�ָ��λ��
			for (size_t i = 0; i < chLength; ++i)
			{
				_str[pos + i] = ch[i];
			}
			_size = newSize;
			return *this;
		}
		//����pos�ڼ�����ʼnpos�������ٸ�
		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			if (pos == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= pos;
			}
		}
		//������
		typedef const char* const_iterator;
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _size + _str;
		}
		//����
		void swap(string& str)
		{
			std::swap(_str, str._str);
			std::swap(_capcity, str._capcity);
			std::swap(_size, str._size);
		}
		//β��
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* ch)
		{
			append(ch);
			return *this;
		}
		//��������
		//const �ؼ����ں��������еĵ�һ��λ�ñ�ʾ�ú��������޸Ķ���ĳ�Ա������
		//���ڶ��� const �ؼ��ֱ�ʾ�ú��������޸Ķ�����
		//��ˣ�const char* c_str() const ��ʾ����һ����Ա������
		//�������޸Ķ����״̬��������һ��ָ���� null ��β�� C �ַ����ĳ���ָ�롣
		const char* c_str() const
		{
			return _str;
		}
		//����ʹ�ô�С
		size_t size() const
		{
			return _size;
		}
		//���������С
		size_t capcity() const
		{
			return _capcity;
		}

		char& operator[](size_t pos)//ʵ���������
		{

			assert(pos < _size);//!����!��
			return _str[pos];
		}
		/*size_t find(char ch, size_t pos = 0);
		
		size_t find(const char* sub, size_t pos = 0);
		
		bool operator>(const string& s) const;
	
		bool operator==(const string& s) const;
		
		bool operator<(const string& s) const;
		
		bool operator!=(const string& s) const;
	
		bool operator>=(const string& s) const;
	
		bool operator<=(const string& s) const;*/

		//��ʼ��
		string(const char* str = "")//����string(const char* str = "")
		{//��ʼ����
			_str = new char[strlen(str) + 1];//�������+1��ô��Ч�ַ�-1
			_size = strlen(str);//strlen������\0
			_capcity = strlen(str);
			strcpy(_str, str);
		}
		//��������
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capcity = 0;
		}
 	private:
		char* _str;
		size_t _size;
		size_t _capcity;
		//const static c++���⴦��
		const static size_t npos = -1;//��Ϊsize_t�����ֵ
	};
	ostream& operator<<(ostream& os, const string& str)//����ȡ���
	{
		os << str.c_str();
		return os;
	}
	istream& operator>>(istream& in,  string& str)//����ȡ����
	{
		char ch;
		ch = in.get();
		ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			str += ch;
			ch = in.get();
		}
		return in;
	}

	//size_t string::npos = -1;


	/*std::ostream& operator << (std::ostream& os, const string& str)
	{
		os << str.c_str();
		return os;
	}*/
	/*void test()
	{
		string s1("hello world");
	}*/
	//void test2()
	//{ 
	//	string s1("hello world");
	//	string s2;
	//	s1 += " hello Morgan";
	//	string s3(s1);
	//	s2 = s1;
	//	string s4;
	//	s4 = s1;
	//	s4.insert(0, "Wxyz");
	//	std::cout << s1 <<std::endl;
	//	std::cout << s4 << std::endl; 
	//}
	void test3()
	{
		string s1("hello world!!!!!!!!!");
		s1.push_back('1');
		cout << s1 << endl;
		string s2;
		s2 = s1;
		std::cout << s2.c_str() << std::endl;
		s2.erase(5, 10);
		std::cout << s2.c_str() << std::endl;

	}
}
