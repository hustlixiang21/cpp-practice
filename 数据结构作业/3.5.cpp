/*
写出使用队列、栈两种数据结构来判断字符序列是否为回文序列的算法。（例如'abba' 与'abcba'都是回文。）

1）使用队列来判断的算法

2）使用栈来判断的算法
*/
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

bool stack_judge(string &str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }
    for (int i = 0; i < str.length() / 2; i++)
    {
        if (s.top() != str[i])
            return false;
        s.pop();
    }
    return true;
}
bool queue_judge(string &str)
{
    queue<char> q;
    for (int i = 0; i < str.length(); i++)
    {
        q.push(str[i]);
    }
    for (int i = str.length() - 1; i > str.length() / 2; i--)
    {
        if (q.front() != str[i])
            return false;
        q.pop();
    }
    return true;
}

int main()
{
    string buf;
    cout << "请输入一个字符串用于判断是否为回文 串：" << endl;
    cin >> buf;
    if (stack_judge(buf))
    {
        cout << "Stack_Judge is Successful!" << endl;
    }
    else
    {
        cout << "Stack_Judge Failed!" << endl;
    }
    if (queue_judge(buf))
    {
        cout << "Queue_Judge is Successful!" << endl;
    }
    else
    {
        cout << "Queue_Judge Failed!" << endl;
    }
    return 0;
}