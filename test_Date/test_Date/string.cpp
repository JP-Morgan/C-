#include<iostream>
#pragma warning(disable:4996)
using namespace std;
namespace Mystring
{
	class String
	{
	public:
		String(const char* str = "")
		{

			_size = _capasity = strlen(str);
			_str = new char[_capasity + 1];
			strcpy(_str, str);
			//memcpy(_str, str, sizeof(char) * _size);
		}
		~String()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capasity = 0;
		}
		void reserve(size_t n)//扩容大小！
		{
			if (_size == _capasity)
			{
				char* tmp = new char[n + 1];
				//memcpy(tmp, _str, sizeof(char) * _size);
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capasity = n;
			}
		}
		void push_back(char ch)
		{
			//满了就扩容
			if (_size == _capasity)
			{
				reserve(_capasity == 0 ? 4 : _capasity * 2);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		typedef const char* const_iterator;
		const_iterator end() const
		{
			return _str + _size;
		}
		const_iterator begin() const
		{
			return _str;
		}
		const char* c_str() const
		{
			return _str;
		}
		

	private:
		char* _str;
		size_t _size;
		size_t _capasity;
	};
}
int main()
{
	Mystring::String s1("12312312");
	std::cout<<s1.c_str();

	return 0;
}