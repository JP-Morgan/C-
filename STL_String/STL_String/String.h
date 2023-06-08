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
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
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
		{
			_str = new char[strlen(str) + 1];//�������+1��ô��Ч�ַ�-1
			_size = strlen(str);//strlen������\0
			_capcity = strlen(str);
			strcpy(_str, str);
		}
		string(const string& s);
		string& operator=(const string& s);
		
		~string()
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

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
	private:
		char* _str;
		size_t _size;
		size_t _capcity;
	};
	void test()
	{
		string s1("hello world");
	}
}