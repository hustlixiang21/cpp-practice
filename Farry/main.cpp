#include "List.h"
int main() {
    int a;
    List l;
    for(a=10;a<=1000;a++)
    {
        l.putin(a);
        l.print(a);
    }
    return 0;
}
