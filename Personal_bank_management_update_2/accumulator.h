//
// Created by lixiang on 2022/8/2.
//

#ifndef PERSONAL_BANK_MANAGEMENT_UPDATE_1_ACCUMULATOR_H
#define PERSONAL_BANK_MANAGEMENT_UPDATE_1_ACCUMULATOR_H

#include "date.h"

//一个用于实现按日累加的类
class Accumulator{
public:
    Accumulator(const Date &date, double value) : lastDate(date),value(value),sum(0){}

    //用来计算到指定日期的累加结果的函数
    double getSum(const Date &date) const {return sum+value*(date-lastDate);};

    void change(const Date &date,double new_value)//用来在指定日期更改数值value
    {
        sum = getSum(date);
        lastDate = date;
        this -> value = new_value;
    }
    void reset(const Date &date,double new_value) //将累加器清零并重新设定初始日期
    {
        lastDate = date;
        sum = 0;
        this -> value = new_value;
    }

private:
    Date lastDate;  //被累加数值上次变更的日期
    double value;   //被累加数值当前值
    double sum;     //被累加数值到上次变更为止的按日累加总和
};




#endif //PERSONAL_BANK_MANAGEMENT_UPDATE_1_ACCUMULATOR_H


//最好不要在类的定义的文件里在直接定义成员函数，很容易发生重复定义