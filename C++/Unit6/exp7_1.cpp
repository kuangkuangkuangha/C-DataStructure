#include <iostream>
using namespace std;

class Point
{
    private:
        float x;
        float y;

    public: 
        Point(float x, float y)
        {
            this->x = x;
            this->y = y;
            
        }

        void Show()
        {
            cout<<"x: "<<x<<" y: "<<y<<endl;
        }
};

// 继承Point类
class Rectangle:public Point
{
    private: 
        float height;
        float width;

    public:
        Rectangle(int x, int y, int width, int height):Point(x, y)  // 使用
        {
            this->width = width;
            this->height = height;
        }

        void Area()
        {
            cout<<"长方形的面积是:"<<height*width<<endl;
        }

};


class Circle:public Point
{
    private:
        float r;
    
    public:
        Circle(float x, float y, float r):Point(x, y) // 对派生类的基类进行初始化 
        {
            this->r = r;
        }

        void Area()
        {
            cout<<"圆的面积是:"<<3.14*r*r<<endl;
        }
};


int main()
{
    class Rectangle door(1, 2, 3, 4);
    door.Area();
    door.Show();

    class Circle ball(0, 0, 5);
    ball.Area();
    ball.Show();
}