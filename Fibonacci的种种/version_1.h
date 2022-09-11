//斐波那契数列之二分递归
//直接根据数列的定义就可

int Fibonacci_1(int n)
{
    return n < 2 ? n : Fibonacci_1(n - 1) + Fibonacci_1(n - 2);
}

//时间复杂度O(2^n)