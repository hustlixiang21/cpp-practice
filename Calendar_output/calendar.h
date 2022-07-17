//
// Created by lixiang on 2022/7/17.
//

#ifndef CALENDAR_OUTPUT_CALENDAR_H
#define CALENDAR_OUTPUT_CALENDAR_H

#include <bits/stdc++.h>
using namespace std;
int is_run[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
int not_run[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int flag=0;

int calculate(int year,int month);

bool is_leap(int year);

void output(int remainder,int month);

int calculate(int year,int month)
{
    int sum_of_days=1;
    if(is_leap(year))
    {
        flag = 1;
        for(int i=1;i<month;i++) sum_of_days+=is_run[i];
        return ((year-1)+(year-1)/4-(year-1)/100+(year-1)/400+sum_of_days)%7;
    }
    else
    {
        for(int i=1;i<month;i++) sum_of_days+=not_run[i];
        return ((year-1)+(year-1)/4-(year-1)/100+(year-1)/400+sum_of_days)%7;
    }
}

bool is_leap(int year)
{
    if((year%4==0&&year%100!=0)||year%400==0) return true;
    else return false;
}

void output(int remainder,int month)
{
    if(flag)
    {
        cout << "——————————————————————————————" << endl;
        cout << "| Sun Mon Tue Wed Thr Fri Sat｜" << endl;
        cout << "| ";
        for(int j=0;j<remainder;j++)
        {
            cout << "    ";
        }
        for(int i=1;i<=is_run[month];i++,remainder++)
        {
            if(remainder%7==0){
                cout << "|" << endl;
                cout << "| ";
                remainder=0;
            }
            cout << setw(3) << i << " ";
        }
        for(;remainder<7;remainder++)
        {
            cout << "    ";
        }
        cout << "|" << endl;
        cout << "——————————————————————————————" << endl;
    }
    else
    {
        cout << "——————————————————————————————" << endl;
        cout << "| Sun Mon Tue Wed Thr Fri Sat |" << endl;
        cout << "| ";
        for(int j=0;j<remainder;j++)
        {
            cout << "    ";
        }
        for(int i=1;i<=not_run[month];i++,remainder++)
        {
            if(remainder%7==0){
                cout << "|" << endl;
                cout << "| ";
                remainder=0;
            }
            cout << setw(3) << i << " ";
        }
        for(;remainder<7;remainder++)
        {
            cout << "    ";
        }
        cout << "|" << endl;
        cout << "——————————————————————————————" << endl;

    }

}

#endif //CALENDAR_OUTPUT_CALENDAR_H
//函数需求分析
//有根据年月日推算是星期几的公式，为函数calculate
//判断是否是闰年，从而二月份是不同的，需要函数is_leap，设置两个数组
//日历需要输出，有日历输出函数,函数output