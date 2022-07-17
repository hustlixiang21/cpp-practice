#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
	friend Complex operator+ (const Complex& c1, const Complex& c2);
	friend Complex operator- (const Complex& c1, const Complex& c2);
	friend Complex operator* (const Complex& c1, const Complex& c2);
	friend Complex operator/ (const Complex& c1, const Complex& c2);
	friend ostream& operator<< (ostream& out, const Complex& c);
	friend ostream& operator>> (ostream& out, const Complex& c);
	bool operator==(const Complex& d)             //==
	{
		cout << "==" << endl;
		return this->real == d.real && this->imag == d.imag;
	}
	bool operator!=(const Complex& d)             //!=
	{
		cout << "!=" << endl;
		return this->real != d.real || this->imag == d.imag;
	}
	//复数只有当虚部为0时，即imag=0时，才可以比较大小，这时比较的是实部即real的大小
	bool operator>(const Complex& d)          //>
	{
		if (this->imag != 0 || d.imag != 0)
		{
			cout << "无法比较";
			return false;
		}

		else
		{
			return this->real > d.real;
		}
	}
	bool operator<(const Complex& d)           //<
	{
		if (this->imag != 0 || d.imag != 0)
		{
			cout << "无法比较      ";
			return false;
		}
		else
		{
			return this->real < d.real;
		}
	}
	bool operator<=(const Complex& d)           //<=
	{
		if (this->imag != 0 || d.imag != 0)
		{
			cout << "无法比较      ";
			return false;
		}
		else
		{
			return this->real <= d.real;
		}
	}
	bool operator>=(const Complex& d)           //>=
	{
		if (this->imag != 0 || d.imag != 0)
		{
			cout << "无法比较        ";
			return false;
		}
		else
		{
			return this->real >= d.real;
		}
	}

private:
	double real;
	double imag;
};

Complex operator+ (const Complex& c1, const Complex& c2)
{
	return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

Complex operator- (const Complex& c1, const Complex& c2)
{
	return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

Complex operator* (const Complex& c1, const Complex& c2)
{
	return Complex(c1.real - c2.imag, c1.imag + c2.real);
}

Complex operator/ (const Complex& c1, const Complex& c2)
{
	return Complex(c1.real / c2.real, c1.imag / c2.imag);
}

ostream& operator<<(ostream& out, const Complex& c)
{
	out << "(" << c.real << "," << c.imag << ")";
	return out;
}

void Test()
{
	Complex d1(7, 0);
	Complex d2(6, 0);
	Complex d3;
	Complex d4(6, 0);
	cout << d1.operator>(d2) << endl;
	cout << d1.operator<(d2) << endl;
	cout << d3.operator<=(d4) << endl;
	cout << d2.operator>=(d4) << endl;
}

int main()
{
	Complex c1(5, 4), c2(2, 10), c3;
	cout << "c1=" << c1 << endl;
	cout << "c2=" << c2 << endl;
	c3 = c1 - c2;
	cout << "c3=c1-c2" << c3 << endl;
	c3 = c1 + c2;
	cout << "c3=c1+c2" << c3 << endl;
	c3 = c1 * c2;
	cout << "c3=c1*c2" << c3 << endl;
	c3 = c1 / c2;
	cout << "c3=c1/c2" << c3 << endl;
	Test();
	return 0;
}