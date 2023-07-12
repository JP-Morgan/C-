#pragma once
#include <iostream>
namespace Myvcetor
{
	template<class T>
	class vector
	{
	public:
		typedef T *iterator;

		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr) {}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				*T tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * size());
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + size();
				_end_of_storage = _start + n;
			}
		}

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


		size_t capacity() const
		{
			return _end_of_storage - _start;
		}
		size_t size() const
		{
			return _filish - _start;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}