#include <iostream>
#include <math.h>
using namespace std;

class Point {

    private:
        int x, y;

    public:
        Point(int x, int y)
        {
            this->x = x;
            this->y = y;
        }


        void Distance(class Point *p)
        {
            int temp = pow(x-p->x, 2) + pow(y-p->y, 2);
            cout<<"两点之间的距离是:"<<sqrt(temp)<<endl;
        }
};

int main()
{
    class Point a(0,0);
    class Point b(3,4);

    a.Distance(&b);
}