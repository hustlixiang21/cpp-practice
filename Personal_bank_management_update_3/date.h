//
// Created by lixiang on 2022/8/23.
//

#ifndef PERSONAL_BANK_MANAGEMENT_UPDATE_3_DATE_H
#define PERSONAL_BANK_MANAGEMENT_UPDATE_3_DATE_H


class Date
{
public:
    //构造函数
    Date(int year, int month, int day);

    //年月日的外部接口
    int getYear() const {return year;}
    int getMonth() const {return month;}
    int getDay() const {return day;}

    int getMaxDay() const; //获得当月有多少天
    bool isLeapYear() const  //判断是否是闰年
    {
        return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    }
    void show() const; //输出当前的日期

    //计算两个日期之间差多少天
    //可以直接重载"-"操作符
    int operator-(const Date &date) const{
        return (this -> totalDays - date.totalDays);
    }
    /*
    int distance(const Date &date) const
    {
        return totalDays - date.totalDays;
    }
    */
private:
    int year, month, day, totalDays;
};
#endif //PERSONAL_BANK_MANAGEMENT_UPDATE_3_DATE_H
