#include <iostream>
//#include <cmath>
using namespace std;

class Complex
{
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {} //构造函数
    //声明友元是为了访问类内的数据成员
    friend Complex operator+(const Complex &c1, const Complex &c2); //重载加法运算符
    friend Complex operator-(const Complex &c1, const Complex &c2); //重载减法运算符
    friend Complex operator*(const Complex &c1, const Complex &c2); //重载乘法运算符
    friend Complex operator/(const Complex &c1, const Complex &c2); //重载除法运算符

    friend ostream &operator<<(ostream &out, const Complex &c); //重载输出运算符
    friend istream &operator>>(istream &in, Complex &c);        //重载输入运算符 const了怎么改引用，大蠢货！！！

    friend bool operator==(const Complex &c1, const Complex &c2); //重载==运算符
    friend bool operator!=(const Complex &c1, const Complex &c2); //重载!=运算符
    friend bool operator<(const Complex &c1, const Complex &c2);  //重载<运算符
    friend bool operator>(const Complex &c1, const Complex &c2);  //重载>运算符
    friend bool operator<=(const Complex &c1, const Complex &c2); //重载<=运算符
    friend bool operator>=(const Complex &c1, const Complex &c2); //重载>=运算符

    friend void operator-(Complex &c1); //重载取负运算符
private:
    double real; //复数的实部
    double imag; //复数的虚部
};

//重载加减乘除
Complex operator+(const Complex &c1, const Complex &c2) { return {c1.real + c2.real, c1.imag + c2.imag}; }
Complex operator-(const Complex &c1, const Complex &c2) { return {c1.real - c2.real, c1.imag - c2.imag}; }
Complex operator*(const Complex &c1, const Complex &c2)
{
    return {c1.real * c2.real - c1.imag * c2.imag, c1.imag * c2.real + c1.real * c2.imag};
}
Complex operator/(const Complex &c1, const Complex &c2)
{
    return {(c1.real * c2.real + c1.imag * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag), (c1.imag * c2.real - c1.real * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag)};
}

// Clang-Tidy: Avoid repeating the return type from the declaration; use a braced initializer list instead 这是C++11的做法，可以优化代码，只传初始化列表

//重载比较运算符
bool operator==(const Complex &c1, const Complex &c2)
{
    if (c1.real == c2.real && c1.imag == c2.imag)
        return true;
    else
        return false;
}
bool operator!=(const Complex &c1, const Complex &c2)
{
    if (c1.real != c2.real || c1.imag != c2.imag)
        return true;
    else
        return false;
}
bool operator<(const Complex &c1, const Complex &c2)
{
    if (c1.imag != 0 || c2.imag != 0)
    {
        cout << "The two numbers cannot be compared!" << endl;
        exit(1);
    }
    if (c1.real < c2.real)
        return true;
    else
        return false;
}
bool operator>(const Complex &c1, const Complex &c2)
{
    if (c1.imag != 0 || c2.imag != 0)
    {
        cout << "The two numbers cannot be compared!" << endl;
        exit(1);
    }
    if (c1.real > c2.real)
        return true;
    else
        return false;
}
bool operator<=(const Complex &c1, const Complex &c2)
{
    if (c1.imag != 0 || c2.imag != 0)
    {
        cout << "The two numbers cannot be compared!" << endl;
        exit(1);
    }
    if (c1.real <= c2.real)
        return true;
    else
        return false;
}
bool operator>=(const Complex &c1, const Complex &c2)
{
    if (c1.imag != 0 || c2.imag != 0)
    {
        cout << "The two numbers cannot be compared!" << endl;
        exit(1);
    }
    if (c1.real >= c2.real)
        return true;
    else
        return false;
}

//重载输入输出
ostream &operator<<(ostream &out, const Complex &c) // ostream只能传引用不能传副本，因为ostream类是不可复制的
{
    out << "(" << c.real << "," << c.imag << ")";
    return out;
}
istream &operator>>(istream &in,Complex &c)
{
    in >> c.real >> c.imag;
    return in;
}

//重载负号操作符，取负
void operator-(Complex &c)
{
    c.real = -c.real;
    c.imag = -c.imag;
}

int main()
{
    Complex c1(5, 4), c2(2, 10), c3;
    cout << "c1=" << c1 << endl;
    cout << "c2=" << c2 << endl;
    c3 = c1 - c2;
    cout << "c3=c1-c2=" << c3 << endl;
    c3 = c1 + c2;
    cout << "c3=c1+c2=" << c3 << endl;
    c3 = c1 * c2;
    cout << "c3=c1*c2=" << c3 << endl;
    c3 = c1 / c2;
    cout << "c3=c1/c2=" << c3 << endl;
    -c3;
    cout << "-c3=" << c3 << endl;
    Complex c4(5, 4);
    if (c1 == c4)
        cout << "c1=c4" << endl;
    if (c4 != c2)
        cout << "c2!=c4" << endl;
    cin >> c3;
    cout << "c3=" << c3 << endl;

    return 0;
}
