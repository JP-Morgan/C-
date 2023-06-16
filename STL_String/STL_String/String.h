#include <iostream>
#include <assert.h>
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
		typedef const char* const_iterator;
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _size + _str;
		}
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

		string(const char* str = "")//����string(const char* str = "")
		{//��ʼ����
			_str = new char[strlen(str) + 1];//�������+1��ô��Ч�ַ�-1
			_size = strlen(str);//strlen������\0
			_capcity = strlen(str);
			strcpy(_str, str);
		}

		~string()//��������
		{
			delete[] _str;
			_str = nullptr;
			_size = _capcity = 0;
		}
		//��������
		const char* c_str() const
		{
			return _str;
		}
		//���ش�С
		size_t size() const
		{
			return _size;
		}

		char& operator[](size_t pos)//ʵ���������
		{
			assert(pos < _size);//!����!��
			return _str[pos];
		} 

		//string& operator = (const string& str)//���ƿ���
		//{
		//	if (this == &str)//��ֹ�Լ����Լ���ֵ
		//		//��������ַ��ƥ�ԣ�
		//		return *this;

		//	delete[] _str;//thisָ��ָ���
		//	_str = new char[strlen(str._str)+1];
		//	_size = str._size;//strlen������\0
		//	_capcity = str._capcity;
		//	strcpy(_str, str._str);
		//	return *this;
		//}

		string& operator = (const string& str)//���ƿ���2
		{
			if (this == &str)//��ֹ�Լ����Լ���ֵ
				//��������ַ��ƥ�ԣ�
				return *this;
			string tmp(str._str);
			swap(tmp);
			return *this;
		}
		//string(const string& str)//�������췽��1
		//{
		//	_str = new char[strlen(str._str) + 1];
		//	_size = str._size;
		//	_capcity = str._capcity;
		//	strcpy(_str, str._str);
		//}

		//string(const string& str)//�������췽��2
		//	: _str(new char[str._capcity])
		//	, _size(str._size)
		//	, _capcity(str._capcity)
		//{
		//	strcpy(_str, str._str);
		//}
		void swap(string& str)
		{
			std::swap(_str, str._str);
			std::swap(_capcity, str._capcity);
			std::swap(_size, str._size);
		}
		string(const string& str)//�������췽��3
			: _str(nullptr)
			, _size(0)
			, _capcity(0)
		{
			string tmp(str._str);//�൱�ڵ��ù���
			swap(tmp);
		}
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
		friend std::ostream& operator << (std::ostream& os, const string& str);//����ȡ���
 	private:
		char* _str;
		size_t _size;
		size_t _capcity;
	};
	std::ostream& operator << (std::ostream& os, const string& str)
	{
		os << str.c_str();
		return os;
	}
	/*void test()
	{
		string s1("hello world");
	}*/
	void test2()
	{ 
		string s1("hello world");
		string s2;
		string s3(s1);
		s2 = s1;
		string s4;
		std::cout << s1 <<std::endl;
	}
}