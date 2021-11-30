#include <iostream>
using namespace std;

class shape
{
    public:
        virtual int area() = 0;
};

class Rectangle: public shape
{
    private:
        int a, b;
    
    public:
        Rectangle(int a, int b)
        {
            this->a = a;
            this->b = b;
        }

        int area()
        {
            return a*b;
        }
};

class Circle: public shape
{
    private:
        int r;
    
    public:
        Circle(int r)
        {
            this->r = r;
        }

        int area()
        {
            return 3.14*r*r;
        }
};

int main()
{
    Rectangle a(3, 5);
    Circle b(4);

    shape* pst1 = &a;
    shape* pst2 = &b;

    cout<<"长方形的面积是:"<<pst1->area()<<endl;
    cout<<"圆的面积是:"<<pst2->area()<<endl;
}