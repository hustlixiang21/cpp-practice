//
// Created by lixiang on 2022/8/1.
//

#ifndef GAUSS_CPP_MATRIX_H
#define GAUSS_CPP_MATRIX_H
class Matrix {
public:
    Matrix(int size = 2);
    ~Matrix();
    void setMatrix(const double * values);    //为矩阵初始化
    void printMatrix() const;                 //显示矩阵
    int getSize() const {return size;}        //得到矩阵的维数
    double &element(int i,int j){return elements[i * size + j];}        //返回的是个引用可以作为左值修改矩阵元素
    double element(int i,int j) const {return elements[i * size + j];}  //只是返回得到矩阵的某一元素
private:
    int size;               //矩阵的大小
    double * elements;      //矩阵存放数组首地址（矩阵元素用一维数组存放）
};
#endif //GAUSS_CPP_MATRIX_H
