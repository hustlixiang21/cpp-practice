#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Please enter a number:" << endl;
    cin >> n;
    //外层循环用于输出乘法表行数
    for(int i=1;i<=n;i++)
    {
        //内层循环用于输出每行的内容
        for(int j=1;j<=i;j++)
        {
            cout << i << "*" << j << "="<< i*j << "\t";
        }
        //换行
        cout << endl;
    }
    return 0;
}
