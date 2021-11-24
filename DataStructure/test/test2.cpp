#include <iostream>
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
    Q.elem = new char[20];
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
char DeQuene(Quene& Q)
{
    return Q.elem[Q.front++];
}

// 输出队列元素
void TraverseQuene(Quene& Q)
{
    int start = Q.front;
    int end = Q.rear;
    while(start != end)
    {
        cout<<Q.elem[start++]<<"*";
    }
    cout<<endl;
}

void GetQueneHead(Quene& Q, char& e)
{
    e = Q.elem[Q.front++];
}

int QueneEmpty(Quene& Q)
{
    if(Q.front == Q.rear)
        return 1;

    return 0;
}

// ********** Stack **************
void InitStack(Stack& S)
{
    S.elem = new char [20];
    S.top = -1;
}

void Push(Stack& S, char e)
{
    S.elem[++S.top] = e;
}

char Pop(Stack& S)
{
    return S.elem[--S.top];
}

int StackEmpty(Stack& S)
{
    if(S.top < 0)
        return 1;
    
    return 0;
}

char GetStackTop(Stack& S)
{
    int a=S.top;
    if(S.top<0)
    {
        cout<<"栈已经空了"<<endl;
    }

    return S.elem[a];
}

void StackTraverse(Stack& S)
{
    cout<<"输出栈元素:"<<endl;
    int a = S.top;
    while(a >= 0)
    {
        cout<<S.elem[a--]<<" ";
    }
    cout<<endl;
}


void Input(Quene& QP)
{
    char a;
    cout<<"请输入你的序列:"<<endl;
    cin>>a;
    while(a!='#')
    {
        EnQuene(QP, a);
        cin>>a;
    }
}

void Work()
{
    Quene a;
    Quene b;
    InitQuene(a); // 输入序列
    InitQuene(b); // 判断序列

    Input(a);
    Input(b);
    TraverseQuene(a);
    TraverseQuene(b);

    Stack s;
    InitStack(s);

    char temp;
    char s_top;
    char E;

    int i=0;
    while(!QueneEmpty(a) || (QueneEmpty(a) && !QueneEmpty(b)))
    {
        E = DeQuene(b);  // 从判断序列中取出一个数进行判断
        // cout<<"取出来的字符是:"<<E<<endl;

        if(!StackEmpty(s))
        {
            s_top = GetStackTop(s);
            // cout<<"栈顶字符是:"<<s_top<<endl;
            // cout<<"栈中元素有:"<<endl;
            StackTraverse(s);
            if( s_top==E )          // 如果一开始进来栈不空，可以看看栈顶元素是不是判断要判断的字母
            {
                Pop(s);
                continue;
            }
        }

        do
        {
            if(QueneEmpty(a))
                break;
            temp = DeQuene(a);
            // cout<<"a出栈字符是:"<<temp<<endl;
            // cout<<temp<<"***"<<endl;
            Push(s, temp);
            // cout<<"入站元素是:"<<s.elem[0]<<endl;
        } while (temp != E);

        if(GetStackTop(s)==E)
            Pop(s);

    }

    if(StackEmpty(s))
        cout<<"its ok!"<<endl;
    else
        cout<<"not ok!"<<endl;
}


int main()
{
    Work(); // 一个小BUG，fedcba 和 cbadfe 没法判断  (现在修好了)
}