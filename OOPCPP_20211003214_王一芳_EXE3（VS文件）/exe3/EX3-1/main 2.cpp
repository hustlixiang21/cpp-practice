//������Fraction��ʵ��

#include <iostream>
#include <sstream>
#include "Fraction.h"
using namespace std;

int main()
{
	//ͨ��double����Fraction����
	double  d;
	Fraction    f1(0.3);

	//��������������ӡ���ĸ
	Fraction    f2{};
	cin >> f2;

	//����������ʽ�Ľ���������ʽΪ�����ķ���
	Fraction f3 = (f2 - f1) * (f1 + f2) / f2;
	cout << f3 << endl;

	return 0;
}