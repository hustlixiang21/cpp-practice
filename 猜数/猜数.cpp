//随机数生成代码
#include <iostream>
#include <ctime>  //time
#include <cstdlib>  //rand
using namespace std;
int main()
{
    int guess_number,input_number,times=0;
    srand((unsigned int)time(0)); //随机数种子
    guess_number = rand()%100; //存储一个0-99之间的随机数
    cout << "Please enter a random number:" << endl;
    do
    {
        cin >> input_number;
        if(input_number > guess_number)
        {
            cout << "The number you guess is larger than the random number" << endl;
        }
        else if(input_number < guess_number)
        {
            cout << "The number you guess is smaller than the random number" << endl;
        }
        times++;
    }while(guess_number != input_number);
    cout << "Congratulation! You use " << times << " times to guess the number!" << endl;
    return 0;
}

