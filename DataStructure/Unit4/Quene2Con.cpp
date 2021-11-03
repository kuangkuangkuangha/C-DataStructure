#include <iostream>
using namespace std;
// 顺序队列（数组）
//  front <- 1 2 3 4 5 6 <- rear

struct SqQuene
{
    int* elem;
    int front;
    int rear;
    int quenesize;      // 数组的大小（就是元素的个数 + 1个不用的空间）
    int incrementsize;
};

typedef struct SqQuene Quene;

// 初始化循环队列
void InitQuene(Quene& Q, int maxsize)  // maxsize 是元素的个数
{
    Q.elem = new int [maxsize];
    Q.quenesize = maxsize+1;           
    Q.front = Q.rear = 0;
}

// 扩容函数(已经队满了)
void IncrementQuenesize(Quene& Q)
{
    int a[Q.quenesize+Q.incrementsize];

    for(int i=0; i<Q.quenesize-1; i++)
    {   
        a[i] = Q.elem[(Q.front+i)%Q.quenesize];
    }

    delete [] Q.elem;

    Q.elem = a;
    Q.front = 0;
    Q.rear = Q.quenesize-1; // 已经队满了，所以Q.rear 一定在Q.quenesize-1;
}

// 返回元素的个数
int QueneLength(Quene& Q)
{   
    return (Q.rear-Q.front+Q.quenesize)%Q.quenesize;
}

// 出队列
bool DeQuene(Quene& Q, int& e)
{
    if(Q.front == Q.rear)
        return false;

    e = Q.elem[Q.front];
    Q.front = (Q.front+1)%Q.quenesize;
    
        return true;
}

// 入队列
void EnQuene(Quene& Q, int e)
{
    // 增加容量

    Q.elem[Q.rear] = e;
    Q.rear = (Q.rear+1)%Q.quenesize;
}

// 输出队列的全部元素
void QueneTraverse(Quene& Q)
{
    int end=Q.rear;
    for(int i=Q.front; i<(end+Q.quenesize)%Q.quenesize; i++)
    {
        cout<<Q.elem[i]<<" ";
    }
}

// 获取队头元素
void GetQueneHead(Quene& Q, int& e)
{
    e = Q.elem[Q.front];
}

void Yanghui(int n)
{
    // 打印输出杨辉三角的前n（n>0）行
    Quene Q;
    for(int i=0; i<n; i++)
    {   
        cout<<' ';
    }
    cout<<'1'<<endl;
    InitQuene(Q, n+2);
    EnQuene(Q, 0);
    EnQuene(Q, 1);
    EnQuene(Q, 1);
    int k = 1;
    int s;
    int e;

    while(k<n)
    {
        for(int i=0; i<n-k; i++)
            cout<<' ';
        
        EnQuene(Q, 0);
        
        do{
            DeQuene(Q, s);
            GetQueneHead(Q, e);
            if(e)
                cout<<e<<' ';
            else
                cout<<endl;

            EnQuene(Q, s+e);
        }while(e!=0);

        k++;
    };

    DeQuene(Q, e);

    while ((Q.rear+1)%Q.quenesize == Q.front)  // 如果非空
    {
        DeQuene(Q, e);
        cout<<e<<' ';
    }
}


int main()
{

    Yanghui(5);
    // Quene temp;
    // int e;
    // InitQuene(temp, 10);
    // EnQuene(temp, 1);
    // EnQuene(temp, 2);
    // EnQuene(temp, 8);

    // QueneTraverse(temp);

    // DeQuene(temp, e);

    // QueneTraverse(temp);
}