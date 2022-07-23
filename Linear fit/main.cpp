//核心思路就是采用最小二乘法进行运算，然后计算一下相关系数r。

#include <iostream>
#include "point.h"
#include <cmath>

using namespace std;

float lineFit(const Point points[], int nPoint)
{
    float avgX = 0, avgY = 0;
    float lxx = 0, lxy = 0, lyy = 0;
    for (int i = 0; i < nPoint; i++)
    {
        avgX += points[i].x / nPoint;
        avgY += points[i].y / nPoint;
    }
    for (int j = 0; j < nPoint; j++)
    {
        lxx += (points[j].x - avgX) * (points[j].x - avgX);
        lyy += (points[j].y - avgY) * (points[j].y - avgY);
        lxy += (points[j].x - avgX) * (points[j].y - avgY);
    }
    cout << "This line can be fitted by y=ax+b." << endl;
    cout << "a=" << lxy / lxx << "  ";
    cout << "b=" << avgY - lxy * avgX / lxx << endl;
    return static_cast<float>(lxy / sqrt(lxx * lyy)); //强制类型转换
}

int main()
{
    Point p[10] = { Point(6, 10),
                    Point(14, 20),
                    Point(26, 30),
                    Point(33, 40),
                    Point(46, 50),
                    Point(54, 60),
                    Point(67, 70),
                    Point(75, 80),
                    Point(84, 90),
                    Point(100, 100) };
    float r=lineFit(p,10);
    cout << "Line coeffient r = " << r << endl;
    return 0;
}