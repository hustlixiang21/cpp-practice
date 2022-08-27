//从标准输入读入几个实数，分别输出他们的平方
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

double square(double x)
{
    return x * x;
}

int main()
{
    transform(istream_iterator<double>(cin),istream_iterator<double>(),ostream_iterator<double>(cout,"\t"),square);
    //istream_iterator<double>()调用了输入流迭代器的默认构造函数，使之指向的是输入流的结束位置。
    cout << endl;
    return 0;
    //你如果不手动终止程序，程序会一直运行下去，因为输入流一直在等待你的输入
}