#pragma once
#include <iostream>
#include <memory>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cassert>

namespace ns_STL
{
	class string 
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
	public:
		//默认初始化分配0空间给字符串
		string():str(nullptr),size(0),capacity(0)
		{}

		//赋值构造
		string(const string& other):str(nullptr),size(other.size),capacity(other.capacity)
		{
			//分配内存
			str = new char[capacity];
			memset(str, 0, capacity);
			memcpy(str, other.str, size);
		}

		//移动构造
		string(string&& other) noexcept :str(nullptr), size(other.size), capacity(other.capacity)
		{
			//交换数据
			str = other.str;
			other.str = nullptr;
			other.size = 0;
			other.capacity = 0;
		}

		~string()
		{
			delete[] str;
			size = 0;
			capacity = 0;
		}

		//赋值重载
		string& operator=(const string& other) noexcept
		{
			if (&other == this)
			{
				return *this;
			}

			//先释放原来资源
			delete[] str;
			size = 0;
			capacity = 0;

			//将资源拷贝到新的字符串中
			str = new char[other.capacity];
			memset(str, 0, capacity);
			memcpy(str, other.str, size);

			return *this;
		}
		
		//移动赋值重载
		string& operator=(string && other)noexcept
		{
			//先释放原来资源
			delete[] str;
			size = other.size;
			capacity = other.capacity;
			
			str = other.str;
			other.str = nullptr;
			other.size = 0;
			other.capacity = 0;
		}

		char operator[](int index)const
		{
			assert(index >= 0 && index < size);
			return str[index];
		}

		//重新设置大小
		void resize(int newSize)
		{
			//如果新的size比原来大，把原来的数据拷贝过去，剩下的位置填充'\0'
			if (newSize > size)
			{
				recapacity(newSize * 1.5);
				size = newSize;
			}
			else
			{
				memset(str + size - 1, 0, size - newSize);
			}
		}

		string& operator+=(string &other)
		{
			//如果字符串已经满了，进行扩容
			if (size + other.size > capacity)
			{
				recapacity((size + other.size)*1.5);
			}
			memcpy(str + size, other.str, other.size);
			size += other.size;
			return *this;
		}

		string& operator+=(char ch)
		{
			if (size + 1 > capacity)
			{
				recapacity(capacity * 1.5);
			}
			str[size] = ch;
			size += 1;
			return *this;
		}

		string& append(string &other)
		{
			return *this += other;
		} 

		string& append(char ch)
		{
			return *this += ch;
		}

		iterator begin()
		{
			return str;
		}

		const_iterator begin()const
		{
			return str;
		}

		iterator end()
		{
			return str + size;
		}

		const_iterator end()const
		{
			return str + size;
		}


	private:
		//实现扩容机制
		void recapacity(int newCapacity)
		{
			char* newStr = new char[newCapacity];
			memset(newStr, 0, newCapacity);
			memcpy(newStr, str, size);
			delete[]str;
			str = newStr;
			capacity = newCapacity;
		}

	private:
		char* str;		//存放字符串的内容
		int size;		//存放字符串的实际大小
		int capacity;	//存放字符串的容量大小
	public:
		static int npos;
	};
	int string::npos = -1;
};

