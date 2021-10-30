#include <iostream>
using namespace std;

class Data
{
    int year;
    int month;
    int day;
    public:
        Data(int year, int month, int day)
        {
            this->year = year;
            this->month = month;
            this->day = day;
        }

        void Show()
        {
            cout<<year<<"-"<<month<<"-"<<day;
        }

};


class Clock
{
    int h;
    int m;
    int s;

    public:
        Clock(int h, int m, int s)
        {   
            this->h = h;
            this->m = m;
            this->s = s;
        }

        void ShowTime()
        {
            cout<<h<<":"<<m<<":"<<s<<endl;
        }
};

class ClockWithData: public Clock, public Data
{

    public:
        ClockWithData(int year, int month, int day, int h, int m, int s):Data(year, month, day), Clock(h, m, s)
        {
        }

        void InSecond()
        {
            
        }
};

int main()
{

}