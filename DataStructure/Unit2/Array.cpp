#include <iostream>
#include "ArrayConfig.cpp"
using namespace std;


void JiaoJi(SqList la, SqList lb)
{
    SqList lc;
    lc.elem = new int[10];
    int count=0;

    for(int i=0; i<la.length; i++)
    {
        int e=la.elem[i];
        if(LocateElem(lb, e))
        {
            lc.elem[count++]=e;
        }
    }

    lc.length=count;

    cout<<"交集结果是:";
    ListTraverse(lc);
    // cout<<">";
}


void BingJi(SqList la, SqList lb)
{

    int Len = lb.length;
    for(int i=0; i<la.length; i++)
    {
        int e=la.elem[i];
        if(!LocateElem(lb, e))
        {
            ListInsert(&lb, ++Len, e);
        }
    }

    cout<<"并集结果是:";
    ListTraverse(lb);
    // cout<<">";
}


void ChaJi(SqList la, SqList lb)
{
    SqList lc;
    lc.elem = new int[10];
    int count=0;

    for(int i=0; i<la.length; i++)
    {
        if(!LocateElem(lb, la.elem[i]))
        {
            lc.elem[count++]=la.elem[i];
        }
    }

    lc.length=count;

    cout<<"差集结果是：";
    ListTraverse(lc);
    // cout<<">";
}


int main()
{
    SqList La, Lb;
    Init(&La, &Lb);

    cout<<"*************Result*************"<<endl;
    cout<<"A = ";
    ListTraverse(La);
    cout<<"B = ";
    ListTraverse(Lb);
    JiaoJi(La, Lb);
    BingJi(La, Lb);
    cout<<endl;

    cout<<"A-B:"<<endl;
    ChaJi(La, Lb);

    cout<<endl;
    cout<<"B-A:"<<endl;
    ChaJi(Lb, La);
    cout<<"*********************************"<<endl;
}



