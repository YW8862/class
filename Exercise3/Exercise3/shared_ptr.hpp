#pragma once

namespace ns_ptr
{
	template<typename T>
	class shared_ptr
	{
	public:
		shared_ptr() :cnt(nullptr), ptr(nullptr)
		{}

		shared_ptr(T* _ptr) :cnt(new int(1)), ptr(_ptr)
		{}

		shared_ptr(const shared_ptr<T> & other):cnt(other.cnt),ptr(other.ptr)
		{
			addAcount();
		}

		~shared_ptr()
		{
			delCount();
		}

		void addCount()
		{
			++(*addCount);
		}

		void delCount()
		{
			if (--(*cnt) == 0)
			{
				delete ptr;
				delete cnt;
			}
		}

		shared_ptr operator=(const shared_ptr<T> &other)
		{
			if (other.ptr == ptr)	return *this;
			//½â³ý°ó¶¨
			delCount();
			//
			ptr = other.ptr;
			cnt = other.cnt;
			addCount();

			return *this;
		}

		T& operator *()
		{
			return *ptr;
		}

		T* operator->()
		{
			return ptr;
		}

	private:
		int* cnt;
		T* ptr;
	};
};