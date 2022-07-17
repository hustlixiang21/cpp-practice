#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a,b,temp,i=0,x=1;
    cout << "请输入两个正整数:"<< endl;
    cin >> a >> b;
    if (a<1 || b<1)
    {
        cout << "请确认输入的是两个正整数" << endl;
        return 0;
    }
    while(a%2==0 && b%2==0) //计算a,b能被多少个2整除，用i来存储次数
    {
        a/=2;
        b/=2;
        i+=1;
    }
    if(a<b) //用a来保存大的值
    {
        temp = a;
        a = b;
        b = temp;
    }
    while(x)
    {
        x = a - b;
        a = (b>x)? b:x; //a是差和减数中较大的那个
        b = (b<x)? b:x; //b是差和减数中较小的那个
        if (b==(a-b)) //当减数和差相等时结束循环这个值称之为等数
            break;
    }
    if (i==0)
        cout << "最大公约数为：" << b << endl;
    else
        cout << "最大公约数为：" << (int)pow(2,i)*b << endl; //最后结果是等数乘以2^i
    return 0;
}
/*int main()
{
    int a,b,temp;
    cout << "请输入两个正整数:"<< endl;
    cin >> a >> b;
    if (a<1 || b<1)
    {
        cout << "请确认输入的是两个正整数" << endl;
        return 0;
    }
    if(a<b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    temp = a%b;
    while(temp != 0)
    {
        a = b;
        b = temp;
        temp = a%b;
    }
    cout << "最大公约数为：" << b << endl;
    return 0;
}*/
/*int main()
{
    int a,b,gcd;
    cout << "请输入两个正整数:"<< endl;
    cin >> a >> b;
    if (a<1 || b<1)
    {
        cout << "请确认输入的是两个正整数" << endl;
        return 0;
    }
    gcd = a < b ? a : b;
    for ( ; gcd >0 ; gcd--)
    {
        if(a%gcd==0 && b%gcd==0)
        {
            break;
        }
    }
    cout << "最大公约数为："<< gcd << endl;
    return 0;
}*/
/*int main()
{
    int a,b,flag=0;
    cout << "请输入两个正整数:";
    cin >> a >> b;
    for (int i = ( a > b ) ? b : a ; i > 0 && flag == 0 ; i--)
    {
        if(a%i == 0&& b%i==0)
        {
            cout << i;
            flag = 1;
        }
    }
    return 0;
}*/
// 最后一个是自己写的
