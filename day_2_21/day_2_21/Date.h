#include<iostream>
#include<assert.h>
using namespace std;
class Date
{
private:
	int _year;
	int _month;
	int _day;
public:

	//获取某月份的天数
	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);
		static int MonthDay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 &&
			((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
			return 29;
		return MonthDay[month];
	}

	//检查日期合法性
	bool CheckInvalid();
	//构造函数
	Date(int year = 2024, int month = 2, int day = 10);

	//操作符重载
	Date& operator=(const Date& d);
	bool operator<(const Date& d2) const;
	bool operator>(const Date& d2) const;
	bool operator<=(const Date& d2) const;
	bool operator>=(const Date& d2) const;
	bool operator==(const Date& d2) const;
	bool operator!=(const Date& d2) const;

	Date operator+(int day);
	Date& operator+=(int day);

	Date& operator-=(int day);
	Date operator-(int day);
	int operator-(const Date d2) const;


	Date& operator++();
	Date operator++(int);

	Date& operator--();
	Date operator--(int);

	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

	void Print() const;

	//Date* operator&();

};

ostream& operator<<(ostream& out, const Date& d);

istream& operator>>(istream& in, Date& d);
