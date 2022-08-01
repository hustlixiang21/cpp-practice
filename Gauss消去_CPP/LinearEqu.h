//
// Created by lixiang on 2022/8/1.
//

#ifndef GAUSS_CPP_LINEAREQU_H
#define GAUSS_CPP_LINEAREQU_H
#include "Matrix.h"

class LinearEqu: public Matrix {
public:
    LinearEqu(int size = 2);
    ~LinearEqu();
    void setLinearEqu(const double * a , const double * b);   //方程赋值
    bool solve();         //高斯消去法求解方程算法,然后判断有无解,貌似不是普通的高斯，是全选祝愿高斯消去
    void printLinearEqu() const;  //显示方程
    void printSolution() const;   //显示方程的解
private:
    double * sums;      //方程右端项
    double * solution;  //方程的项
};
#endif //GAUSS_CPP_LINEAREQU_H
