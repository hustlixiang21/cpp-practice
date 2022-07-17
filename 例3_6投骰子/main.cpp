#include <iostream>
#include <cstdlib>
using namespace std;
int rollDice()
{
    int die1 = 1 + rand()%6;
    int die2 = 1 + rand()%6;
    int sum = die1 + die2;
    cout << "player rolled" << die1 << "+" << die2 << "=" << sum <<endl;
    return sum;
}
enum GameStatus{WIN,LOSE,PLAYING}; //定义枚举类型游戏状态
int main()
{
    int sum,mypoint;
    GameStatus status;
    unsigned seed;
    cout << "Please enter an unsigned integer:";
    cin >> seed; //输入随机数种子
    srand(seed);//将种子传递给rand()
    sum = rollDice();
    switch (sum)
    {
        case 7:
        case 11:
            status = WIN;
            break;
        case 2:
        case 3:
        case 12:
            status =LOSE;
            break;
        default:
            status = PLAYING;
            mypoint = sum;
            cout << "point is "<< mypoint << endl;
            break;
    }
    while(status == PLAYING)
    {
        sum = rollDice();
        if (sum == mypoint)
        {
            status = WIN;
        }
        else if(sum == 7)
        {
            status = LOSE;
        }
    }
    if(status == WIN )
        cout << "player wins" <<endl;
    else
        cout << "player loses" <<endl;
    return 0;
}
