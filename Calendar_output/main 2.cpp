#include "calendar.h"
using namespace std;
int main()
{
    int year,month;
    cin >> year >> month;
    output(calculate(year,month),month);
    return 0;
}
