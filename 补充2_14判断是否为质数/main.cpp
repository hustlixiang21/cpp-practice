#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a,isprime = 0;
    cout << "请输入一个整数正整数a:" <<endl;
    cin >> a ;
    if (a<2)
        cout << "请检查你输入的数字" <<endl;
    if (a==2)
        cout << "该数不是质数" <<endl;
    else
    {
        for(int i=2 ; i <= sqrt(a) ; i++)
        {
            if (a%i == 0)
            {
                isprime = 1;
                break;
            }
        }
    }
    if (isprime == 1)
        cout << a << "不是质数" <<endl;
    else
        cout << a << "是质数" << endl;
    return 0;
}
