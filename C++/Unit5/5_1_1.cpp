#include <iostream>
using namespace std;

struct clock
{
    int H,M,S;
};

struct clock watch;

void SetTime(int h, int m, int s)
{
    watch.H=h;
    watch.M=m;
    watch.S=s;
}

void ShowTime()
{
    cout<<watch.H<<":"<<watch.M<<":"<<watch.S<<endl;
}

int main()
{
    ShowTime();
    SetTime(8,30,30);
    ShowTime();
}