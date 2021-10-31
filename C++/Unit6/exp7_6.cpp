#include <iostream>
using namespace std;



class Clock
{
    int h;
    int m;
    int s;

    public:
        Clock(int h, int m, int s)
        {   
            this->h = h > 23 ? 0 : h;
            this->m = m > 59 ? 0 : m;
            this->s = s > 59 ? 0 : s;
        }

        int GetHour()
        {
            return h;
        }

        int GetMinute()
        {
            return m;
        }

        int GetSecond()
        {
            return s;
        }

        void Run();

        void ShowTime()
        {
            cout<<h<<":"<<m<<":"<<s<<endl;
        }
};

void  Clock :: Run()
{
    s ++;
    if(s > 59)
    {
        s=0;
        m++;
    }

    if(m > 59)
    {
        m=0;
        h++;
    }

    if(h > 23)
        h=0;

}


class Data
{
    private:
        int year;
        int month;
        int day;
        
    public:
    // 构造函数
        Data(int year, int month, int day)
        {
            if(month>12 || month<1)
            {
                cout<<"没有这个月份"<<endl;
            }

            if(day > 31)
                cout<<"没有这天"<<endl;

            this->year = year;
            this->month = month;
            this->day = day;
        }

        // 判断天数是否有效
        int Days(int year, int month);
        void NewDay();

        void display()
        {
            cout<<year<<"-"<<month<<"-"<<day<<endl;
        }

};

int Data :: Days(int year, int month)
{
    bool leap;
    if((year%400==0) && (year%100!=0 && year%4==0))
        return true;
    else
        return false;

    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;

        case 2:
            if(year)
                return 29;
            else    
                return 28;
            break;
    }

}

void Data::NewDay()
{
        if(day < Days(month, day))
        {
            day ++;
        }
        else
        {
            month ++;
            day = 1;
            if(month > 12)
            {
                year ++;
                month = 1;
            }
        }   
}


class ClockWithData: public Clock, public Data
{

    public:
        ClockWithData(int year, int month, int day, int h, int m, int s):Data(year, month, day), Clock(h, m, s)
        {
        }

        void Run()
        {
            Clock::Run();
            if(GetHour()==0 && GetMinute()==0 && GetSecond()==0)
            {
                 NewDay();
            }
        }

        void ShowTime()
        {
            Clock::ShowTime();
            Data::display();
        }
};

int main()
{
    ClockWithData a(2020, 12, 31, 23, 59, 59);
    a.ShowTime();

    for(int i=0; i<1; i++)
    {
        a.Run();
    }

    cout<<"after 1 s:"<<endl;
    a.ShowTime();

    return 0;
}