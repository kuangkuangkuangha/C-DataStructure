#include <iostream>
using namespace std;

class vehicle
{
    public:
        virtual void ShowInfo()=0;
};

class car: public vehicle
{
    private:
        float volume;
        float price;

    public:
        car(float volume, float price)
        {
            this->volume = volume;
            this->price = price;
        }


        void ShowInfo()
        {

            cout<<"小车体积是:"<<volume<<endl;
            cout<<"小车价格是:"<<price<<endl;
        }
};


class truck: public vehicle
{
    private:
        float can; // 负载重量
        float weight; // 自身重量

    public:
        truck(float can, float weight)
        {
            this->can = can;
            this->weight = weight;
        }


        void ShowInfo()
        {
            cout<<"货车负载重量是:"<<can<<endl;
            cout<<"货车自身重量是"<<weight<<endl;
        }
};


class boat: public vehicle
{
    private:
        float water; // 排水量
        float speed; // 海上航行速度

    public:
        boat(float water, float speed)
        {
            this->water = water;
            this->speed = speed;
        }


        void ShowInfo()
        {
            cout<<"轮船体积是:"<<water<<endl;
            cout<<"轮船价格是:"<<speed<<endl;
        }
};

int main()
{
    car a(1,2);
    truck b(3,4);
    boat c(5,6);

    vehicle* pst = &c;
    pst->ShowInfo();

    vehicle* pst2 = &b;
    pst2->ShowInfo();

    vehicle* pst3 = &a;
    pst3->ShowInfo();   

}