#include "List.h"
int main()
{
    List l;

    for(int n = 20 ; n <= 100 ; n += 10)
    {
        l.print_to_file(l.factorial(n),n);
    }
    return 0;
}
