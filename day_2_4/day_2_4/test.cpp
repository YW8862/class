#include<iostream>
using namespace std;

typedef int ElemType;

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
		data = nullptr;
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

	void Pop()
	{
		if (!is_Empty())
			size--;
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




//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	// 基本类型(内置类型)
//	int _year;
//	int _month;
//	int _day;
//
//	// 自定义类型
//	Time _t;
//};

//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	// 基本类型(内置类型)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// 自定义类型
//	Time _t;
//};
//
//
//
//int main()
//{
//	Date d;
//	cout << d._year << "-" << d._month << "-" << d._day << endl;
//	return 0;
//}


//class Date
//{
//public:
//	Date()
//	{
//		_year = 1900;
//		_month = 1;
//		_day = 1;
//		cout << "fun1" << endl;
//	}
//
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << "fun2" << endl;
//
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d;
//	return 0;
//}


class Time
{
public:
	~Time()
	{
		cout << "~Time()" << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
private:
	// 基本类型(内置类型)
	int _year = 1970;
	int _month = 1;
	int _day = 1;
	// 自定义类型
	Time _t;
};
int main()
{
	Date d;
	return 0;
}