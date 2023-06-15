#pragma once
#include <iostream>
class string
{
public:
	string(const char* str = 0);
	string(const string& str);
	~string();
	string& operator = (const string& str);
	char* get_char()const
	{
		return _str;
	}
private:
	char* _str;
	size_t _size;
	size_t _InAll;
};
inline
string::string(const char* str = "")
{
	if(str)
	{
		_str = new char[strlen(str) + 1];
		_size = strlen(str);
		_InAll = strlen(str);
		strcpy(_str, str);
	}
	else
	{
		_str = new char[1];
		_size = strlen(str);
		_InAll = strlen(str);
		*_str = '\0';
	}
}
inline
string::~string()
{
	delete[] _str;
	_size = _InAll = 0;
}

inline
string::string(const string& str)
{
	_str = new char[strlen(str._str) + 1];
	strcpy(_str, str._str);
	_InAll = str._InAll;
	_size = str._size;
}

inline
string& string::operator = (const string& str)
{
	if (this == &str)
	{
		return *this
	}
	delete[] _str;
	_str = new char[strlen(str._str) + 1];
	strcpy(_str, str._str);
	_InAll = str._InAll;
	_str = str._str;
	return *this;//s1=s2=s3可以连续赋值
}