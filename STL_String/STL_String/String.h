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
		//迭代器
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

		//复制拷贝
		string& operator = (const string& str)
		{
			if (this == &str)//防止自己给自己赋值
				//是两个地址的匹对！
				return *this;
			delete[] _str;//this指针指向的
			_str = nullptr;
			_str = new char[strlen(str._str)+1];
			_size = str._size;//strlen不包含\0
			_capcity = str._capcity;
			strcpy(_str, str._str);
			return *this;
		}

		//string& operator = (const string& str)//复制拷贝2
		//{
		//	if (this == &str)//防止自己给自己赋值
		//		//是两个地址的匹对！
		//		return *this;
		//	string tmp(str._str);
		//	swap(tmp);
		//	return *this;
		//}
		//
		////直接让str顶替tmp
		//string& operator = (string str)//复制拷贝3
		//{
		//	swap(str);
		//	return *this;
		//}
		//string(const string& str)//拷贝构造方法1
		//{
		//	_str = new char[strlen(str._str) + 1];
		//	_size = str._size;
		//	_capcity = str._capcity;
		//	strcpy(_str, str._str);
		//}

		string(const string& str)//拷贝构造方法2
			: _str(new char[str._capcity])
			, _size(str._size)
			, _capcity(str._capcity)
		{
			strcpy(_str, str._str);
		}

		//拷贝构造方法3
		//string(const string& str)
		//	: _str(nullptr)
		//	, _size(0)
		//	, _capcity(0)
		//{
		//	string tmp(str._str);//相当于调用构造
		//	swap(tmp);
		//}
		//string(const string& str)//拷贝构造方法3
		//	: _str(nullptr)
		//	, _size(0)
		//	, _capcity(0)
		//{
		//	string tmp(str._str);//相当于调用构造
		//	std::swap(_str, tmp._str);
		//	std::swap(_capcity, tmp._capcity);
		//	std::swap(_size, tmp._size);
		//}
		void reserve(size_t n)//扩容大小！
		{
			if (n > _capcity)
			{
				char* tmp = new char[n + 1];//加一为\0
				strcpy(tmp, _str);
				delete[] _str;
				//全新长度的_str
				_str = tmp;
				_capcity = n;
			}
		}
		//尾插一个字符
		void push_back(char ch)
		{
			//满了就扩容
			if (_size == _capcity)
			{
				reserve(_capcity == 0 ? 4 : _capcity * 2);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		//插入一个字符串
		void append(const char* str)
		{
			size_t len = strlen(str);
			size_t all = _size + len;//已使用大小加上被真加的字符大小！
			if (all > _capcity)
			{
				reserve(all);
			}
			// 将要插入的字符串拷贝到当前字符串的末尾
			strcpy(_str + _size, str);  // _str + _size 表示当前字符串的末尾位置
			_size += len;  // 更新当前字符串的长度  
		}

		//string& insert(size_t pos, char* ch)//插入
		//{
		//	assert(pos <= _capcity);//非假为真
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
		
		//按照位置插入
		string& insert(size_t pos, const char* ch)
		{
			assert(pos <= _capcity);
			size_t chLength = strlen(ch);//获得ch的长度
			size_t newSize = _size + chLength;//全新的总长度已经使用的的长度+新的长度
			//判断是否需要扩容
			if (newSize >= _capcity)
			{
				size_t newCapacity = (_capcity == 0) ? 4 : _capcity * 2;
				reserve(newCapacity);
			}
			// 移动现有字符为插入的字符串腾出空间
			for (int i = _size; i >= (int)pos; --i)
			{
				_str[i + chLength] = _str[i];//后往后移动
			}
			// 将字符从输入字符串复制到指定位置
			for (size_t i = 0; i < chLength; ++i)
			{
				_str[pos + i] = ch[i];
			}
			_size = newSize;
			return *this;
		}
		//擦除pos第几个开始npos擦除多少个
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
		//迭代器
		typedef const char* const_iterator;
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _size + _str;
		}
		//交换
		void swap(string& str)
		{
			std::swap(_str, str._str);
			std::swap(_capcity, str._capcity);
			std::swap(_size, str._size);
		}
		//尾加
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
		//返回内容
		//const 关键字在函数声明中的第一个位置表示该函数不会修改对象的成员变量。
		//而第二个 const 关键字表示该函数不会修改对象本身。
		//因此，const char* c_str() const 表示这是一个成员函数，
		//它不会修改对象的状态，并返回一个指向以 null 结尾的 C 字符串的常量指针。
		const char* c_str() const
		{
			return _str;
		}
		//返回使用大小
		size_t size() const
		{
			return _size;
		}
		//返回整体大小
		size_t capcity() const
		{
			return _capcity;
		}

		char& operator[](size_t pos)//实现随机查找
		{

			assert(pos < _size);//!真与!假
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

		//初始化
		string(const char* str = "")//或者string(const char* str = "")
		{//初始化！
			_str = new char[strlen(str) + 1];//如果不加+1那么有效字符-1
			_size = strlen(str);//strlen不包含\0
			_capcity = strlen(str);
			strcpy(_str, str);
		}
		//析构函数
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
		//const static c++特殊处理
		const static size_t npos = -1;//变为size_t的最大值
	};
	ostream& operator<<(ostream& os, const string& str)//流提取输出
	{
		os << str.c_str();
		return os;
	}
	istream& operator>>(istream& in,  string& str)//流提取输入
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
