//寻找并且输出11——999间的数m使得m，m^2，m^3均为回文数
#include <iostream>
using namespace std;
/*int power(int n ,int i)
{
    int val=1;
    for( ;i>0 ; i--)
    {
        val *=n;
    }
    return val;
}
int reverse(int n)
{
    int m=0;
    for(int i=0;n>0;i++)
    {
        m = m*10 + n%10;
        n/=10;
    }
    return m;
}
int main() {
    int i;
    for (i=11;i<1000;i++)
    {
        if(i == reverse(i)&& power(i,2) == reverse(power(i,2)) && power(i,3) == reverse(power(i,3)))
        {
            cout << i <<"^2=" << power(i,2) <<"  "<<i<<"^3=" <<power(i,3)<<endl;
        }
    }
    return 0;
}
*/
//自己编写的代码如上
bool symm(unsigned n) //定义布尔类型的函数在进行条件判断的时候会简单很多
{
    unsigned i =n;
    unsigned m = 0;
    while (i>0)
    {
        m = m*10 +i%10;
        i/=10;
    }
    return m==n;
}
int main()
{
    for(unsigned m=11;m<1000;m++)
    {
        if(symm(m)&&symm(m*m)&& symm(m*m*m))
        {
            cout << "m = " << m;
            cout << " m*m = " << m*m;
            cout << " m*m*m = "
                << m*m*m <<endl;
        }
    }
    return 0;
}