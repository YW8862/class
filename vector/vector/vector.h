#pragma once
#include<iostream>
using namespace std;
#include<assert.h>

namespace myvector {

	template<typename T>
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
	private:
		T* _start;
		T* _finish;
		T* _end_of_storge;
	public:
		// 构造和销毁
		
		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storge(nullptr){
		}

		vector(size_t n, const T& value = T())
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storge(nullptr){
			reserve(n);
			while (n--){
				push_back(value);
			}
		}

		vector(int n, const T& value = T())
			: _start(new T[n])
			, _finish(_start + n)
			, _end_of_storge(_finish){
			for (int i = 0; i < n; ++i){
				_start[i] = value;
			}
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last){
			while (first != last){
				push_back(*first);
				++first;
			}
		}

		vector(const vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storge(nullptr){
			reserve(v.capacity());
			iterator it = begin();
			const_iterator vit = v.begin();
			while (vit != v.end()){
				*it++ = *vit++;
			}
			_finish = it;
		}

		vector<T>& operator=(vector<T> v){

			swap(v);
			return *this;
		}

		~vector(){
			if (_start){
				delete[] _start;
				_start = _finish = _end_of_storge = nullptr;
			}
		}
		/// <summary>
		/// 迭代器
		/// </summary>
		/// <returns></returns>
		
		iterator begin() {
			return _start;
		}

		iterator end() {
			return _finish;
		}

		const_iterator begin()const {
			return _start;
		}

		const_iterator end()const {
			return _finish;
		}
		/// <summary>
		/// 容量相关
		/// </summary>
		/// <returns></returns>
		size_t size()const {
			return _finish - _start;
		}

		size_t capacity()const {
			return _end_of_storge - _start;
		}

		void reserve(size_t n) {
			if (_end_of_storge - _start < n) {
				size_t old_size = _finish - _start;
				T* tmp = new T[n];	
				if (tmp) {
					memcpy(tmp, _start, sizeof(T) * (_end_of_storge - _start));
					delete[]_start;
					_start = tmp;
				}
				_finish = _start + old_size;
				_end_of_storge = _start + n;
			}
		}

		void resize(size_t n, const T& value = T()) {
			if (n < _finish - _start) {
				_finish = _start + n;
				return;
			}
			if (n > _end_of_storge - _start) {
				reserve(n);
			}
			iterator t = _finish;
			_finish = _start + n;
			while (t != _finish) {
				*t = value;
				++t;
			} 
		}

		T& operator[](size_t pos) {
			assert(pos < size());
			return *(_start + pos);
		}

		const T& operator[](size_t pos)const {
			assert(pos < size());
			return _start + pos;
		}

		void push_back(const T& x) {
			
			if (_finish == _end_of_storge) {
				reserve(_end_of_storge - _start == 0 ? 4 : 2 * (_end_of_storge - _start));
			}

			*_finish = x;
			++_finish;
		}

		void pop_back() {
			if (_finish != _start) {
				--_finish;
			}
		}

		void swap(vector<T>& x) {
			std::swap(this->_start, x._start);
			std::swap(this->_finish, x._finish);
			std::swap(this->_end_of_storge, x._end_of_storge);
		}

		iterator insert(iterator pos, const T& x) {
			assert(pos <= _finish);
			// 空间不够先进行增容
			if (_finish == _end_of_storge)
			{
				//size_t size = size();
				size_t newCapacity = (0 == capacity()) ? 1 : capacity() * 2;
				reserve(newCapacity);

				// 如果发生了增容，需要重置pos
				pos = _start + size();
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}

			*pos = x;
			++_finish;
			return pos;
		}

		iterator erase(iterator pos) {
			// 挪动数据进行删除
			iterator begin = pos + 1;
			while (begin != _finish) {
				*(begin - 1) = *begin;
				++begin;
			}

			--_finish;
			return pos;
		}


	};
}