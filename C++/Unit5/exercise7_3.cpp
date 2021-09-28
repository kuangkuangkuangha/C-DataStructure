#include <iostream>
using namespace std;

class CData {
    private:
         int year, month, day;

    public:
        CData(int year, int month, int day)
        {
            this->year = year;
            this->month = month;
            this->day = day;
        }

        void NewDay();
 

        void ShowData()
        {
            cout<<year<<":"<<month<<":"<<day<<endl;
        }
};


void CData:: NewDay()
{
    if(year%4==0 && year%100!=0)
    {
        if(month==2 && day==29)
        {
            day=1;
            month=3;
        }
    }
    else
    {
        if(month==12 && day==31)
        {
            year++;
            month=1;
            day=1;
        }

        if(month==4||month==6||month==9||month==11 && day==30)
        {
            month++;
            day=1;
        }
        else if(month==1&&month==3&&month==5&&month==7&&month==8&&month==10&&day==31)
        {
            month++;
            day=1;
        }
        else if(month==12&&day==31)
        {

        }
        else
        {
            day++;
        }
    }
}


int main()
{
    class CData a(2022, 12, 31);
    a.NewDay();
    a.ShowData();
}