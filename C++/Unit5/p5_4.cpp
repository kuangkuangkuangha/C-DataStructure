#include <iostream>
using namespace std;

// 构造拷贝构造函数
class clock 
{
    private:
        int H,M,S;

    public:
        clock()
        {
            H=0;
            M=0;
            S=0;
            cout<<"调用了第一个构造函数"<<endl;
        }

        clock(const char* str)
        {
            cout<<"调用了第二个构造函数："<<str<<endl;
        }

        ~ clock()
        {
            cout<<"调用了析构函数：对象已经被清除了"<<endl;
        }

        // 拷贝构造函数
        clock(clock & p)
        {
            H=p.H;
            M=p.M;
            S=p.S;
            cout<<"调用了拷贝构造函数"<<endl;
        }

        void ShowTime()
        {
            cout<<H<<":"<<M<<":"<<S<<endl;
        }
};

class clock fun(class clock c)
{
    return c;
}

int main()
{

    class clock c2("程御文");
    c2.ShowTime();  //乱

    class clock c1;
    c1.ShowTime();  //0:0:0

    class clock c3=c2;  //

    fun(c2);
}