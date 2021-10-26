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
            this->h = h;
            this->m = m;
            this->s = s;
        }

        void ShowTime()
        {
            cout<<h<<":"<<m<<":"<<s<<endl;
        }
};

class NewClock: public Clock
{
    int temp;
    int mm;
    int ss;
    public:
        NewClock(int h, int m, int s):Clock(h, m, s)
        {
            temp = h;
            mm = m;
            ss = s;
        }

        void Show()
        {
            if(temp < 12)
            {
                cout<<temp<<":"<<mm<<":"<<ss<<endl<<"AM"<<endl;
            } 
            else
            {
                cout<<temp-12<<":"<<mm<<":"<<ss<<"PM"<<endl;
            }  
        }
};

int main()
{
    class NewClock nc(20,34,11);
    nc.Show();
}