#pragma once
#include <iostream>
#include <cassert>
namespace Myvcetor
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		
		//����
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * sz);
					delete[] _start;
				}
				
				_start = tmp;
				_finish = tmp + sz;
				_end_of_storage = _start + n;
			}
		}

		//β��
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
		//����
		iterator insert(iterator pos, const T& val)
		{
			assert(pos >= _start && pos <= _finish);

			if (_finish == _end_of_storage)
			{
				//��ֹ������ʧЧ����1
				size_t tmp = pos - _start;

				size_t nwecapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(nwecapacity);
				//1
				pos = tmp + _start;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = val;
			_finish++;
			return *this;
		}

		//�����ŷ���
		T& operator[](size_t pos) 
		{
			return _start[pos];
		}
		const T& operator[](size_t pos) const
		{
			return _start[pos];
		}

		//������
		iterator end() 
		{
			return _finish;
		}
		iterator begin() 
		{
			return _start;
		}
		const_iterator end() const//ͻȻ��������iterator end() const�Ƕ�this����Ч������const iterator �ǶԷ�����Ч��
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}

		//�����С
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}
		size_t size() const
		{
			return _finish - _start;
		}

		//��ʼ��
		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr) {}
		
		//����
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
	
}
void test1()
{
	Myvcetor::vector<int> vi;
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
	for (size_t i = 0; i < vi.size(); i++)
	{
		printf("%d", vi[i]);
	}
	std::cout << std::endl;
}