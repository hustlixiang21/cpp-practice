//
// Created by lixiang on 2022/9/14.
//

#include "List.h"
using namespace std;
ofstream fout;
void List::putin(int n)
{
    for (int i = 2; i <= n; i++) {
        LinkNode* prev = first;
        while (prev!= last) {
            if (prev->down_data + prev->next->down_data <= i) {    //判断条件：分母小于n
                LinkNode* temp = new LinkNode(prev->up_data + prev->next->up_data, prev->down_data + prev->next->down_data);//法雷序列的性质4
                temp->next = prev->next;
                prev->next = temp;
                prev = temp->next;//将新节点插入到链表中
            }
            else prev = prev->next;
        }
    }
}

void List::print(int n) {
    fout.open("Farry_test.txt",ios::app);
    output(first,n);
    fout.close();
}
void output(LinkNode* l,int n) {
    int i;
    for (i = 0; l!= nullptr; ++i,l=l->next);
    fout << n << "级法雷序列有" << i << "个结点" << endl;
}