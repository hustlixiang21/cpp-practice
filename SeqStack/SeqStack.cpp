//
// Created by lixiang on 2022/9/13.
//

#include "SeqStack.h"

template <class T>
SeqStack<T>::SeqStack(int size)
{
    top = -1;
    maxSize = size;
    elements = new T[maxSize];
    assert(elements);
}

template <class T>
void SeqStack<T>::overflowProcess()
{
    //私有函数：当栈满则执行扩充栈存储空间处理
    T *newArray = new T[maxSize + stackIncreament];
    assert(newArray); //创建更大的存储数组
    for (int i = 0; i <= top; i++)
        newArray[i] = elements[i];
    maxSize += stackIncreament;
    delete[] elements;
    elements = newArray; //改变elements指针
}

template <class T>
void SeqStack<T>::push(const T &x)
{
    if (isFull())
        overflowProcess();
    element[++top] = x;
}

template <class T>
bool SeqStack<T>::pop(T &x)
{
    //函数退出栈顶元素并返回栈顶元素的值
    if (IsEmpty())
        return false;
    x = elements[top--]; //栈顶指针退1
    return true;         //退栈成功
}

template <class T>
bool getTop(T &x)
{
    if (IsEmpty())
        return false;
    x = elements[top];
    return true;
}
