//分数类Fraction的实现

#include <iostream>
#include <sstream>
#include "Fraction.h"
using namespace std;

int main()
{
	//通过double构造Fraction对象
	double  d;
	Fraction    f1(0.3);

	//从输入流输入分子、分母
	Fraction    f2{};
	cin >> f2;

	//计算分数表达式的结果，输出形式为化简后的分数
	Fraction f3 = (f2 - f1) * (f1 + f2) / f2;
	cout << f3 << endl;

	return 0;
}