#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXSIZE 10
#define MAXLENGTH 50

/********函数声明部分********/
/*判断一个系数是否为零*/
bool judge_zero(double num);

/********函数实现部分********/

bool judge_zero(double num)
{
    if (num < 1e-4 && num > -1e-4)
        return true;
    return false;
}

/********主函数部分********/
int main()
{
    //每个多项式利用两个一维维数组分别暂存系数和指数
    double coef1[MAXSIZE] = {0};
    double coef2[MAXSIZE] = {0};
    int exp1[MAXSIZE] = {0};
    int exp2[MAXSIZE] = {0};
    int i1 = 0, j1 = 0;
    char ch;
    char str[MAXLENGTH];
    gets(str);
    char *p = strtok(str, " ");
    while (p)
    {
        if (p[0] == '+')
        {
            ch = '+';
            break;
        }
        if (p[0] == '-' && p[1] == '\0')
        {
            ch = '-';
            break;
        }
        if (i1 % 2 == 0)
            coef1[(i1++) / 2] = atof(p);
        else
        {
            exp1[(i1++) / 2] = atoi(p);
        }
        p = strtok(NULL, " ");
    }
    i1 = i1 / 2 + 1;
    p = strtok(NULL, " ");
    while (p)
    {
        if (j1 % 2 == 0)
            coef2[(j1++) / 2] = atof(p);
        else
        {
            exp2[(j1++) / 2] = atoi(p);
        }
        p = strtok(NULL, " ");
    }
    j1 = j1/2 + 1;
    double result_coef[MAXSIZE] = {0};
    int result_exp[MAXSIZE] = {0};
    int i = 0, j = 0, count = 0;
    if (ch == '+')
    {
        while (i < i1 && j < j1)
        {
            if (exp1[i] < exp2[j])
            {
                result_coef[count] = coef1[i];
                result_exp[count++] = exp1[i];
                i++;
            }
            else if (exp1[i] > exp2[j])
            {
                result_coef[count] = coef2[j];
                result_exp[count++] = exp2[j];
                j++;
            }
            else
            {
                if (judge_zero(coef1[i] + coef2[j]))
                {
                    i++;
                    j++;
                    continue;
                }
                result_coef[count] = coef1[i] + coef2[j];
                result_exp[count++] = exp1[i];
                i++;
                j++;
            }
        }
        if (i == i1)
        {
            while (j < j1)
            {
                result_coef[count] = coef2[j];
                result_exp[count++] = exp2[j++];
            }
        }
        if (j == j1)
        {
            while (i < i1)
            {
                result_coef[count] = coef1[i];
                result_exp[count++] = exp1[i++];
            }
        }
    }
    else
    {
        while (i < i1 && j < j1)
        {
            if (exp1[i] < exp2[j])
            {
                result_coef[count] = coef1[i];
                result_exp[count++] = exp1[i];
                i++;
            }
            else if (exp1[i] > exp2[j])
            {
                result_coef[count] = -coef2[j];
                result_exp[count++] = exp2[j];
                j++;
            }
            else
            {
                if (judge_zero(coef1[i] - coef2[j]))
                {
                    i++;
                    j++;
                    continue;
                }
                result_coef[count] = coef1[i] - coef2[j];
                result_exp[count++] = exp1[i];
                i++;
                j++;
            }
        }
        if (i == i1)
        {
            while (j < j1)
            {
                result_coef[count] = -coef2[j];
                result_exp[count++] = exp2[j++];
            }
        }
        if (j == j1)
        {
            while (i < i1)
            {
                result_coef[count] = coef1[i];
                result_exp[count++] = exp1[i++];
            }
        }
    }
    if (count == 0)
        printf("0 0");
    else
    {
        for (int k = count - 1; k >= 0; k--)
        {
            if (judge_zero(result_coef[k]))
                continue;
            printf("%g %d ", result_coef[k], result_exp[k]);
        }
    }
    return 0;
}
