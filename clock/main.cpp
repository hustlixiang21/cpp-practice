#include <iostream>
using namespace std;
//类的定义
class Clock{
public:
    Clock(int newH,int newM,int newS): hour(newH),minute(newM),second(newS){}//构造函数
    void setTime(int newH = 0,int newM = 0,int newS = 0);
    void showTime() const;
private:
    int hour,minute,second;
};

//成员函数的实现
void Clock::setTime(int newH,int newM,int newS)
{
hour = newH;
minute = newM;
second = newS;
}
void Clock::showTime() const
{
    cout << hour << ":" << minute << ":" << second << endl;
}
//对象的使用
int main()
{
    Clock c(0,0,0);//自动调用构造函数
    c.showTime();
    c.setTime(8,8,8);
    c.showTime();
    return 0;
}