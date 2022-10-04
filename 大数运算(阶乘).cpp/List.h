//
// Created by lixiang on 2022/9/15.
//

#ifndef ___CPP_LIST_H
#define ___CPP_LIST_H

#include <iostream>
#include <fstream>

using namespace std;
struct ListNode
{
    ListNode* pre;
    ListNode* next;
    int n;         //表示[0, 999]的数
};

class List{
public:
    ListNode* head = new ListNode{nullptr, nullptr,1};
    ListNode* tail = nullptr;
    ListNode* factorial(int n);
    void print_to_file(ListNode* ptr,int n) const;
};


#endif //___CPP_LIST_H
