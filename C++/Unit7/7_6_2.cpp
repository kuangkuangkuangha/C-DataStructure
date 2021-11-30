#include <iostream>
using namespace std;

class Location
{
    private:
        int x;
        int y;

    public:
        Location(int x, int y)
        {
            this->x = x;
            this->y = y;
        }

        void Show()
        {
            cout<<"现在的位置是:"<<x<<","<<y<<endl;
        }

        Location operator + (Location point);
        Location operator - (Location point);
};

// 重载点的加法运算
Location Location::operator + (Location point)
{
    return Location(x+point.x, y+point.y);
}

// 重载点的加法运算
Location Location::operator - (Location point)
{
    return Location(x-point.x, y-point.y);
}


int main()
{
    Location point1(1, 1);
    Location point2(3, 6);

    Location res =  point1.operator+(point2);
    res.Show();

    Location res2 = point1.operator-(point2);
    res2.Show();
}