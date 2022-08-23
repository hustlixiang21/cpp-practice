//
// Created by lixiang on 2022/8/2.
//

#ifndef PERSONAL_BANK_MANAGEMENT_UPDATE_2_ACCOUNT_H
#define PERSONAL_BANK_MANAGEMENT_UPDATE_2_ACCOUNT_H

#include <iostream>
#include "accumulator.h"
#include <cmath>
using namespace std;

class Account
{
public:
    const string &getId() const { return id; }    // id的外部接口
    double getBalance() const { return balance; } //余额的外部接口
    static double getTotal() { return total; }    //各余额总和total的外部接口
    virtual void deposit(const Date &date, double amount, const string &desc) = 0;
    virtual void withdraw(const Date &date, double amount, const string &desc) = 0;
    virtual void settle(const Date &date) = 0;
    virtual void show() const; //显示账户信息
protected:
    Account(const Date &date, const string &id);                      //构造函数传，引用效率更高
    void record(const Date &date, double amount, const string &desc); //记录每一笔支出或者收入
    void record(const Date &date, double amount, const string &desc,int); //欠利息的时候total并没有减少
    void error(const string &msg) const;                              //用于账户的报错
private:
    string id;           //账户id
    double balance;      //账户余额
    static double total; //所有账户的余额总和，静态变量不属于任何对象
};

class SavingsAccount : public Account
{ //储蓄账户派生类
public:
    SavingsAccount(const Date &date, const string &id, double rate);
    double getRate() const { return rate; }                             //年利率的外部接口
    void deposit(const Date &date, double amount, const string &desc) override;  //存钱
    void withdraw(const Date &date, double amount, const string &desc) override; //取钱
    void settle(const Date &date) override;                                      //结算利息，每年1月1日调用该函数
private:
    Accumulator acc; //辅助计算利息的累加器
    double rate;     //存款的年利率
};

class CreditAccount : public Account
{
public:
    CreditAccount(const Date &date, const string &id, double credit, double rate, double fee);
    double getCredit() const { return credit; }
    double getRate() const { return rate; }
    double getFee() const { return fee; }
    double getAvailableCredit() const
    {
        if (getBalance() < 0)
            return credit + getBalance();
        else
            return credit;
    }
    void deposit(const Date &date, double amount, const string &desc) override;  //存钱
    void withdraw(const Date &date, double amount, const string &desc) override; //取钱
    void settle(const Date &date) override;                                      //结算利息，每月1日调用该函数
    void show() const override;

private:
    Accumulator acc;
    double credit;
    double rate;
    double fee;
    double getDebt() const
    {
        double balance = getBalance();
        return (balance < 0 ? balance : 0);
    }
};

#endif // PERSONAL_BANK_MANAGEMENT_UPDATE_1_ACCOUNT_H
