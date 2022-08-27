//综合运用集中迭代器的实例
#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
using namespace std;

template <class T, class InputIterator, class OutputIterator>
void mySort(InputIterator first, InputIterator last, OutputIterator result)
{
    vector<T> s;
    while (first != last)
    {
        s.push_back(*first);
        first++;
    }
    sort(s.begin(), s.end()); // sort参数必须是随机访问迭代器
    copy(s.begin(), s.end(), result);
}

int main()
{
    double a[5] = {1.2, 2.4, 0.8, 3.3, 3.2};
    //对已知数组排序
    mySort<double>(a, a + 5, ostream_iterator<double>(cout, " "));
    cout << endl;
    //从标准输入读入若干整数，排序后的结果输出
    mySort<int>(istream_iterator<int>(cin), istream_iterator<int>(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}