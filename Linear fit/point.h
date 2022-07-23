#ifndef _POINT_H_
#define _POINT_H_

class Point{
public:
    Point(float xx,float yy):x(xx),y(yy){}
    float getX(){return x;}
    float getY(){return y;}
    friend float lineFit(const Point points[],int nPoint);
private:
    float x,y;
};


#endif