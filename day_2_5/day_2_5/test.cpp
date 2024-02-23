#include<iostream>
using namespace std;

//#include <stdio.h>
//int judge(int year)
//{
//	if (year % 4 || (year % 100 == 0 && year % 400))
//		return 0;
//	return 1;
//}
//
//int main() {
//	int year = 0, month = 0, day = 0;
//	while (scanf_s("%d %d %d", &year, &month, &day) != EOF) { // 注意 while 处理多个 case
//		int date[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		if (judge(year))
//			date[2] = 29;
//		int num = 0;
//		for (int i = 0; i < month; i++)
//			num += date[i];
//		num += day;
//		printf("%d\n", num);
//	}
//	return 0;
//}


//class Date
//{
//public:
//    Date(int year =2024, int month = 2, int day = 6)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    
//    Date(const Date& d)  
//    {
//        _year = d._year;
//        _month = d._month;
//        _day = d._day;
//    }
//    void Print()
//    {
//        cout << _year << "-" << _month << "-" << _day << endl;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};


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
	Stack(const Stack& s)
	{
		ElemType*tmp = (ElemType*)malloc(sizeof(ElemType) * s.capacity);
		if (tmp == nullptr)
		{
			perror("copy error");
			exit(-1);
		}
		memcpy(tmp, s.data, sizeof(ElemType) * s.capacity);
		data = tmp;
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


//int main()
//{
//	Stack s;
//	s.Push(12);
//	s.Push(23);
//	s.Push(43);
//	s.Push(35);
//	s.Push(565);
//	s.print();
//	Stack s2(s);
//	s.print();
//	int x = 1;
//	const int& a = x;
//	const int b = 20;
//	const int& q = a + b;
//	cout << q << endl;
//	return 0;
//}


//class Date
//{
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//public:
//	Date(int year = 2024, int month = 2, int day = 6)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//Date(const Date& d)
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}
//
//	bool operator<(const Date d2)
//	{
//		if (_year < d2._year)
//			return true;
//		else if (_month < d2._month)
//			return true;
//		else if (_day < d2._day)
//			return true;
//		return false;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" <<_day <<endl;
//	}
//};


//class Date
//{
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//public:
//	Date(int year = 2024, int month = 2, int day = 6)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	~Date()
//	{
//		cout << this << endl;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//};

class Date
{

private:
	int _year;
	int _month;
	int _day;

public:
	Date(int year = 2024, int month = 2, int day = 6)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	~Date()
	{
		cout << this << endl;
	}
};

void fun(Date d)
{
	return;
}
int main()
{
	Date d1(2022, 2, 1);
	fun(d1);
	return 0;
}

