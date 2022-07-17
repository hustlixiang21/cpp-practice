#include <iostream>
#include <string>
using namespace std;
class Person
{
	friend ostream& operator<<(ostream&, const Person&);
	friend istream& operator>>(istream&, Person&);
public:
	Person() {};
	Person(const string& name)
	{
		m_strName = name;
	}
	~Person() {};

private:
	string m_strName;
};

ostream& operator<<(ostream& cout, const Person& p)
{
	cout << p.m_strName;
	return cout;
}

istream& operator>>(istream& cin, Person& p)
{
	cin >> p.m_strName;
	return cin;
}

class Student :public Person
{
	friend ostream& operator<<(ostream&, const Student&);
	friend istream& operator>>(istream&, Student&);
public:
	Student() {};
	Student(const string& name)
	{
		m_strSID = name;
	}
	Student& operator++()
	{
		m_nLastID++;
		return *this;
	}
	~Student() {};
private:
	string m_strSID = "ÕÅÈý";
	static int m_nLastID;
};

int Student::m_nLastID = 0;

ostream& operator<<(ostream& cout, const Student& s)
{
	cout << s.m_strSID << "  " << ++s.m_nLastID;
	return cout;
}

istream& operator>>(istream& cin, Student& s)
{
	cin >> s.m_strSID;
	return cin;
}

int main()
{
	Person p;
	cin >> p;
	cout << p << endl;

	Student s1;
	cin >> s1;
	cout << s1 << endl;

	Student s2;
	cin >> s2;
	cout << s2 << endl;
}