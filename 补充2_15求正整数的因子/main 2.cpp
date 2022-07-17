#include <iostream>
using namespace std;
int main()
{
    int a,element=2,b;
    cout << "please input a positive integer：" << endl;
    cin >> a;
    cout << a << "=";
    b =a;
    while (a!=1)
    {
        if(b ==element)
            cout << "1*";
        if(a%element == 0)
        {
            cout << element;
            if(a != element)
                cout << "*";
            a /= element;
        }
        else
            element++;

    }
    return 0;
}
