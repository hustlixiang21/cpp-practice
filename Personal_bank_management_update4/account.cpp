//
// Created by lixiang on 2022/8/27.
//

#include "account.h"
#include <utility>
using namespace std::rel_ops;

// Account类的实现
double Account::total = 0;

Account::Account(const Date &date, const string &id) : id(id), balance(0)
{
    date.show();
    cout << "\t#" << id << "\t"
         << "created" << endl;
}

void Account::record(const Date &date, double amount, const string &desc)
{
    amount = floor(amount * 100 + 0.5) / 100; //保留小数点后两位，符合四舍五入原则
    balance += amount;
    total += amount;
    recordMap.insert(make_pair(date,AccountRecord(date,this,amount,balance,desc)));
    date.show();
    cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}
void Account::record(const Date &date, double amount, const string &desc, int)
{
    amount = floor(amount * 100 + 0.5) / 100; //保留小数点后两位，符合四舍五入原则
    balance += amount;
    recordMap.insert(make_pair(date,AccountRecord(date,this,amount,balance,desc)));
    date.show();
    cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}

void Account::error(const string &msg) const
{
    cout << "Error(#" << id << "): " << msg << endl;
}

void Account::show() const
{
    cout << "\t#" << id << "\tBalance: " << balance << endl;
}

// SavingsAccount类的实现

SavingsAccount::SavingsAccount(const Date &date, const string &id, double rate) : Account(date, id), rate(rate), acc(date, 0) {}

void SavingsAccount::withdraw(const Date &date, double amount, const string &desc)
{
    //先判断能不能取的出来
    if (amount > getBalance())
    {
        error("not enough money");
    }
    else
    {
        record(date, -amount, desc);
        acc.change(date, getBalance());
    }
}

void SavingsAccount::deposit(const Date &date, double amount, const string &desc)
{
    record(date, amount, desc);
    acc.change(date, getBalance());
}

void SavingsAccount::settle(const Date &date)
{
    //计算年利息 每年的一月计算一次利息
    if (date.getMonth() == 1)
    {
        double interest = acc.getSum(date) * rate / (date - Date(date.getYear() - 1, 1, 1)); //日累计总和除以当年的长度
        if (interest != 0)
            record(date, interest, "interest");
        acc.reset(date, getBalance()); //千万不能忘记重置accumulator
    }
}

// CreditAccount类的实现

CreditAccount::CreditAccount(const Date &date, const string &id, double credit, double rate, double fee) : Account(date, id), credit(credit), rate(rate), fee(fee), acc(date, 0) {}

void CreditAccount::deposit(const Date &date, double amount, const string &desc)
{
    record(date, amount, desc);
    acc.change(date, getBalance());
}

void CreditAccount::withdraw(const Date &date, double amount, const string &desc)
{
    //先判断能不能取的出来
    if (amount - getBalance() > credit)
    {
        error("not enough credit");
    }
    else
    {
        record(date, -amount, desc);
        acc.change(date, getBalance());
    }
}

void CreditAccount::settle(const Date &date)
{
    double interest = acc.getSum(date) * rate;
    if (interest != 0)
        record(date, interest, "interest", 0);
    if (date.getMonth() == 1)
        record(date, -fee, "annual fee", 0);
    acc.reset(date, getDebt()); //千万不能忘记重置accumulator
}

void CreditAccount::show() const
{
    Account::show();
    cout << "\tAvailable credit:" << getAvailableCredit() << endl;
}

AccountRecord::AccountRecord(const Date &date, const Account *account, double amount, double balance,
                             string desc) : date(date), account(account), amount(amount), balance(balance), desc(std::move(desc)) {}

void AccountRecord::show() const
{
    date.show();
    cout << "\t#" << account->getId() << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}

RecordMap Account::recordMap;
void Account::query(const Date &begin, const Date &end)
{
    if (begin <= end)
    {
        auto iter1 = recordMap.lower_bound(begin);
        auto iter2 = recordMap.upper_bound(end);
        for (auto iter = iter1; iter != iter2; ++iter)
        {
            iter->second.show();
        }
    }
}