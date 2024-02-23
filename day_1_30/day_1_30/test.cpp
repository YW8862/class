#include<iostream>
using namespace std;
class Date
{
private:
	int _year;
	int _month;
	int _day;

public:
	Date(int year=2024,int month=1,int day=1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	~Date()
	{

	}
	
};


int main()
{
	Date x;
	x.print();
	return 0;
}