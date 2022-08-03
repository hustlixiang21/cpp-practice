//
// Created by lixiang on 2022/8/2.
//

#ifndef PERSONAL_BANK_MANAGEMENT_UPDATE_1_ACCOUNT_H
#define PERSONAL_BANK_MANAGEMENT_UPDATE_1_ACCOUNT_H

#include <iostream>
#include "accumulator.h"
#include <cmath>
using namespace std;

class Account {
public:
    const string &getId() const {return id;}     //id的外部接口
    double getBalance() const {return balance;}  //余额的外部接口
    static double getTotal() {return total;}     //各余额总和total的外部接口
    void show() const;  //显示账户信息
protected:
    Account(const Date &date,const string &id); //构造函数传，引用效率更高
    void record(const Date &date,double amount,const string &desc); //记录每一笔支出或者收入
    void error(const string &msg) const; //用于账户的报错
private:
    string id;               //账户id
    double balance;          //账户余额
    static double total;     //所有账户的余额总和，静态变量不属于任何对象
};

class SavingsAccount : public Account{   //储蓄账户派生类
public:
    SavingsAccount(const Date &date,const string &id, double rate);
    double getRate() const {return rate;}   //年利率的外部接口
    void deposit(const Date &date, double amount,const string &desc); //存钱
    void withdraw(const Date &date, double amount, const string &desc); //取钱
    void settle(const Date &date);   //结算利息，每年1月1日调用该函数
private:
    Accumulator acc;   //辅助计算利息的累加器
    double rate;       //存款的年利率
};

class CreditAccount : public Account{

};

#endif //PERSONAL_BANK_MANAGEMENT_UPDATE_1_ACCOUNT_H
