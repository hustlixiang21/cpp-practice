//优化策略：借助一定量的辅助空间，在各子问题求解之后，及时记录下其对应的解答
//根据自顶向下或者自底而上，前者叫做制表（tabulation）或者记忆（memoization），后者即动态规划（dynamic programming）
//斐波那契数列之线性递归

int Fibonacci_2(int n, int &prev)
{
    if (0 == n)
    {
        prev = 1;
        return 0;
    }
    else
    {
        int prevprev;
        prev = Fibonacci_2(n - 1, prevprev);
        return prevprev + prev;
    }
}