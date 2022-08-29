//
// Created by lixiang on 2022/8/29.
//

#ifndef PERSONAL_BANK_MANAGEMENT_UPDATE5_ACCOUNT_H
#define PERSONAL_BANK_MANAGEMENT_UPDATE5_ACCOUNT_H

#include "accumulator.h"
#include <map>
#include <cmath>
#include <utility>
#include <istream>

using namespace std;

class Account; //前置声明
class AccountRecord
{
private:
    Date date;              //日期
    const Account *account; //账户
    double amount;          //金额
    double balance;         //余额
    string desc;            //描述
public:
    AccountRecord(const Date &date, const Account *account, double amount, double balance, string desc);
    void show() const;
};

//定义用来存储账目记录的多重映射类型
typedef multimap<Date, AccountRecord> RecordMap;

class Account
{
public:
    const string &getId() const { return id; }    // id的外部接口
    double getBalance() const { return balance; } //余额的外部接口
    static double getTotal() { return total; }    //各余额总和total的外部接口
    virtual void deposit(const Date &date, double amount, const string &desc) = 0;
    virtual void withdraw(const Date &date, double amount, const string &desc) = 0;
    virtual void settle(const Date &date) = 0;
    virtual void show(ostream &out) const;                             //显示账户信息
    virtual ~Account() = default;                          //声明虚析构函数实现动态绑定
    static void query(const Date &begin, const Date &end); //查询指定时间内账户的信息

protected:
    Account(const Date &date, const string &id);                           //构造函数传，引用效率更高
    void record(const Date &date, double amount, const string &desc);      //记录每一笔支出或者收入
    void record(const Date &date, double amount, const string &desc, int); //欠利息的时候total并没有减少
    void error(const string &msg) const;                                   //用于账户的报错
private:
    string id;                  //账户id
    double balance;             //账户余额
    static double total;        //所有账户的余额总和，静态变量不属于任何对象
    static RecordMap recordMap; //账目记录
};

class SavingsAccount : public Account
{ //储蓄账户派生类
public:
    SavingsAccount(const Date &date, const string &id, double rate);
    ~SavingsAccount() = default;
    double getRate() const { return rate; }                                      //年利率的外部接口
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
    ~CreditAccount() = default;
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
    void show(ostream &out) const override;

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

inline ostream & operator<<(ostream &out , const Account &account){
    account.show(out);
    return  out;
}
#endif // PERSONAL_BANK_MANAGEMENT_UPDATE5_ACCOUNT_H
