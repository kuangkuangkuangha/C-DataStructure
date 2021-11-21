#include <iostream>
// 顺序队列
// #include "../Unit4/QueneConfig.cpp"
using namespace std;

typedef struct Sql_Quene
{
    char* elem;
    int front;
    int rear;
    int queneSize;
}Quene;

typedef struct Sql_Stack
{
    char* elem;
    int top;
    int stackSize;
}Stack;

// 初始化队列
void InitQuene(Quene& Q)
{
    Q.elem = new char[10];
    Q.front = 0;
    Q.rear = 0;
}


// 入队
void EnQuene(Quene& Q, char e)
{
    Q.elem[Q.rear] = e;
    Q.rear ++;
}

// 出队
void DeQuene(Quene& Q, char& e)
{
    e = Q.elem[Q.front];
    Q.front ++;
}

// 输出队列元素
void TraverseQuene(Quene& Q)
{
    int start = Q.front;
    int end = Q.rear;
    while(start != end)
    {
        cout<<Q.elem[--end]<<" ";
    }
    cout<<endl;
}

void GetQueneHead(Quene& Q, char& e)
{
    e = Q.elem[Q.front++];
}

// ********** Stack **************
void InitStack(Stack& S)
{
    S.elem = new char [10];
    S.top = -1;
}

void Push(Stack& S, char e)
{
    S.elem[++S.top] = e;
}

void Pop(Stack& S, char& e)
{
    S.elem[--S.top] = e;
}

int StackEmpty(Stack& S)
{
    if(S.top>=0)
        return 1;
    
    return 0;
}

void GetStackTop(Stack& S, char& e)
{
    if(S.top<0)
    {
        cout<<"栈已经空了"<<endl;
    }

    e = S.elem[--S.top];
}


void Input(Quene& QP, Quene QS)
{
    char a;
    cout<<"请输入你要判断的序列:"<<endl;
    cin>>a;
    while(a!='#')
    {
        EnQuene(QP, a);
        cin>>a;
    }
    TraverseQuene(QP);

    cout<<"请输入你要输入的序列:"<<endl;
    char b;
    cin>>b;
    while(b!='#')
    {
        EnQuene(QS, b);
        cin>>b;
    }

    TraverseQuene(QS);
}

void Work()
{
    Quene a;
    Quene b;
    Stack S;
    char e;

    InitQuene(a);  // 被判断的
    InitQuene(b);  // 输入的

    Input(a, b);

    InitStack(S);

    DeQuene(b, e);
    Pop(S, e);

    char Ahead;
    char Bhead;
    GetQueneHead(a, Ahead);

    while(!StackEmpty(S))
    {
        do
        {
            DeQuene(b, Bhead);
            Push(S, Bhead);

        }while(Ahead!=Bhead);

        
    }

}

int main()
{
    Work();
}