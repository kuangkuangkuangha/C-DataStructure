#include <iostream>
#include "config.cpp"
using namespace std;
const int LIST_INIT_SIZE=5;
const int LISTINCREMENT=10;
#define ElemType int

typedef struct 
{
    ElemType *elem;
    int length;
    int listsize;
    int incrementsize;
}SqList;

// 初始化线性表
void InitList_Sq(SqList* temp)
{
    temp->elem = new ElemType(LIST_INIT_SIZE);
    temp->length = 5;
    temp->listsize = LIST_INIT_SIZE;
    temp->incrementsize = LISTINCREMENT;
}

// 定位元素的位置
int LocateElem(SqList temp, ElemType e)
{
    int addr=1;
    int*p = temp.elem;

    while(*p!=e && addr<=temp.length)
    {
        p++;
        addr++;
    }

    if(addr <= temp.length)
        return addr;
    else
        return 0;
}

// 销毁链表
void DestroyList(SqList* temp)
{
    delete[] temp->elem;
    temp->length=0;
    temp->listsize=0;
}

// 插入一个元素
void InsertList_Sq(SqList* temp, int addr, ElemType e)
{

    if(addr<1 || addr>temp->length+1)
    {
        ErrorMessage("插入的位置不合法！");
    }

    if(temp->length > temp->listsize)
        increment(temp);

    ElemType* move = &temp->elem[temp->length-1];
    ElemType* dest = &temp->elem[addr-1];
    for(;move>=dest; move--)
    {
        *(move+1)=*move;
    }
    *move = e;

    temp->length++;

}

void increment(SqList* temp)
{
    ElemType* newArray = new ElemType[LIST_INIT_SIZE+LISTINCREMENT];
    for(int i=0; i<temp->length; i++)
        newArray[i] = temp->elem[i];

    delete temp->elem;
    temp->elem = newArray;
    temp->listsize+=temp->incrementsize;
}


// 删除元素操作
void DeleteList_Sq(SqList* temp, int addr)
{
    ElemType* move=&temp->elem[addr];
    ElemType* dest=&temp->elem[temp->length-1];

    for(; move<dest; move++)
    {
        *(move-1)=*move;
    }

    temp->length--;
}


int main()
{
    SqList haha;
    InitList_Sq(&haha);
    haha.elem[0]=6;
    haha.elem[1]=5;

    cout<<LocateElem(haha, 6)<<endl;

}

