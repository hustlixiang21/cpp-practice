#ifndef _CPP_ARRAY_H_
#define _CPP_ARRAY_H_

#include <cassert>

template <class T>
class Array
{
private:
    T *list;  //用于存放动态分配的数组的首地址
    int size; //数组大小，元素个数
public:
    Array(int sz = 50);                       //构造函数
    Array(const Array<T> &a);                 //复制构造函数
    ~Array();                                 //析构函数
    Array<T> &operator=(const Array<T> &rhs); //重载“=”，返回值是模版类的实例的引用
    T &operator[](int i);                     //重载“[]“
    const T &operator[](int i) const;         //重载“[]“,常函数
    operator T *();                           //重载到T*类型的转换
    operator const T *() const;
    int getSize() const; //得到数组的大小
    void resize(int sz); //修改数组的大小
};

template <class T>
Array<T>::Array(int sz)
{ //构造函数的实现
    assert(sz >= 0);
    size = sz;
    list = new T[size];
}

template <class T>
Array<T>::~Array()
{ //析构函数
    delete[] list;
}

template <class T>
Array<T>::Array(const Array<T> &a)
{ //复制构造函数
    size = a.size;
    list = new T[size];
    for (int i = 0; i < size; i++)
    {
        list[i] = a.list[i];
    }
}

template <class T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
    if (&rhs != this) //确保不是同一个对象
    {
        if (size != rhs.size) //大小不同重新分配
        {
            delete[] list; //删除原有内存
            size = rhs.size;
            list = new T[size]; //重新分配一个size相同的地址
        }
        for (int i = 0; i < size; i++)
        {
            list[i] = rhs.list[i];
        }
    }
    return *this; //返回一个当前对象的引用
}

template <class T>
T &Array<T>::operator[](int i)
{
    assert(i >= 0 && i < size);
    return list[i];
}

template <class T>
const T &Array<T>::operator[](int i) const
{
    assert(i >= 0 && i < size);
    return list[i];
}

template <class T>
Array<T>::operator T *()
{ //重载指针转换运算符，将对象名转化为T类型的指针
    return list;
}

template <class T>
int Array<T>::getSize() const
{
    return size;
}

template <class T>
void Array<T>::resize(int sz)
{ //修改数组的大小
    assert(sz >= 0);
    if (sz == size)
        return;
    T *newList = new T[sz];
    int n = sz < size ? sz : size; //选取新size和size较小的一个以便赋值
    for (int i = 0; i < n; i++)
    {
        newList[i] = list[i];
    }
    delete[] list;
    list = newList;
    size = sz; //更新数据成员
}

#endif