//
// Created by lixiang on 2022/9/13.
//

#ifndef SEQSTACK_SEQSTACK_H
#define SEQSTACK_SEQSTACK_H
#define stackIncreament 20

template <class T>
class SeqStack{
private:
    T *elements; //栈元素存放数组
    int top;     //栈顶指针
    int maxSize  //栈的最大容量
    void overflowProcess(); //溢出处理

public:
    SeqStack(int size = 50);
    ~SeqStack() { delete[] elements; }
    void push(const T &x);
    bool pop(T &x);
    bool getTop(T &x);
    bool isEmpty() const { return top == -1; }
    bool isFull() const { return top == maxSize - 1; }
    void MakeEmpty() { top = -1; }
    friend ostream &operator<<(ostream &out, SeqStack<T> &s);
};

#endif // SEQSTACK_SEQSTACK_H
