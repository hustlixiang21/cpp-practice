//
// Created by lixiang on 2022/8/22.
//

#ifndef STACK_CALCULATOR_STACK_H
#define STACK_CALCULATOR_STACK_H
#include <cassert>

//模版类的定义，SIZE为栈的大小
template <class T, int SIZE = 50>
class Stack
{
private:
    T list[SIZE]; //数组用于存放栈元素
    int top;      //栈顶位置，数组下标
public:
    Stack();                  //构造函数，初始化栈
    void push(const T &item); //压栈操作
    T pop();                  //出栈操作
    void clear();             //清空栈
    const T &peek() const;    //访问栈顶元素
    bool isEmpty() const;     //判断栈是否为空
    bool isFull() const;      //判断栈是否为满
};

template <class T, int SIZE>
Stack<T, SIZE>::Stack() : top(-1) {}

template <class T, int SIZE>
void Stack<T, SIZE>::push(const T &item)
{
    assert(!isFull());
    list[++top] = item;
}

template <class T, int SIZE>
T Stack<T, SIZE>::pop()
{
    assert(!isEmpty());
    return list[top--];
}

template <class T, int SIZE>
void Stack<T, SIZE>::clear()
{
    top = -1;
}

template <class T, int SIZE>
const T &Stack<T, SIZE>::peek() const
{
    assert(!isEmpty());
    return list[top];
}

template <class T, int SIZE>
bool Stack<T, SIZE>::isEmpty() const
{
    return top == -1;
}

template <class T, int SIZE>
bool Stack<T, SIZE>::isFull() const
{
    return top == SIZE - 1;
}
#endif // STACK_CALCULATOR_STACK_H
