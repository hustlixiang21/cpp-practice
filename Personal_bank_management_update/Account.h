#ifndef _CPP_ACCOUNT_H
#define _CPP_ACCOUNT_H

#include <string>
#include "Date.h"
using namespace std;

class SavingsAccount
{
public:
    SavingsAccount(const Date &date, const string &id, double rate);
    const string &getId() const { return id; } //声明了一个常成员函数，目的是不能用来修改数据成员的值，返回的又是一个常引用，目的是节省空间开销且防止通过引用修改值
    double getBalance() const { return balance; }
    double getRate() const { return rate; }
    static double getTotal() { return total; } //静态成员变量最好通过一个静态成员函数来访问
    void deposit(const Date &date, double amount, const string &desc);
    void withdraw(const Date &datee, double amount, const string &desc);
    void settle(const Date &date); //结算函数
    void show() const;

private:
    string id;           //账号
    double balance;      //余额
    double rate;         //存款的年利率
    Date lastDate;       //上次变更余额的日期
    double accumulation; //余额按日累加之和
    static double total; //所有账户的总金额
    void record(const Date &date, double amount, const string &desc);
    void error(const string &date) const;
    double accumulate(const Date &date) const { return accumulation + balance * date.distance(lastDate); }
};

#endif