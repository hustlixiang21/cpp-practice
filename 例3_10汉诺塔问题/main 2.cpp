#include <iostream>
using namespace std;
void move(char src,char dest)
{
    cout << src << "-->" << dest <<endl; //把src针的最上面一个盘子移动到dest针上
}
void hanoi(int n,char src,char medium,char dest)//将n个盘子从src针移动到dest针，以medium针为中转
{
    if(n==1)
        move(src,dest);
    else
    {
        hanoi(n-1,src,dest,medium);
        move(src,dest);
        hanoi(n-1,medium,src,dest);
    }
}

int main()
{
    int m;
    cout << "Enter the number of disks:";
    cin >> m;
    cout << "The steps to moving "<< m << " disks:" << endl;
    hanoi(m,'A','B','C');
    return 0;
}
