#include <iostream>
using namespace std;
int main()
{
    int n,i,j,k;
    cout << "Please enter a number:" << endl;
    cin >> n;
    for(i=1;i <= 2*n-1;i++)//所要输出的总的行数
    {
        //首先应该分类，依据是点数递增和递减
        if(i<=n)
        {
            //输出前面的空格
            for(j=n-i;j>0;j--)
            {
                cout << " ";
            }
            //输出点数*
            for(k=0;k<2*i-1;k++)
            {
                cout << "*";
            }
            //换行
            cout << endl;
        }  
        else
        {
            //输出前面的空格i从11开始
            for(j=i-n;j>0;j--)
            {
                cout << " ";
            }
            //输出点数*
            
            for(k=0;k<2*(2*n-i)-1;k++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
    return 0;
}
