#include"Date.h" 

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
	if (!CheckInvalid())
	{
		_year = 2020;
		_month = 1;
		_day = 1;
	}
}

Date& Date:: operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

bool Date::operator<(const Date &d2) const
{
	if (_year < d2._year)
		return true;
	else if (_year == d2._year && _month < d2._month)
		return true;
	else if (_year == d2._year && _month == d2._month && _day < d2._day)
		return true;
	return false;
}

bool Date::operator<=(const Date&d2) const
{
	return *this < d2 || *this == d2;
}

bool Date::operator>(const Date &d2) const
{
	return !(*this <= d2);
}

bool Date::operator>=(const Date &d2) const
{
	return *this > d2 || *this == d2;
}

bool Date::operator==(const Date &d2) const
{
	return _year == d2._year 
		&& _month == d2._month 
		&& _day == d2._day;
}

bool Date::operator!= (const Date &d2) const
{
	return !(*this == d2);
}

Date& Date::operator+=(int day)
{
	
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp+=day;
	return tmp;
}

Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}

int Date::operator-(const Date d2) const
{
	int flag = 1;
	Date max = *this;
	Date min = d2;
	if (max < min)
	{
		flag = -1;
		max = d2;
		min = *this;
	}
	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}
	return flag * n;
}

bool Date::CheckInvalid()
{
	if (_year < 0
		||_month<1
		||_month>12
		||_day<1
		||_day>GetMonthDay(_year,_month))
		return false;

	return true;
}


ostream& operator<<(ostream& out, const Date& d)
{
	 out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	 return out;
}

istream& operator>>(istream& in, Date& d)
{
	while (1)
	{
		cout << "请输入年月日" << endl;
		in >> d._year >> d._month >> d._day;
		if (!d.CheckInvalid())
		{
			cout << "输入非法，请重新输入日期" << endl;
		}
		else
			break;
	}
	return in;
}

void Date::Print() const
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

