#include <iostream>
#include "version_1.h"
#include "version_2.h"
#include "version_3.h"

using namespace std;

int main()
{
    for (int i = 1; i <= 20; i++) //二分递归思路
    {
        cout << Fibonacci_1(i) << "\t";
    }
    int prev;
    cout << Fibonacci_2(20, prev) << endl; //制表思路
    cout << Fibonacci_3(20) << endl;       //动态规划思路
    return 0;
}