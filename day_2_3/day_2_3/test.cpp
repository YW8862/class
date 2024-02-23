#include<iostream>
using namespace std;

typedef char ElemType;
class Stack
{
private:
	int size;
	int capacity;
	ElemType* data;
public:
	Stack(int n = 4)
	{
		data = (ElemType*)malloc(sizeof(ElemType) * n);
		size = 0;
		capacity = n;
	}

	~Stack()
	{
		free(data);
		size = 0;
		capacity = 0;
	}

	void Boarden()
	{
		ElemType* p = (ElemType*)realloc(data, sizeof(ElemType) * capacity * 2);
		if (p)
		{
			data = p;
			capacity = capacity * 2;
		}
	}

	void Push(ElemType x)
	{
		if (capacity == size)
			Boarden();
		data[size++] = x;
	}

	bool is_Empty()
	{
		return size == 0;
	}

	ElemType Pop()
	{
		if (!is_Empty())
		{
			size--;
			return data[size];
		}
		return 0;
	}

	ElemType Get_Top()
	{
		if (size)
			return data[size - 1];
	}

	void print()
	{
		int i = 0;
		for (int i = 0; i < size; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}
};

class Solution {
public:
	bool isValid(string s) {
		Stack st;
		int i = 0;
		char* c = &s[0];
		while (*(c + i))
		{
			char x = *(c + i);
			if (x == '{' || x == '[' || x == '(')
				st.Push(x);
			else if (st.Pop() != x)
				return false;
			i++;
		}
		return true;
	}
};
