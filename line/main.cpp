#include <iostream>
#include <cmath>
using namespace std;

//Point类
class Point{
public:
    Point(float xx,float yy); //构造函数
    Point(); //默认构造函数
    Point(Point &p); //复制构造函数
    float getX(){return x;}
    float getY(){return y;}
private:
    float x,y;
};
Point::Point(float xx,float yy):x(xx),y(yy){} //构造函数的定义
Point::Point():x(0),y(0){} //默认构造函数的定义
Point::Point(Point &p) //复制构造函数的定义
{
    x=p.x;
    y=p.y;
    cout << "Calling the copy constructor of Point" << endl;
}
//Line类，类的组合，计算两点之间的距离
class Line{
public:
    Line(Point o1,Point o2); //参数为Point对象的构造函数
    Line(Line &l); //复制构造函数
    float getLen(); //外部接口
private:
    Point p1,p2;
    float len=0;
};
Line::Line(Point o1,Point o2):p1(o1),p2(o2) //构造函数是每一个成员变量都要初始化的
{
    float x=p1.getX()-p2.getX();
    //此处并不能够直接写  o1.x - o2.x 因为x属于私有变量
    // 通过两个public成员函数可以访问，相当于提供了外部接口
    float y=p1.getY()-p2.getY();
    len= sqrt(x*x+y*y);
    cout << "Calling the constructor of Line" << endl;
}
Line::Line(Line &l): p1(l.p1),p2(l.p2) //复制构造函数是每一个成员变量都需要进行复制的 且这个'.'只能够在类的作用域内使用。
{
    len=l.len;
    cout << "Calling the copy constructor of Line" << endl;
}
float Line::getLen() {return len;}
int main()
{
    Point myp1(1,1),myp2(4,5);
    Line line(myp1,myp2); //参数传递的时候也需要复制构造哦
    Line line2(line);
    cout << "The length of line is " << line.getLen() << endl;
    cout << "The length of line2 is " << line2.getLen() << endl;
    return 0;
}
