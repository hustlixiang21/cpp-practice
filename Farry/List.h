//
// Created by lixiang on 2022/9/14.
//

#ifndef FARRY_LIST_H
#define FARRY_LIST_H

#include<iostream>
#include<fstream>
struct LinkNode {
    int up_data,down_data;
    LinkNode* next;
    LinkNode(LinkNode* ptr = nullptr) { next = ptr; }
    LinkNode(const int& item,const int& item2, LinkNode* ptr = nullptr)
    {
        up_data = item;//分子
        down_data = item2;//分母
        next = ptr;
    }//节点
};
class List
{
private:
    LinkNode* first;//头指针
    LinkNode* last;//尾指针
public:
    List() {
        first = new LinkNode(0, 1);
        last = new LinkNode(1, 1);
        first->next = last;
    }//初始化为0/1和1/1
    void putin(int n);//主要步骤
    void print(int n);//输出到文件
};
void output(LinkNode *l, int i);


#endif //FARRY_LIST_H
