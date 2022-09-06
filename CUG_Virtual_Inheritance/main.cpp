#include <iostream>
using namespace std;

class Fork{};
class Reptile:virtual public Fork{
public:
    void run();
};
class Aquatic:virtual public Fork{
public:
    void run();
};
class Animal:public Reptile,public Aquatic{
public:
    Animal(const string &m_strName):m_strName(m_strName){}

private:
    string m_strName;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;

}