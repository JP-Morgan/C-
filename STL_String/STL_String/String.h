#include <iostream>
#include <assert.h>
#pragma once
#pragma warning(disable:4996)
namespace Bit
{
	class string
	{
	public:
		//迭代器
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
		//	: _str(new char[1])//注意：我们不可以初始为nullptr，因为在访问时会出现访问空指针！！！！
		//	, _size(0)//
		//	, _capcity(0)
		//{
		//	_str[0] = '\0';
		//}
		//string(const char* str = '\0')//或者string(const char* str = "")
		//	: _str(new char[strlen(str) + 1])//如果不加+1那么有效字符-1
		//	, _size(strlen(str))//strlen不包含\0
		//	, _capcity(strlen(str))
		//	//注不建议使用初始化列表！——组要原因是如果初始化区或声明区顺序改变整体都会改变！
		//{
		//	strcpy(_str, str);
		//}

		string(const char* str = "")//或者string(const char* str = "")
		{//初始化！
			_str = new char[strlen(str) + 1];//如果不加+1那么有效字符-1
			_size = strlen(str);//strlen不包含\0
			_capcity = strlen(str);
			strcpy(_str, str);
		}

		~string()//析构函数
		{
			delete[] _str;
			_str = nullptr;
			_size = _capcity = 0;
		}
		//返回内容
		const char* c_str() const
		{
			return _str;
		}
		//返回大小
		size_t size() const
		{
			return _size;
		}

		char& operator[](size_t pos)//实现随机查找
		{
			assert(pos < _size);
			return _str[pos];
		}

		string& operator = (const string& str)//复制拷贝
		{
			if (this == &str)//防止自己给自己赋值
				//是两个地址的匹对！
				return *this;

			delete[] _str;//this指针指向的
			_str = new char[strlen(str._str)+1];
			_size = str._size;//strlen不包含\0
			_capcity = str._capcity;
			strcpy(_str, str._str);
			return *this;
		}

		string(const string& str)//拷贝构造
		{
			_str = new char[strlen(str._str) + 1];
			_size = str._size;
			_capcity = str._capcity;
			strcpy(_str, str._str);

		}
		friend std::ostream& operator << (std::ostream& os, const string& str);//流提取输出
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