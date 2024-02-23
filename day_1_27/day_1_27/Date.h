//this file is "Date.h"
#pragma once 


#include<iostream>
using namespace std;

class Date
{
public:
	Date();
	void Init(int year, int month, int day);
	void print();

private:
	int _year;
	int _month;
	int _day;

};