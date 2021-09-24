#include <iostream>
#include "ArrayConfig.cpp"  //把库函数写到一个文件里，这是自己写的，函数都在里面
using namespace std;


void BingJi()
{
    SqList La, Lb;

    Init(&La, &Lb);
    int e;

    int La_len = ListLength(La);
    while(ListEmpty(&Lb)==false)
    {
        ListDelete(&Lb, 1, &e);

        if(!LocateElem(La, e))
        {
            ListInsert(&La, ++La_len, e);
        }
    }

    DestroyList(&Lb);
    cout<<"并集结果是："<<endl;
    ListTraverse(La);
}

void JiaoJi()
{
    SqList La, Lb;
    Init(&La, &Lb);

    SqList Lc;
    Lc.elem = new int[10];
    int count=0;

    
        for(int i=0; i<Lb.length; i++)
        {
            if(LocateElem(La, Lb.elem[i]))
            {
                Lc.elem[count++]=Lb.elem[i];
            }
        }

    Lc.length = count;
    cout<<"交集结果是:"<<endl;
    ListTraverse(Lc);
}

void ChaJi()
{
    SqList La,Lb;

    SqList Lc;
    int count=0;
    Init(&La, &Lb);

    for(int i=0; i<La.length; i++)
    {
        if(!LocateElem(Lb, La.elem[i]))
        {
            Lc.elem[count++]=La.elem[i];
        }
    }

    for(int j=0; j<Lb.length; j++)
    {
        if(!LocateElem(La, Lb.elem[j]))
        {
            Lc.elem[count++]=Lb.elem[j];
        }
    }

    Lc.length=count;

    cout<<"差集结果是："<<endl;
    ListTraverse(Lc);
}


int main()
{
    ChaJi();
}



