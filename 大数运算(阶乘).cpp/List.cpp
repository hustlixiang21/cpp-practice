//
// Created by lixiang on 2022/9/15.
//

#include "List.h"

ListNode *List::factorial(int n)
{
    for(int i = 2 ; i <= n; i++)
    {
        ListNode* ptr = head;
        int carry = 0;
        while(true)
        {
            ptr->n = ptr->n * i + carry;
            carry = ptr->n/1000;
            if(carry != 0 && ptr->next == nullptr) //到了最高位了
            {
                ListNode* temp = new ListNode{ptr, nullptr,0};
                ptr->next = temp;
                ptr->n %= 1000;
            }
            else if(carry != 0)
            {
                ptr->n %= 1000;
            }
            else if(ptr->next == nullptr)
            {
                break;
            }
            ptr = ptr->next;
        }
        tail = ptr;
    }
    return head;
}

void List::print_to_file(ListNode* ptr,int n) const
{
    ofstream fout;
    fout.open("output_file",ios::app);
    fout << "N=" << n << endl;
    int count = 0;
    for(ListNode* p = head ; p != nullptr ; p = p->next)
    {
        count++;
    }
    fout << "结点个数为:" << count << "\t";
    fout.fill('0');
    ListNode* p = tail;
    fout << "前十个结点为: ";
    for(int i = 0; p != nullptr && i < 10; i++,p = p->pre)
    {
        fout.width(3);
        fout << p->n << "->";
    }
    fout << endl;
    fout.close();
}

