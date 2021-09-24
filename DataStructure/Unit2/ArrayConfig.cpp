#include <iostream>

using namespace std;
const int LIST_INIT_SIZE=100;
const int LISTINCREMENT=10;
#define ElemType int

typedef struct 
{
    ElemType *elem;
    int length;
    int listsize;
    int incrementsize;
}SqList;

void Init(SqList* La, SqList* Lb)
{
    La->elem=new int[100];
    Lb->elem=new int[100];

    int a,b;
    cout<<"请输入第一个集合的元素个数:"<<endl;
    cin>>a;
    cout<<endl;

    La->length=a;
    for(int i=0; i<a; i++)
    {
        cin>>La->elem[i];
    }

    cout<<"请输入第二个集合的元素个数:"<<endl;
    cin>>b;
    cout<<endl;

    Lb->length=b;
    for(int j=0; j<b; j++)
    {
        cin>>Lb->elem[j];
    }
}

// 初始化线性表
void InitList(SqList* temp, int len)
{
    temp->elem = new ElemType(LIST_INIT_SIZE);
    temp->length = len;
    temp->listsize = LIST_INIT_SIZE;
    temp->incrementsize = LISTINCREMENT;
}



// 销毁线性表
void DestroyList(SqList* temp)
{
    delete[] temp->elem;
    temp->length=0;
    temp->listsize=0;
}

// 将L置为空表
void ClearList(SqList* temp)
{
    temp->length=0;
}

bool ListEmpty(SqList* temp)
{
    if(temp->length>0)
        return false;
    else    
        return true;
}

// 返回线性表的元素个数
int ListLength(SqList temp)
{
    return temp.length;
}

// 返回L中第i个元素的值
int GetElem(SqList temp, int i)
{
    return temp.elem[i-1];
}

// 定位元素的位置  返回元素的位置，第1，2，3，4个
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

// 返回一个元素的前驱
int PriorElem(SqList temp, int cur_e)
{
    int pre_e, j;
    for(int i=0; i<temp.length; i++)
    {
        if(temp.elem[i] == cur_e)
        {
            j=i-1;
        }
    }

    if(j<0)
        return -1;
    else
        return temp.elem[j];

    return -1;
}

// 返回一个元素的后继
int NextElem(SqList temp, int cur_e)
{
        int pre_e, j;
    for(int i=0; i<temp.length; i++)
    {
        if(temp.elem[i] == cur_e)
        {
            j=i+1;
        }
    }

    if(j > temp.length-1)
        return -1;
    else
        return temp.elem[j];

    return -1;
}


// 插入一个元素, 插在第 addr 个位置前, 不是数组下标
void ListInsert(SqList* temp, int addr, ElemType e)
{

    if(addr<1 || addr>temp->length+1)
    {
        return ;
    }

    // if(temp->length > temp->listsize)
    //     increment(temp);

    ElemType* move = &temp->elem[temp->length-1];
    ElemType* dest = &temp->elem[addr-1];
    for(;move>=dest; move--)
    {
        *(move+1)=*move;
    }
    *(move+1) = e;

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


// 删除元素操作    删除第i个元素
void ListDelete(SqList* temp, int i, int *e)
{
    int* move=&temp->elem[i-1];
    int* dest=&temp->elem[temp->length-1];
    *e = temp->elem[i-1];

    for(; move<dest; move++)
    {
        *move=*(move+1);
    }

    temp->length--;
}

// 输出线性表中每一元素
void ListTraverse(SqList temp)
{
    for(int i=0; i<temp.length; i++)
    {
        cout<<temp.elem[i]<<endl;
    }
}