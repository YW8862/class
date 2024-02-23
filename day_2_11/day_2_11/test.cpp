#include<iostream>
using namespace std;


class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};

class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
		, _q(_n=1)
		, p((int*)malloc(sizeof(int)*10))
	{
		if (p == nullptr)
		{
			perror("malloc fail!");
		}
	}
private:
	int _year;
	int _month;
	int _day;
	int _n;
	int _q;
	int* p;
};

int main()
{

	return 0;
}