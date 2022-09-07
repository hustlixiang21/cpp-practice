#include <iostream>

#define MAXINT 65535
#define ArrSize 100
using namespace std;

int main()
{
    int n, i;
    int array[ArrSize];
    cout << "Please enter a integer n:" << endl;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        if (i > ArrSize)
        {
            cout << "\n"
                 << "Sorry, the size is overflow!" << endl;
            exit(-1);
        }
        if (i == 1)
            array[0] = 2;
        else
        {
            if (i * 2 * array[i - 2] > MAXINT)
            {
                cout << "\n"
                     << "Sorry, the number is overflow!" << endl;
                exit(-1);
            }
            array[i - 1] = i * 2 * array[i - 2];
        }
    }
    for (int j = 0; j < i - 1; j++)
    {
        cout << array[j] << "\t";
    }
    return 0;
}