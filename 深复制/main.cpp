#include <iostream>
#include <cassert>
using namespace std;
class Point
{ //创建点类
public:
    Point() : x(0), y(0)
    {
        cout << "Default Constructor called." << endl;
    }
    Point(int x, int y) : x(x), y(y)
    {
        cout << "Constructor called." << endl;
    }
    ~Point() { cout << "Destructor called." << endl; }
    int getX() const { return x; }
    int getY() const { return y; }
    void move(int newx, int newy)
    { // move函数用于改变点的位置
        x = newx;
        y = newy;
    }

private:
    int x, y;
};
class ArrayOfPoints
{ //创建点类的动态数组
public:
    ArrayOfPoints(int size) : size(size)
    {
        points = new Point[size]; //构造一个数组对象为点类的动态数组
    }
    ArrayOfPoints(const ArrayOfPoints &v); //复制构造函数的声明
    ~ArrayOfPoints()
    {
        cout << "Deleting..." << endl;
        delete[] points; //释放分配的空间
    }
    Point &element(int index)
    {
        assert(index >= 0 && index < size); //获取数组下标，用于访问特定的数组对象
        return points[index];               //此处比较重要的一点是返回的必须要是一个引用，否则调用复制构造函数会创建一个新副本
    }                                       //而我们想要做的却是直接访问这个数据使用引用最好
private:
    Point *points;
    int size;
};

ArrayOfPoints::ArrayOfPoints(const ArrayOfPoints &v) //深层复制构造函数的声明
{
    size = v.size;
    points = new Point[size];
    for (int i = 0; i < size; i++)
    {
        points[i] = v.points[i];
    }
}

int main()
{
    int count;
    cout << "Please enter the count of points: ";
    cin >> count;
    ArrayOfPoints pointsArray1(count);
    pointsArray1.element(0).move(5, 0);
    pointsArray1.element(1).move(15, 20);
    ArrayOfPoints pointsArray2 = pointsArray1;
    cout << "Copy of pointsArray1: " << endl;
    cout << "Point_0 Of array2: " << pointsArray2.element(0).getX() << ", " << pointsArray2.element(0).getY() << endl;
    cout << "Point_1 Of array2: " << pointsArray2.element(1).getX() << ", " << pointsArray2.element(1).getY() << endl;

    pointsArray1.element(0).move(25, 20);
    pointsArray1.element(1).move(35, 40);
    cout << "After the moving of pointsArray1:" << endl;
    cout << "Point_0 Of array2: " << pointsArray2.element(0).getX() << ", " << pointsArray2.element(0).getY() << endl;
    cout << "Point_1 Of array2: " << pointsArray2.element(1).getX() << ", " << pointsArray2.element(1).getY() << endl;
    return 0;
}
