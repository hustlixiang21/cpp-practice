#include <iostream>
#include <string>
using namespace std;
class Animal
{
public:
	string m_strName;
	Animal() {};
	Animal(const string&);
};

Animal::Animal(const string& name)
{
	m_strName = name;
}

class Reptile : virtual public Animal
{
public:
	void run() 
	{
		cout << m_strName << " is running" << endl;
	}
};

class Aquatic : virtual public Animal
{
public:
	void run()
	{
		cout << m_strName << "is running" << endl;
	}
};

class Fork : public Reptile, public Aquatic {};

int main()
{
	Fork f;
	f.Reptile::m_strName = "Fork";
	f.Reptile::run();
	return 0;
}