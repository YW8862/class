#include"Date.h"


void Date::Init(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}
void Date::print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

Date::Date()
{
	_year = 2023;
	_month = 12;
	_day = 1;
}