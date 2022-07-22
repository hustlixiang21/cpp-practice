#include <iostream>
#include "account.h"

using namespace std;

int main()
{
    //建立几个账户
    SavingsAccount sa0(1,21325302,0.015);
    SavingsAccount sa1(1,21325302,0.015);
    //几笔账目
    sa0.deposit(5,5000);
    sa1.deposit(25,10000);
    sa0.deposit(45,5500);
    sa1.withdraw(60,4000);
    //开户后第90天到了银行的记息日，结算所有的账户年息
    sa0.settle(90);
    sa1.settle(90);
    //输出各个账户的信息
    sa0.show();
    sa1.show();
    cout << "Total:" << SavingsAccount::getTotal() << endl;
    return 0;
}
