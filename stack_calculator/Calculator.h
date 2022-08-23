//
// Created by lixiang on 2022/8/22.
//

#ifndef STACK_CALCULATOR_CALCULATOR_H
#define STACK_CALCULATOR_CALCULATOR_H
#include "Stack.h"

class Calculator
{
private:
    Stack<double> s;        //操作数栈
    void enter(double num); //将操作数压入栈中
    //连续弹出两个操作数，放在opnd1和opnd2中
    bool getTwoOperands(double &opnd1, double &opnd2);
    void compute(char op); //执行指定的运算
public:
    void run();   //运行计算机程序
    void clear(); //清空操作数栈
};

#endif // STACK_CALCULATOR_CALCULATOR_H
