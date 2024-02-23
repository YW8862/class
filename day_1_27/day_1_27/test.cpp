//#include"Date.h"
//#include<iostream>
//using namespace std;
//
////struct Date {
////	int year;
////	int month;
////	int day;
////	void print()
////	{
////		cout << year << "-" << month << "-" << day << endl;
////	}
////};
//

//class Date
//{
//private:
//	int _year;
//	int _month;
//	int _day;
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//
//	}
//};
//
//int main()
//{
//	//struct Date X;
//	//X.year = 2024;
//	//X.month = 1;
//	//X.day = 27;
//	//X.print();
//
//	Date x;
//	x.Init(2024, 1, 27);
//	
//	x.print();
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//class Line
//{
//public:
//	double length;
//	void Init(double len)
//	{
//		length = len;
//	}
//	double getLength()
//	{
//		return length;
//	}
//};
//
//int main()
//{
//	Line line;
//
//	// 设置长度
//	line.Init(6.0);
//	cout << "Length of line : " << line.getLength() << endl;
//
//	// 不使用成员函数设置长度
//	line.length = 10.0; // OK: 因为 length 是公有的
//	cout << "Length of line : " << line.length << endl;
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//class Box
//{
//public:
//	void setLength(double len)
//	{
//		length = len;
//	}
//	double getLength()
//	{
//		return length;
//	}
//
//private:
//	double length;
//};
//
//
//
//// 程序的主函数
//int main()
//{
//	Box box;
//	// 不使用成员函数设置宽度
//	//box.length = 10.0; // Error: 因为 length 是私有的
//	box.setLength(10.0);  // 使用成员函数设置宽度
//	cout << "Length of box : " << box.getLength() << endl;
//
//	return 0;
//}

#include <iostream>
using namespace std;

class Box
{
protected:
	double length;
};

class SmallBox :Box // SmallBox 是派生类
{
public:
	void setSmallLength(double wid)
	{
		length = wid;
	}
	double getSmallLength(void)
	{
		return length;
	}
};

struct A {

	long a1;

	short a2;

	int a3;

	int* a4;
	//8+4+4+8
};

// 程序的主函数
int main()
{
	//SmallBox box;

	//// 使用成员函数设置宽度
	//box.setSmallLength(5.0);
	//cout << "length of box : " << box.getSmallLength() << endl;
	cout << sizeof(struct A) << endl;
	return 0;
}


























//#include"Data.h"

//class A
//{
//public:
//	A()
//	{
//		_year = 2022;
//		_month = 12;
//		_day = 20;
//
//	}
//
//	void Init(int year, int month, int day) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void print()
//	{
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Data x;
//	x.Init(2024, 1, 27);
//	x.print();
//	return 0;
//	A x;
//	x.Init(2023,12,12);
//	x.print();
//	Data x;
//	x.Init(2024, 1, 27);
//	x.print();
//
//
//	return 0;
//}
