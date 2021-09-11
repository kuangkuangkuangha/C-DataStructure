#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float num1,num2,num3;
    cout<<"Please enter 3 nums:"<<endl;
    cin>>num1>>num2>>num3;
    cout<<setw(30);
    cout<<"The average of 3 nums is:"<<setw(20)<<(num1+num2+num3)/3<<endl;
    return 0;
}

