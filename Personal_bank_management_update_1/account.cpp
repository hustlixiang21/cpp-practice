//
// Created by lixiang on 2022/8/2.
//

#include "account.h"

using namespace std;

//Account类的实现
double Account::total=0;

Account::Account(const Date &date, const string &id) : id(id),balance(0)
{
    date.show();
    cout << "\t#" << id << "\t" << "created" <<endl;
}

void Account::record(const Date &date, double amount, const string &desc)
{
    amount = floor(amount*100+0.5)/100;   //保留小数点后两位，符合四舍五入原则
    balance += amount;
    total += amount;
    date.show();
    cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc <<endl;
}

void Account::error(const string &msg) const
{
    cout << "Error(#"<<id<<"): " << msg <<endl;
}

void Account::show() const
{
    cout << "\t#" << id << "\tBalance: " << balance << endl;
}

//SavingsAccount类的实现

SavingsAccount::SavingsAccount(const Date &date,const string &id, double rate) : Account(date,id),rate(rate),acc(date,0){}

void SavingsAccount::withdraw(const Date &date, double amount,const string &desc)
{
    //先判断能不能取的出来
    if(amount > getBalance())
    {
        error("not enough money");
    }
    else
    {
        record(date,-amount,desc);
        acc.change(date,getBalance());
    }
}

void SavingsAccount::deposit(const Date &date, double amount,const string &desc)
{
    record(date,amount,desc);
    acc.change(date,getBalance());
}

void SavingsAccount::settle(const Date &date)
{
    //计算年利息
    double interest = acc.getSum(date) * rate / date.distance(Date(date.getYear()-1,1,1));  //日累计总和除以当年的长度
    if(interest!=0)
        record(date,interest,"interest");
    acc.reset(date,getBalance()); //千万不能忘记重置accumulator
}

//CreditAccount类的实现

CreditAccount::CreditAccount(const Date &date, const string &id, double credit, double rate, double fee) : Account(date,id),credit(credit),rate(rate),fee(fee),acc(date,0) {}

void CreditAccount::deposit(const Date &date, double amount, const string &desc)
{
    record(date,amount,desc);
    acc.change(date,getBalance());
}

void CreditAccount::withdraw(const Date &date, double amount,const string &desc)
{
    //先判断能不能取的出来
    if(amount - getBalance() > credit)
    {
        error("not enough credit");
    }
    else
    {
        record(date,-amount,desc);
        acc.change(date,getBalance());
    }
}

void CreditAccount::settle(const Date &date)
{
    double interest = acc.getSum(date) * rate;
    if(interest!=0)
        record(date,interest,"interest");
    if(date.getMonth()==1)
        record(date,-fee,"annual fee");
    acc.reset(date,getDebt()); //千万不能忘记重置accumulator
}

void CreditAccount::show() const {
    Account::show();
    cout << "\tAvailable credit:" << getAvailableCredit() << endl;
}
