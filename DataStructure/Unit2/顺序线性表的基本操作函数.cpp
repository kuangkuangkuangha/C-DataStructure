// 顺序线性表的基本操作函数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>
// #include <malloc.h>


#define MAX_SIZE 100;
#define INCREMENT_SIZE 20;

typedef int Elemtype;

typedef struct {
    Elemtype* elem;
    int lenth;
    int max_size;
    int increment_size;
}Sqlink;


//初始化一个新的线性表，且为空表
void Init_Link(Sqlink &L)
{
    L.max_size = MAX_SIZE;
    L.increment_size = INCREMENT_SIZE;
    L.elem = new Elemtype[L.max_size];

    if (!L.elem)
    {
        printf("内存分配出现错误！\n");
        exit(-1);
    }

    L.lenth = 0;
}


//销毁链表
void DestroyList(Sqlink& L)
{
    free(L.elem);
    L.lenth = 0;
    L.max_size = 0;
}




//清除顺序表
void ClearList(Sqlink& L)
{
    L.lenth = 0;
}


//判断是否为空表
bool ListEmpty(Sqlink L)
{
    if (!L.lenth)
        return (true);

    return false;
}




//取元素
Elemtype GetElem(Sqlink L, int i, Elemtype &e)
{
    if (i<1 || i>L.lenth)
    {
        printf("Error of i\n");
        return (-1);
    }
    Elemtype* p = L.elem;
    i--;

    while (i--)
        p++;
    e = *p;
    return e;
}




//取得元素位置
int LocateElem(Sqlink L, Elemtype e)
{
    int i;
    Elemtype* p = L.elem;
    for (i = 1; i <= L.max_size && *p != e; i++, p++);
    if (i > L.max_size) 
    {
        return 0;
    }
    return i;
}

//取前驱元素
void PriorElem(Sqlink L, Elemtype cur_e ,Elemtype& pre_e )
{


    Elemtype* p = L.elem;//指向线性表第一个数据元素
    if (*p == cur_e)
    {
        printf("无前驱元素!\n");
        exit(-1);
    }

    int cout = 1;
    while (cout <= L.lenth - 1 && *(p + 1) != cur_e )
    {
        cout++;
        p++;
    }

    if (cout >= L.lenth)
    {
        printf("在顺序表中找不到输入的数据元素!\n");
        exit(-1);
    }

    pre_e = *p;
}



//插入操作,位置为第n个元素
void Insert_link(Sqlink& L, int n, Elemtype e)
{

    if (n<1 || n>L.lenth + 1)//位次有误
    {
        printf("Error!\n");
        return;
    }


    if (L.lenth == L.max_size)//表满需扩容
    {
        Elemtype* p = new Elemtype[L.max_size + L.increment_size];
        int i;
        for (i = 0; i < L.max_size; i++)
        {
            p[i] = L.elem[i];
        }

        free(L.elem);

        L.elem = p;
        L.elem[i] = e;
        L.max_size += L.increment_size;
        L.lenth++;
        return;
    }



    Elemtype* p,*q;
    q = &L.elem[n - 1];//指向需要插入的位置
    p = &L.elem[L.lenth];//指向L中的最后一个元素的后继

    while (p > q)
    {
        *p = *(p - 1);
        p--;
    }

    *q = e;
    L.lenth++;

}


//删除元素操作
void delete_Elemtype(Sqlink &L, int n, Elemtype &e)
{
    if (n<1 || n>L.lenth)
    {
        printf("Error!\n");
        return;
    }

    int i = n-1;
    e = L.elem[i];

    while (i < L.lenth - 1)
    {
        L.elem[i] = L.elem[i + 1];
        i++;
    }

    L.lenth--;


}



void NextElem(Sqlink L, Elemtype cur_e, Elemtype& next_e)//后继
{
    Elemtype* p = L.elem;
    int len = 1;

    while (*(p + 1) != cur_e&& len < L.lenth)
    {
        p++;
        len++;
    }
    
    if (len >= L.lenth)
    {
        printf("找不到该元素\n");
    }

    next_e = *p;
}


int ListLength(Sqlink L)//长度
{
    return L.lenth;
}

void ListTraverse(Sqlink L)//遍历
{
    Elemtype* p = L.elem;
    int i = 0;
    int cout = 0;

    while (i < L.lenth)
    {
        printf("%d ",p[i]);
        i++;
    }
    printf("\n");
}

#define N 4
#define M 5

/***********************/
/*定义的结构体*/

/*typedef struct {
    Elemtype* elem;
    int lenth;
    int max_size;
    int increment_size;
}Sqlink;*/

int AUB()
{
    Sqlink L;
    int i;
    int *a;
    int *b;
    int na,nb;
    int j;

    printf("请输入A的元素数量:");
    scanf("%d",&na);
    printf("\n");
    a = (int*)malloc(sizeof(int) * na);

    i = 0;
    j = na;
    printf("请输入A集合的元素:");

    while (j--)
    {
        scanf("%d", &a[i]);
        i++;
    }

    printf("/************/\n");
    printf("请输入B的元素数量:");
    scanf("%d", &nb);
    printf("\n");

    b = (int*)malloc(sizeof(int) * nb);
    i = 0;
    j = nb;
    printf("请输入B集合的元素:");

    while (j--)
    {
        scanf("%d", &b[i]);
        i++;
    }


    printf("/************/\n");
    Init_Link(L);
    

    for ( i = 0; i < na; i++)//把A集合赋值给顺序表
        Insert_link(L, L.lenth+1, a[i]);


    for ( i = 0; i < nb; i++)
    {
        if (LocateElem(L, b[i]) == 0)//即找到了不同的元素
        {
            Insert_link(L, L.lenth + 1, b[i]);
        }
    }

    ListTraverse(L);
    DestroyList(L);
    free(a);
    free(b);
    return 0;
}



int AΠB()//交集
{
    int na,nb;
    int i, j;
    int* a, * b;
    Sqlink L;

    printf("请输入A的元素数量:");
    scanf("%d", &na);
    printf("\n");
    a = (int*)malloc(sizeof(int) * na);

    i = 0;
    j = na;
    printf("请输入A集合的元素:");

    while (j--)
    {
        scanf("%d", &a[i]);
        i++;
    }

    printf("/************/\n");
    printf("请输入B的元素数量:");
    scanf("%d", &nb);
    printf("\n");

    b = (int*)malloc(sizeof(int) * nb);
    i = 0;
    j = nb;
    printf("请输入B集合的元素:");

    while (j--)
    {
        scanf("%d", &b[i]);
        i++;
    }

    printf("/************/\n");

    Init_Link(L);

    for (i = 0; i < na; i++)
    {
        Insert_link(L, L.lenth + 1, a[i]);
    }

    Sqlink l;
    Init_Link(l);

    for (i = 0; i < nb; i++)
    {
        if (LocateElem(L, b[i]))
        {
            Insert_link(l, l.lenth + 1, b[i]);
        }
    }

    printf("AΠB = ");
    ListTraverse(l);
    DestroyList(l);
    DestroyList(L);
    free(a);
    free(b);
    



    return 0;

}


int main()//差集
{
    int na, nb;
    int i, j;
    int* a, * b;
    Sqlink L;

    printf("请输入A的元素数量:");
    scanf("%d", &na);
    printf("\n");
    a = (int*)malloc(sizeof(int) * na);

    i = 0;
    j = na;
    printf("请输入A集合的元素:");

    while (j--)
    {
        scanf("%d", &a[i]);
        i++;
    }

    printf("/************/\n");
    printf("请输入B的元素数量:");
    scanf("%d", &nb);
    printf("\n");

    b = (int*)malloc(sizeof(int) * nb);
    i = 0;
    j = nb;
    printf("请输入B集合的元素:");

    while (j--)
    {
        scanf("%d", &b[i]);
        i++;
    }

    printf("/************/\n");

    Init_Link(L);

    for (i = 0; i < na; i++)
    {
        Insert_link(L, L.lenth + 1, a[i]);
    }

    int tag;
    Elemtype e;
    for (i = 0; i < nb; i++)
    {
        if (LocateElem(L, b[i]))
        {
            tag = LocateElem(L,b[i]);
            delete_Elemtype(L,tag,e);
        }
    }

    printf("A-B:");
    ListTraverse(L);
    return 0;


}