//
// Created by YANGWEI on 24-12-16.
//

#ifndef DAY_0913_DATE_H
#define DAY_0913_DATE_H
#include <iostream>
#include <vector>
using namespace std;

namespace myClass
{
    class Date{
    private:
        int _year;
        int _month;
        int _day;
        vector<int>days = {31,28,31,30,31,30,31,31,30,31,30,31};
    public:
        //构造函数
        explicit Date(int year = 2024,int month = 12,int day = 16):_year(year),_month(month),_day(day){}
        Date(Date&date) = default;
        //打印日期
        void print() const
        {
            cout<< this->_year<<"年"<< this->_month<<"月"<< this->_day<<"日"<<endl;
        }

        int operator -(Date date) const
        {
            int sym = 1;
            int retday = 0;
            if (date._year > this->_year
                ||(date._year == this->_year && date._month > this->_month)
                ||((date._year == this->_year) && date._month == this->_month && date._day > this->_day))
                sym = -1;
            //加上年
            for(int y = this->_year;y< date._year;y++)
            {
                retday += 365;
                if(isLeap(y))
                    retday += 1;
            }
            //加上月
            for(int m = this->_month;m<date._month;m++)
            {
                retday += getday(date._year,m);
            }
            //加上日
            retday += (this->_day - date._day);
            return sym*retday;
        }
        //获取某个月的天数
        int getday(int year,int month) const
        {
            if(month == 2 && isLeap(year))
            {
                return 29;
            }
            return days[month];
        }

        static bool isLeap(int year)
        {
            return !((year%4!=0)||(year%100==0&&year%400!=0));
        }
    };

} // myClass

#endif //DAY_0913_DATE_H
