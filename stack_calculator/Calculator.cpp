#include "Calculator.h"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

//工具函数，用于将字符串转化为实数
inline double stringToDouble(const string &str)
{
    istringstream stream(str);
    double result;
    stream >> result;
    return result;
}

void Calculator::enter(double num)
{
    s.push(num);
}

bool Calculator::getTwoOperands(double &opnd1, double &opnd2)
{
    if (s.isEmpty())
    {
        cerr << "Missing operand!" << endl;
        return false;
    }
    opnd1 = s.pop();
    if (s.isEmpty())
    {
        cerr << "Missing operand!" << endl;
        return false;
    }
    opnd2 = s.pop();
    return true;
}

void Calculator::compute(char op)
{
    //执行运算
    double operand1, operand2;
    bool result = getTwoOperands(operand1, operand2);
    if (result)
    { //如果成功，执行运算并将运算结果压入栈
        switch (op)
        {
        case '+':
            s.push(operand2 + operand1);
            break;
        case '-':
            s.push(operand2 - operand1);
            break;
        case '*':
            s.push(operand2 * operand1);
            break;
        case '/':
            if (operand1 == 0)
            { //检查除数是否为0
                cerr << "Divided by 0!" << endl;
                s.clear(); //除数为0时清空栈
            }
            else
                s.push(operand2 / operand1);
            break;
        case '^':
            s.push(pow(operand2, operand1));
            break;
        default:
            cerr << "Unrecognized operator!" << endl;
            break;
        }
        cout << "= " << s.peek() << " "; //输出本次运算结果
    }
    else
        s.clear(); //操作数不够，清空栈
}

void Calculator::run()
{

    //读入并处理后缀表达式
    string str;
    while (cin >> str, str != "q")
    {
        switch (str[0])
        {
        case 'c':
            s.clear();
            break;
        case '-': //遇'-'需判断是减号还是负号
            if (str.size() > 1)
                enter(stringToDouble(str));
            else
                compute(str[0]);
            break;
        case '+': //遇到其它操作符时
        case '*':
        case '/':
        case '^':
            compute(str[0]);
            break;
        default: //若读入的是操作数，转换为整型后压入栈
            enter(stringToDouble(str));
            break;
        }
    }
}

void Calculator::clear()
{
    s.clear();
}
