#include <iostream>
#include "account.h"
using namespace std;

int main()
{
    Date date(2008, 11, 1);   //起始日期
    //创建几个用户
    SavingsAccount sa1(date, "037219837", 0.015);
    SavingsAccount sa2(date, "128423091", 0.015);
    CreditAccount ca(date,"492837823",10000,0.0005,50);

    // 11月的几笔账目
    sa1.deposit(Date(2008, 11, 5), 5000, "salary");
    sa2.deposit(Date(2008, 11, 25), 10000, "sell stock 0323");
    ca.withdraw(Date(2008,11,15),2000,"buy a cell");

    //结算信用卡
    ca.settle(Date(2008,12,1));

    // 12月的几笔账目
    ca.deposit(Date(2008,12,1),2016,"repay the credit");
    sa1.deposit(Date(2008, 12, 5), 5500, "salary");
    cout << endl;

    //结算所有的账户
    sa1.settle(Date(2009,1,1));
    sa2.settle(Date(2009,1,1));
    ca.settle(Date(2009,1,1));
    cout << endl;

    //输出各个账户的信息
    sa1.show(); cout << endl;
    sa2.show(); cout << endl;
    ca.show(); cout << endl;
    cout << "Total: " << SavingsAccount::getTotal() << endl;
    return 0;

}
