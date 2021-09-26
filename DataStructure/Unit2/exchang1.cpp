#include <iostream>
using namespace std;

void invert(int* p, int m, int n)
{
    int temp;
    while(m<n)
    {
        temp = p[m];
        p[m] = p[n];
        p[n] = temp;

        m++;
        n--;
    }
}

int main()
{
    int a[]={0,1,2,3,4,5};
    invert(a,0,3);

    for(int i=0; i<6; i++)
    {
        printf("%d\n", a[i]);
    }
}