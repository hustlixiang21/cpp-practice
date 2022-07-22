#ifndef _CPP_ACCOUNT_H
#define _CPP_ACCOUNT_H

class SavingsAccount
{
public:
    SavingsAccount(int date, int id, double rate);
    int getId() const {return id;}
    double getBalance() const {return balance;}
    double getRate() const {return rate;}
    static double getTotal(){return total;}      //静态成员变量最好通过一个静态成员函数来访问
    void deposit(int date, double amount);
    void withdraw(int date, double amount);
    void settle(int date);    //结算函数
    void show() const;

private:
    int id;              //账号
    double balance;      //余额
    double rate;         //存款的年利率
    int lastDate;        //上次变更余额的日期
    double accumulation; //余额按日累加之和
    static double total; //所有账户的总金额
    void record(int date, double amount);
    double accumulate(int date) const { return accumulation + balance * (date - lastDate); }
};


#endif