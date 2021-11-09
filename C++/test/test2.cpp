#include <iostream>
using namespace std;

class Point
{
    private:
        int x,y;

    public:
        Point(int x, int y)
        {
            this->x = x;
            this->y = y;
        }

        void Area()
        {
            cout<<"点的表面积为0:"<<endl;
        }

        ~Point()
        {
            cout<<"数据已经被清空了"<<endl;
        }
};

class Circle: public Point
{
    private:
        int radius;

    public:
        Circle(int x, int y, int radius):Point(x, y)
        {
            this->radius = radius;
        }

        // 显示面积
        void ShowArea()
        {
            cout<<"圆的面积为:"<<3.14*radius*radius<<endl;
        }

        // 返回面积
        float Area()
        {
            return 3.14*radius*radius;
        }


        // 求圆的周长
        float Long()
        {
            return 3.14*2*radius;
        }

        ~Circle()
        {
            cout<<"数据已经被清空了"<<endl;
        }

};

class Cylinder: public Circle
{
    private:
        int height;
    
    public:
        Cylinder(int x, int y, int radius, int height): Circle(x, y, radius)
        {
            this->height = height;
        }

        void Area()
        {
            cout<<"圆柱的表面积是:"<<Circle::Long()*height + Circle::Area()<<endl;
        }
};

int main()
{

    class Point a(0,0);
    class Circle b(0,0,2);
    class Cylinder c(0,0,2,4);
    a.Area();
    b.ShowArea();
    c.Area();
}