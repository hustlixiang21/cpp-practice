#include <iostream>
using namespace std;
int fibonacci(int n)
{
   if(n==1 || n==2)
       return 1;
   else return fibonacci(n-1)+fibonacci(n-2);
}
int main()
{
    int n;
    cout << "please enter a number:" << endl;
    cin >> n;
    if(n==1 || n==2)
    {
        cout << "The outcome is 1" << endl;
    }
    else
        cout << "The outcome is " << fibonacci(n-1)+fibonacci(n-2) << endl;
    return 0;
}

