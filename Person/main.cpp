#include <iostream>
#include <string>

using namespace std;

class Person;//类的声明
std::istream& read(std::istream& is, Person& per);
std::ostream& print(std::ostream& os,Person& per);
//读写函数的声明
class Person//类的定义
        {
public:
    Person()
    {
        name =  "0" ;
        address = "0";
    }
    Person(const string name_, const string address_)
    {
        name = name_;
        address = address_;
    }
    //explicit Person(std::istream& is = std::cin) {}  //满足第四个问题和第五个
    //可以通过explicit关键字，阻止“以赋值语法进行带有转型操作的初始化”
    string getName() const {return name;}
    string getAddress() const { return address; }
    // 这里的getName和getAddress应当被设置为常量成员函数，因为函数体内部存在对成员变量的修改，
    // 即如果设置为常量成员函数该类常量的对象也就可以调用这两个函数。
    void setName(string name_) { name = name_; }
    void setAddress(string address_) { address = address_; }
    //Add函数用于增加人员信息


private:
    string name;
    string address;
};
Person person[10]; //定义一个对象数组
//读写函数的定义

/* read和print分别接受一个各自IO类型的引用作为其参数，这是因为IO类属于不能被拷贝的类型
 * 因为我们只能使用引用来进行传递。并且在函数体内需要修改IO对象的状态，
 * 所以IO对象不能被设置成const。*/
std::istream& read(std::istream& is, Person& per)
// 解释：istream &is是一个引用的定义。 其中，istream是in stream的简称，即输入流。
// 这是c++中用来读取输入的一个类，封装了大部分的常用输入操作，如cin就是该类最常用的一个对象。
// &is表示定义一个引用，其名字为is。引用是c++中的一种特殊类型，定义时本身并不会申请内存，而是直接使用初始化变量的内存，相当于该变量的别名。
// 其好处在于，由于不需要申请分配内存，也不会产生构造和析构，提高了运行效率。同时，当引用被修改时，原始变量会被同步修改。
// 引用作为变量形式出现时，必须在定义时同时赋值，否则编译会出错。 除变量外，引用还常用于函数参数。
{
    string name, address;
    is >> name >> address;
    per.setName(name);
    per.setAddress(address);
    return is;  //这里所返回的也是一个引用，好处是可以作为左值
}
std::ostream& print(std::ostream& os, Person& per) {
    os << per.getName() << '\t' << per.getAddress() << endl;
    return os;
}
void Add()
{
    int n;
    cin >> n;
    read(cin,person[n]);
    cout << "Add finished!" << endl;
}
void print_person()
{
    int n;
    cin >> n;
    print(cout,person[n]);
    cout << "print finished!" <<endl;
}
void Delete()
{
    int n;
    cin >> n;
    person[n].setName("0");
    person[n].setAddress("0");
    cout << "Delete finished" << endl;
}
void Modify()
{
    int n;
    cin >> n;
    read(cin,person[n]);
    cout << "Modify finished!" << endl;
}
void Clear_all()
{
    for(auto & i : person)
    {
        i.setName("0");
        i.setAddress("0");
        cout << "Clear finished!" << endl;
    }
}
void List_all()
{
    int num =0;
    for(auto & i : person)
    {
        for(auto &s:i.getName())
        {
            num  = num*10 + s - '0';
        }
        if(num!=0)
        {
            print(cout,i);
        }
        num = 0;
    }
    cout << "List finished!" << endl;
}

int main()
{
    int flag =1;
    char expression;
    while(true)
    {
        if(flag==1)
        {
            cout << "You should Type -H to know the operations!" << endl;
        }
        cin >> expression;
        switch (expression)
        {
            case 'A':
                Add();
                break;
            case 'D':
                Delete();
                break;
            case 'P':
                print_person();
                break;
            case 'M':
                Modify();
                break;
            case 'C':
                Clear_all();
                break;
            case 'L':
                List_all();
                break;
            case 'H':
                cout << "A [ID] [name] [address] -Add one person in the specific place" << endl;
                cout << "D [ID] -Del one person" << endl;
                cout << "M [ID] [name] [address] -Modify ID's person's information" << endl;
                cout << "C -Clear all the person" << endl;
                cout << "L -List the person" << endl;
                cout << "p [ID] -Print the person's information according to ID " << endl;
                cout << "X -Exit" << endl;
                cout << "H -Help" << endl;
                cout << "The ID begin from 0!" << endl;
                break;
            case 'E':
                return 0;
        }
        flag = 0;
    }
}
