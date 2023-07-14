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
	//基础功能
		//初始化函数
		String(const char* str = "")
		{
			_str = new char[strlen(str) + 1];//还是一句话+1为给\0留位置
			_size = strlen(str);
			_capasity = strlen(str);
			strcpy(_str, str);
		}
		//析构函数
		~String()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capasity = 0;
		}
		//拷贝构造
		String(const String& str)
			//: _str(new char[str._capasity])没有+1他会在最后析构的时候崩溃主要原因是莫有录入\0但在析构崩溃
			//主要原因是delete调用了free，释放字符串的时候需要识别到\0
			: _str(new char[str._capasity+1])
			, _size(str._size)
			, _capasity(str._capasity)
		{
			strcpy(_str, str._str);
		}
		//复制拷贝函数(注意一个核心点复制拷贝函数要加const char& str为啥？链接地址：)
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
		//查看内容
		const char* c_str() const
		{
			return _str;
		}
		//随机查找
		char& operator[](const size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}
		//迭代器
		typedef const char* const_iterator;
		const_iterator end() const
		{
			return _str + _size;//将_str移动到末尾返回；
		}
		const_iterator bigen() const
		{
			return _str;
		}
		//提取数据
		size_t size() const
		{
			return _size;
		}
		size_t capasity() const
		{
			return _capasity;
		}
	//增加功能
		//扩容
		void reserve(const char n)
		{
			if (n > _capasity)
			{
				//因为_str是char*类型所以：
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;//delete的是_str中的内容
				_str = tmp;
				_capasity = n;
			}
		}
		//尾插
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
		//尾加
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