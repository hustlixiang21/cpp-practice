#include <iostream>
using namespace std;
int main()
{
    int start_number = 10;
    for( ;start_number <= 10000;start_number*=10) {
        for (int i = start_number / 10; i < start_number; i++) {
            if (i == (i * i) % start_number) {
                cout << "i=" << i << "  " <<"i*i=" << i * i << endl;
            }
        }
    }
    return 0;
}
