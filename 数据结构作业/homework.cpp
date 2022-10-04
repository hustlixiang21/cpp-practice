
#include <iostream>
using namespace std;
struct LinkNode
{
    int val;
    LinkNode *next;
    LinkNode(int x) : val(x), next(nullptr) {}
    LinkNode(int x, LinkNode *ptr) : val(x), next(ptr) {}
};

LinkNode *Reverse_Recursion(LinkNode *head)
{
    //递归实现链表的原地倒置
    if (head->next == nullptr || head == nullptr)
        return head; //递归结束的条件同时也防止是一个空表
    LinkNode *last = Reverse_Recursion(head->next);
    head->next->next = head;
    head->next = nullptr;
    return last;
}
LinkNode *Reverse_iteration(LinkNode *head)
{
    //迭代实现链表的原地倒置
    LinkNode *prev = nullptr; //需要三个指针才能实现倒置，否则会丢失
    LinkNode *cur = head;
    while (cur != nullptr)
    {
        LinkNode *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

// 2.19
// 分析：删除结点之前必须有前驱指针以保证连续
template <typename T>
LinkNode *del_Elem_in_range(LinkNode *head, T min, T max)
{
    //建立一个虚拟头结点防止特况的判断
    LinkNode *dummy = new LinkNode(-1, head);
    LinkNode *prev = dummy;
    LinkNode *cur = dummy->next;
    while (cur != nullptr && cur->val < max) //此处的条件判断其实可以简化，大于max的不用遍历了
    {
        if (cur->val > min)
        {
            prev->next = cur->next;
            delete cur;
            cur = prev->next;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }

    return head;
}
//
/*
循环队列的队尾位置为 rear，队列元素个数为 length。

1）队列满了的判断条件为（）

2）入队列的算法为（）

3）出队列的算法为（）
*/

//队列由数组实现,rear指向队列末尾

#include "stdio.h"
#include "stdlib.h"
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define MAXQSIZE 100

typedef int Status;
typedef char QElemType;
typedef struct
{
    QElemType *base; //初始化动态分配存储空间
    int front;       //队头指针
    int rear;        //队尾指针
} SqQueue;

Status InitQueue(SqQueue &Q);
//构造一个空循环队列Q
Status InitQueue(SqQueue &Q)
{
    Q.base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
    if (!Q.base)
        exit(OVERFLOW);
    Q.front = Q.rear = 0; //队头尾都指向0号元素
    return OK;
}

Status EnQueue(SqQueue &Q, QElemType e);
//插入元素e作为Q的新的队尾元素，入队
Status EnQueue(SqQueue &Q, QElemType e)
{
    if ((Q.rear + 1) % MAXQSIZE == Q.front)
        return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
    return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e);
//删除Q的队头元素，用e返回其值,出队
Status DeQueue(SqQueue &Q, QElemType &e)
{
    if (Q.front == Q.rear)
        return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return OK;
}
