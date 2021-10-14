#include <iostream>
// #include "C-"
using namespace std;

 // f(x)=a0+a1*x+a2*x*x 。。。
int exci(int x, int n, int* a)
{
    int temp;
    int sum =0;

    for(int j=0; j<=n; j++)
    {
        temp=1;
        temp=temp*a[j];
        for(int k=0; k<j; k++)
        {
            temp=temp*x;
        }
        sum=sum+temp;
    }

    return sum;
}




int main()
{
    int x=2;
    int n=3;
    int a[4]={3,5,6,4};

    cout<<exci(x,n,a)<<endl;
}