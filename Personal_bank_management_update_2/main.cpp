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
    Account * accounts[] {&sa1,&sa2,&ca};
    const int n = sizeof(accounts) / sizeof(accounts[0]);
    cout << "(d)deposit (w)withdraw (s)show (c)change day (n) next month e(exit)" << endl;
    char cmd;
    do{
        date.show();
        cout << "\tTotal:" << Account::getTotal() << " \tcommand>";
        int index,day;
        double amount;
        string desc;
        cin >> cmd;
        switch (cmd) {
            case 'd':
                cin >> index >> amount;
                getline(cin,desc);
                accounts[index] -> deposit(date,amount,desc);
                break;
            case 'w':
                cin >> index >> amount;
                getline(cin,desc);
                accounts[index] -> withdraw(date,amount,desc);
                break;
            case 's':
                for(int i = 0; i < n; i++)
                {
                    cout << "[" << i << "]";
                    accounts[i] -> show();
                    cout << endl;
                }
                break;
            case 'c':
                cin >> day;
                if (day < date.getDay())
                    cout << "You can't specify a previous day";
                else if(day > date.getMaxDay())
                    cout << "Invalid day";
                else date = Date(date.getYear(),date.getMonth(),day);
                break;
            case 'n':
                if(date.getMonth()==12)
                    date = Date(date.getYear()+1,1,1);
                else
                    date = Date(date.getYear(),date.getMonth()+1,1);
                for(auto & account : accounts)
                {
                    account -> settle(date);
                }
                break;
            default:
                break;
        }

    } while (cmd!='e');
    return 0;
}
