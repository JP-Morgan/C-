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
		

		////����
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					//memcpy(tmp, _start, sizeof(T) * sz);
					//ΪʲôҪ�����ģ�
					/*for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;*/
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
		//���루��������
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

		//ɾ��
		iterator erase(iterator pos)
		{
			//Ϊʲô��<_finish?
			assert(pos >= _start && pos < _finish);
			iterator dele = pos;
			while (dele != _finish)
			{
				*dele = *(dele + 1);
				dele++;
			}
			_finish--;

			return pos + 1;
		}

		//���¶����С
		void resize(size_t n, const T& val= T())//T()Ϊ���������÷�ע�⣺��������Ҳ�ǿ���ʹ�õ�
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_start + n != _finish)
				{
					*_finish = val;
					_finish++;
				}
			}
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

		void swap(vector<T>& v)
		{
			std::swap(_start,v._start);
			std::swap(_finish,v._finish);
			std::swap(_end_of_storage,v._end_of_storage);
		}

		vector<T>& operator=(vector<T>& v)
		{
			swap(v);
			return *this;
		}
		//��ʼ��
		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr) {}
		
		//��������
	/*	vector(const vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			_start = new T[v.capacity()];
			memcpy(_start, v._start, sizeof(T) * v.size());
			_finish = _start + v.size();
			_end_of_storage = _start + v.capacity();
		}*/
		
		//��������2
		vector(const vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr) 
		{
			reserve(v.capacity());
			for (auto e:v)
			{
				push_back(e);
			}
		}

		vector(size_t n, const T& val = T())
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			resize(n, val);
		}
		vector(int n, const T& val = T())
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			resize(n, val);
		}
		//[first , last)
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
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
//void test1()
//{
//	Myvcetor::vector<int> vi;
//	vi.push_back(1);
//	vi.push_back(2);
//	vi.push_back(3);
//	vi.push_back(4);
//	vi.push_back(5);
//	for (auto e : vi)
//	{
//		std::cout << e << " ";
//	}
//	std::cout << std::endl;
//	for (size_t i = 0; i < vi.size(); i++)
//	{
//		printf("%d", vi[i]);
//	}
//	std::cout << std::endl;
//}
//void test2()
//{
//	Myvcetor::vector<int> vi;
//	vi.push_back(1);
//	vi.push_back(2);
//	vi.push_back(3);
//	vi.push_back(4);
//	vi.push_back(5);
//	vi.erase(vi.begin());
//	for (auto e : vi)
//	{
//		std::cout << e << " ";
//	}
//	std::cout << std::endl;
//}