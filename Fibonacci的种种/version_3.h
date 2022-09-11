//斐波那契数列之迭代：动态规划的策略
//直接视作逐层向上返回的过程
int Fibonacci_3(int n)
{
    int f = 0, g = 1;
    while (1 < n--)
    {
        g += f;
        f = g - f;
    }
    return g;
}