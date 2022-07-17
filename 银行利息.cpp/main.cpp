/*【问题描述】
定义一个银行账号，包括户主(string)和账户金额属性，并关联银行利息。输入储蓄年数，计算账号金额数。
假定下一年利率为上一年利率的95%。
【输入形式】
户主    账户金额    存款利率%    储蓄年数
【输出形式】
户主    账户金额
【样例输入】
Wang    10000    3.5    10
【样例输出】
Wang    13190.8*/
#include <iostream>
#include <string>
using namespace std;
class account
{
public:
 void set_account(string name ,double balance = 0,double rates = 0,int year = 0);
 void show_account();
 double calculate_balance();
private:
 string m_name;
 double m_balance;
 double m_rates;
 int m_year;
};

void account::set_account(string name , double balance , double rates, int year)
{
    m_name = name;
    m_balance = balance;
    m_rates = rates;
    m_year = year;
}
void account::show_account()
{
    cout << m_name << "\t" << m_balance;
}
double account::calculate_balance()
{
    for(int i=0;i < m_year; i++)
    {
        m_balance = m_balance*(1 + m_rates*0.01);
        m_rates *= 0.95; //每年利率都会变，第一年是原来的所以放在后面
    }
    return m_balance;
}

int main()
{
    string name;
    double balance, rates;
    int year;//定义所需初始变量
    account my_account;//定义对象名
    cin >> name>> balance >> rates >> year; // 将对应变量读入
    my_account.set_account(name , balance , rates ,year); //进行变量的初始化
    my_account.calculate_balance();//计算最后钱
    my_account.show_account();//显示最后的账户信息
    return 0;
}

// 我发现你很重要的一个问题就是成员函数里的东西用的是个糊的。大多数情况下，使用类内定义的变量进行计算，也就是你这个private定义的变量。
// 也可以直接使用形参计算（当然前提是你的成员函数定义了形参），这些形参一般是类外的变量（因为类内的成员函数可以直接访问），最后计算结果
// 可以返回给类内的变量以达到将结果存储（当然也可以返回给一个类外变量，但是其实这样做这个函数就和类脱去了关系，虽定义在类内，其实就是一般的函数）
// 不建议像我说的最后那一种做法。