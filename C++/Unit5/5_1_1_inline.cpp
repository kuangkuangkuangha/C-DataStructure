#include <iostream>
using namespace std;

class clock
{
    private:
        int H,M,S;
    
    public:
        void SetTime(int h,int m,int s);
        void ShowTime();
};

inline void clock :: SetTime(int h, int m, int s)
{
    H=h;
    M=m;
    S=s;
}

inline void clock :: ShowTime()
{
    cout<<H<<":"<<M<<":"<<S<<endl;
}


int main()
{
    class clock watch;
    watch.ShowTime();
    watch.SetTime(8,30,30);
    watch.ShowTime();
}