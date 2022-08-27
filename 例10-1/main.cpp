//从标准输入读入几个整数，存入向量容器，输出相反数
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
    const int N = 5;
    vector<int> s(N);
    for (int i = 0; i < N; i++)
    {
        cin >> s[i];   
    }
    transform(s.begin(),s.end(), ostream_iterator<int>(cout," "),negate<int>());
    //negate是一个类模版，重载了“()”运算符，接受一个参数，改运算符就返回该参数的相反数
    cout << endl;
    return 0;
}