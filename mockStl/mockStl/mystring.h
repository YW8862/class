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
		//Ĭ�ϳ�ʼ������0�ռ���ַ���
		string():str(nullptr),size(0),capacity(0)
		{}

		//��ֵ����
		string(const string& other):str(nullptr),size(other.size),capacity(other.capacity)
		{
			//�����ڴ�
			str = new char[capacity];
			memset(str, 0, capacity);
			memcpy(str, other.str, size);
		}

		//�ƶ�����
		string(string&& other) noexcept :str(nullptr), size(other.size), capacity(other.capacity)
		{
			//��������
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

		//��ֵ����
		string& operator=(const string& other) noexcept
		{
			if (&other == this)
			{
				return *this;
			}

			//���ͷ�ԭ����Դ
			delete[] str;
			size = 0;
			capacity = 0;

			//����Դ�������µ��ַ�����
			str = new char[other.capacity];
			memset(str, 0, capacity);
			memcpy(str, other.str, size);

			return *this;
		}
		
		//�ƶ���ֵ����
		string& operator=(string && other)noexcept
		{
			//���ͷ�ԭ����Դ
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

		//�������ô�С
		void resize(int newSize)
		{
			//����µ�size��ԭ���󣬰�ԭ�������ݿ�����ȥ��ʣ�µ�λ�����'\0'
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
			//����ַ����Ѿ����ˣ���������
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
		//ʵ�����ݻ���
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
		char* str;		//����ַ���������
		int size;		//����ַ�����ʵ�ʴ�С
		int capacity;	//����ַ�����������С
	public:
		static int npos;
	};
	int string::npos = -1;
};

