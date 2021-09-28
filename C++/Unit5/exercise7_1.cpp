#include <iostream>
#include <math.h>
using namespace std;

class Atriangle {
    private:
        int a, b, c;
    
    public:
        Atriangle(int A, int B, int C)
        {
            a=A;
            b=B;
            c=C;
        }

        void Area()
        {
            int p = (a+b+c)/2;
            int temp = p*(p-a)*(p-b)*(p-c);
            cout<<"三角形的面积是"<<sqrt(temp)<<endl;
        }

        void And()
        {
            cout<<"三角形的周长是:"<<a+b+c<<endl;
        }
};

int main()
{
    int a, b, c;

    cout<<"请输入三条边长:"<<endl;
    cin>>a>>b>>c;

    class Atriangle temp(a, b, c);
    
    temp.And();
    temp.Area();
}