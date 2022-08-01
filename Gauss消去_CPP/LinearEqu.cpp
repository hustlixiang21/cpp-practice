//
// Created by lixiang on 2022/8/1.
//

#include "LinearEqu.h"
#include <iostream>
#include <iomanip>

using namespace std;

LinearEqu::LinearEqu(int size) : Matrix(size) {
    sums = new double[size];
    solution = new double[size];
}

LinearEqu::~LinearEqu() {
    delete[] sums;
    delete[] solution;  //分配的数组必须要delete[],很重要！！！
}

void LinearEqu::setLinearEqu(const double * a, const double * b) {   //a为系数矩阵一维数组，b为方程右端的值
    setMatrix(a);
    for(int i = 0 ; i < getSize() ; i++)
    {   /*公有继承不能访问基类的private的size数据，只能通过外部接口getSize*/
        sums[i] = b[i];
    }
}

//需要多次进行两个数的交换，可以定义一个交换函数
void swap(double &a , double &b)
{
    double temp = a;
    a = b;
    b = temp;
}


bool LinearEqu::solve()
{
    int * js = new int[getSize()]; //存储主元素所在列号的数组，列交换的时候会改变x[i]的位置，需要记录
    for (int k = 0; k < getSize() - 1 ; k++)
    {
        int is;   //主元素所在的行号
        double max = 0; //让最大的在主对角线的原因就是防止主对角线上有0，想要继续消元就得换行，避免了这种情况
        for (int i = k ; i < getSize() ; i++)
        {
            for(int j = k ; j < getSize() ; j++)
            {
                double temp = element(i,j)>0 ? element(i,j) : -element(i,j);
                if(temp > max)
                {
                    max = temp;
                    is = i;
                    js[k]=j;
                }
            }
        }
        if(max==0)
        {
            delete[] js;
            return false;
        }
        else
        {
            if(js[k]!=k)//交换列
            {
                for(int i = 0; i < getSize(); i++)
                {
                    swap(element(i,k), element(i,js[k]));
                }
            }
            if(is!=k)//交换行
            {
                for(int j = 0; j < getSize(); j++)
                {
                    swap(element(k,j), element(is,j));
                    swap(sums[k],sums[is]);
                }
            }
        }
        double major = element(k,k);
        for (int j=k+1;j<getSize();j++)
        {
            element(k,j) /= major;
        }
        sums[k] /= major;
        for (int i=k+1;i<getSize();i++)
        {
            for (int j=k+1;j<getSize();j++)
            {
                element(i,j) -= element(i,k) * element(k,j);
            }
            sums[i] -= element(i,k) * sums[k];
        }
    }
    double d = element(getSize()-1 , getSize()-1);
    if ((d>0? d : -d) < 1e-15){
        delete[] js;
        return false;
    }
    solution[getSize()-1] = sums[getSize()-1]/d;
    for(int i=getSize()-2;i>=0;i--)
    {
        double t=0;
        for (int j=i+1; j <= getSize()-1; j++)
        {
            t += element(i,j) * solution[j];
        }
        solution[i] = sums[i] - t;
    }
    for(int k = getSize() - 2; k >= 0 ; k--)
    {
        if (js[k]!=k) swap(solution[k],solution[js[k]]);
    }
    delete[] js;
    return true;
}

void LinearEqu::printLinearEqu() const
{
    cout << "The Line equation is: " << endl;
    for (int i = 0 ; i < getSize() ; i++)
    {
        for (int j = 0 ; j < getSize() ; j++)
        {
            cout << setw(6) <<  element(i,j) << " ";
        }
        cout << "     " << sums[i] << endl;
    }
}

void LinearEqu::printSolution() const
{
    for(int i = 0 ; i < getSize() ; i++)
    {
        cout << "x["<< i <<"]=" << solution[i] << endl;
    }
}


