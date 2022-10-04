/*
一）已知顺序表 L 有 n 个整数，请用递归算法的函数来实现以下要求。

1）求 L 中的最大整数；

2）求 L 中 n 个整数之和；

3）求 L 中 n 个整数之积；

4）求 L 中 n 个整数之平均值；
*/

//整体还是使用分治的思想
#include <iostream>

using namespace std;
//最大整数
int MaxElem(int *arr, int left, int right)
{
    if (left == right)
        return arr[left];
    int mid = (right - left) / 2 + left;
    int val1 = MaxElem(arr, left, mid);
    int val2 = MaxElem(arr, mid + 1, right);
    return val1 < val2 ? val2 : val1;
}
//求和
int SumElem(int *arr, int left, int right)
{
    if (left == right)
        return arr[left];
    int mid = (right - left) / 2 + left;
    int val1 = SumElem(arr, left, mid);
    int val2 = SumElem(arr, mid + 1, right);
    return val1 + val2;
}

//求平均
double Average_Elem(int *arr, int left, int right, int n)
{
    return static_cast<double>(SumElem(arr, left, right)) / static_cast<double>(n);
}
//乘积
int MulElem(int *arr, int left, int right)
{
    if (left == right)
        return arr[left];
    int mid = (right - left) / 2 + left;
    int val1 = MulElem(arr, left, mid);
    int val2 = MulElem(arr, mid + 1, right);
    return val1 * val2;
}

int main()
{
    int array[10] = {1, 4, 2, 0, 6, 10, 7, 9, 4, 3};
    cout << MaxElem(array, 0, 9) << endl;
    cout << SumElem(array, 0, 9) << endl;
    cout << MulElem(array, 0, 9) << endl;
    cout << Average_Elem(array, 0, 9, 10) << endl;
    return 0;
}