#include "Fraction.h"
Fraction::Fraction(int nume, int deno)
{
	m_numerator = nume;
	m_denominator = deno;
}

Fraction::Fraction(const Fraction& f)
{
	m_numerator = f.m_numerator;
	m_denominator = f.m_denominator;
}

Fraction::Fraction(double d)
{
	stringstream ss;
	string str;
	ss << d;
	ss >> str;

	bool flag = 0;
	char ch;
	for (int i = 0; i < str.length(); i++)
	{
		ch = str[i];
		if (ch == '.')	flag = 1;
		else
		{
			m_numerator = m_numerator * 10 + ch - '0';
			if (flag) m_denominator *= 10;
		}
	}

	for (int i = 2; i <= m_numerator; i++)
	{
		if (m_numerator % i == 0 && m_denominator % i == 0)
		{
			m_numerator /= i;
			m_denominator /= i;
			i = 1;
		}
	}
	cout << m_numerator << '/' << m_denominator << endl;
}

ostream& operator<<(ostream& cout, Fraction& f)
{
	f.normalize();
	cout << f.m_numerator << "/" << f.m_denominator;
	return cout;
}

istream& operator>>(istream& cout, Fraction& f)
{
	cin >> f.m_numerator >> f.m_denominator;
	f.simplify();
	return cin;
}

int Fraction::getNumerator() const
{
	return m_numerator;
}

int Fraction::getDenominator() const
{
	return m_denominator;
}

double Fraction::getValue() const
{
	double value = m_numerator / m_denominator;
	return value;
}

void Fraction::normalize()
{
	this->simplify();
	this->resetSign();

}

void Fraction::resetSign()
{
	if (m_denominator < 0)
	{
		m_denominator = -m_denominator;
		m_numerator = -m_numerator;
	}
}

void Fraction::simplify()
{
	int t, a, b;
	a = m_numerator;
	b = m_denominator;
	while (b != 0)
	{
		t = a % b;
		a = b;
		b = t;
	}
	m_numerator = m_numerator / a;
	m_denominator = m_denominator / a;
}

Fraction Fraction::operator+(const Fraction& f)
{
	Fraction f0;
	if (this->m_denominator == 0 || f.m_denominator == 0)
	{
		cout << "无法运算" << endl;
		return f0;
	}
	else
	{
		f0.m_numerator = this->m_numerator * f.m_denominator + f.m_numerator * this->m_denominator;
		f0.m_denominator = this->m_denominator * f.m_denominator;
		f0.normalize();
		return f0;
	}
}

Fraction Fraction::operator-(const Fraction& f)
{
	Fraction f0;
	if (this->m_denominator == 0 || f.m_denominator == 0)
	{
		cout << "无法运算" << endl;
		return f0;
	}
	else
	{
		f0.m_numerator = this->m_numerator * f.m_denominator - f.m_numerator * this->m_denominator;
		f0.m_denominator = this->m_denominator * f.m_denominator;
		f0.normalize();
		return f0;
	}
}

Fraction Fraction::operator*(const Fraction& f)
{
	Fraction f0;
	if (this->m_denominator == 0 || f.m_denominator == 0)
	{
		cout << "无法运算" << endl;
		return f0;
	}
	else
	{
		f0.m_numerator = this->m_numerator * f.m_numerator;
		f0.m_denominator = this->m_denominator * f.m_denominator;
		f0.normalize();
		return f0;
	}
}

Fraction Fraction::operator/(const Fraction& f)
{
	Fraction f0;
	if (this->m_denominator == 0 || f.m_denominator == 0)
	{
		cout << "无法运算" << endl;
		return f0;
	}
	else
	{
		f0.m_numerator = this->m_numerator * f.m_denominator;
		f0.m_denominator = this->m_denominator * f.m_numerator;
		f0.normalize();
		return f0;
	}
}