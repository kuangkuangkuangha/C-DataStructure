#include <iostream>
using namespace std;


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
        // 增加新的一天
        void NewDay();

        void display()
        {
            cout<<year<<"-"<<month<<"-"<<day<<endl;
        }

        ~Data()
        {
            cout<<"所有的数据都被清除了"<<endl;
        }

};


// 区别平年和闰年，判断月份有多少天
int Data :: Days(int year, int month)
{
    bool leap;
    if((year%400==0) || (year%100!=0 && year%4==0))
        leap = true;
    else
        leap = false;

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

    return 0;
}

void Data::NewDay()
{
        if(day < Days(month, day))
        {
            cout<<Days(month, day)<<endl;
            day ++;
        }
        else
        {
            cout<<Days(month, day)<<endl;
            month ++;
            day = 1;
            if(month > 12)
            {
                year ++;
                month = 1;
            }
        }   
}

int main()
{
    Data a(2021,11,27);
    a.display();
    a.NewDay();
    cout<<"一天后"<<endl;
    a.display();
}