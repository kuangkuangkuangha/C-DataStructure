#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float x,y;
    cout<<"请输入两个数:"<<endl;
    cin>>x>>y;

    cout<<"计算结果为："<<setprecision(4)<<x/y<<endl;
}