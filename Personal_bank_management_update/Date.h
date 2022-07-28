#ifndef _CPP_DATE_H_
#define _CPP_DATE_H_

class Date
{
public:
    Date(int year, int month, int day);
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getMaxDay() const; //获得当月有多少天
    bool isLeapYear() const
    {
        return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    }
    void show() const; //输出当前的日期
    int distance(const Date &date) const
    { //计算两个日期之间差多少天
        return totalDays - date.totalDays;
    }

private:
    int year, month, day, totalDays;
};

#endif