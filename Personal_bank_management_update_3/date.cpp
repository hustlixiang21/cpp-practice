//
// Created by lixiang on 2022/8/23.
//

#include "date.h"
#include <iostream>
#include <cstdlib>
using namespace std;

namespace
{   //这种直接把总和写出来的方法简直巧妙
    const int DAYS_BEFORE_MONTH[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334,365};
}

Date::Date(int year, int month, int day) : year(year), month(month), day(day)
{
    if (day <= 0 || day > getMaxDay() )
    {
        cout << "Invalid date:";
        show();
        cout << endl;
        exit(1); //终止程序返回1
    }
    int years = year - 1;  //选择 1年1月1日为基准，计算总的天数
    totalDays = years * 365 + years / 4 - years / 100 + years / 400 + DAYS_BEFORE_MONTH[month - 1] + day;
    if (isLeapYear() && month > 2)
        totalDays++;
}
int Date::getMaxDay() const
{
    if (isLeapYear() && month == 2)
        return 29;
    else
        return DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month - 1];
}

void Date::show() const
{
    cout << getYear() << "-" << getMonth() << "-" << getDay();
}




