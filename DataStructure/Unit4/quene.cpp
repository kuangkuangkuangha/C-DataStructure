#include <iostream>
#include "QueneConfig.cpp"
using namespace std;

int main()
{
    Quene a;
    int e;
    Init(a);


    DeQuene(a, e);

   
    QueneTraverse(a);

    cout<<"e: "<<e<<endl;
    EnQuene(a, e);

    DestroyQuene(a);
}