#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class Fraction
{
public:
	Fraction() {};
	Fraction(int nume, int deno);
	Fraction(const Fraction& f);
	Fraction(double);

	void normalize();
	void resetSign();
	void simplify();

	int getNumerator() const;
	int getDenominator() const;
	double getValue() const;

	Fraction operator+(const Fraction& f);
	Fraction operator-(const Fraction& f);
	Fraction operator*(const Fraction& f);
	Fraction operator/(const Fraction& f);

	friend ostream& operator<<(ostream& cout, Fraction& f);
	friend istream& operator>>(istream& cout, Fraction& f);

private:
	int m_numerator = 0;
	int m_denominator = 1;
};