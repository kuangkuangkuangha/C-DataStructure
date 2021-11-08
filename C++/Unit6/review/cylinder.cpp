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

        void PointShow()
        {   
            cout<<"圆心为:"<<x<<y<<endl;
        }

        void SHow() const
        {
            cout<<x<<y<<endl;
        }
};

class Circle: protected Point
{
    private:
        int radius;

    public:
        Circle(int x, int y, int radius): Point(x, y)
        {
            this->radius = radius;
        }   

        void Show()
        {
            Point::PointShow();
            cout<<"圆的半径是:"<<endl;
        }
};

class Cylinder: protected Circle
{
    private:
        int high;

    public:
        Cylinder(int x, int y, int radius,  int high): Circle(x, y,radius)
        {
            this->high = high;
        }
        
        void Show()
        {
            Point::PointShow();
            cout<<"圆柱的高是:"<<high<<endl;
        }
};

int main()
{
    Circle a(2,4, 6);

    const Point po(3,4);

    
}