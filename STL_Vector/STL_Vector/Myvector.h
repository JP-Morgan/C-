#pragma once
#include <iostream>
namespace Myvcetor
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;

		
		
		//扩容
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T *tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * size());
					delete[] _start;
				}
				_finish = tmp + size();
				_start = tmp;
				_end_of_storage = _start + n;
			}
		}
		//尾插
		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				size_t nwecapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(nwecapacity);
			}
			*_finish = x;
			_finish++;
		}
		//方括号访问
		T& operator[](size_t pos)
		{
			return _start[pos]
		}
		T& operator[](size_t pos) const
		{
			return _start[pos];
		}
		//迭代器
		iterator end() const
		{
			return _finish;
		}
		iterator begin() const
		{
			return _start;
		}
		//计算大小
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}
		size_t size() const
		{
			return _finish - _start;
		}
		//初始化
		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr) {}
		//析构
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
	void test1()
	{
		vector<int> vi;
		vi.push_back(1);
		vi.push_back(2);
		vi.push_back(3);
		vi.push_back(4);
		vi.push_back(5);
		for (auto e : vi)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}
}