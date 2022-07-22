#include <iostream>
#include <cmath>
using namespace std;

class Point{                //Point类定义
public:
    Point(int set_x,int set_y):x(set_x),y(set_y){}   //构造函数 初始化列表
    Point(Point &p){                                 //复制构造函数
        x = p.x;
        y = p.y; 
        }
    ~Point(){cout << "hello!" << endl;}
    int get_x(){return x;}
    int get_y(){return y;}
    friend double distance(Point p1, Point p2);
private:
    int x,y;
};
double distance(Point p1,Point p2){
    double x = p1.get_x() - p2.get_x();
    double y = p1.get_y() - p2.get_y();
    return sqrt(x*x+y*y);
}
int main()
{
    Point p1(1,1),p2(4,5);
    cout << "The distance between p1 and p2 is " << distance(p1,p2) << endl;
    return 0;
}