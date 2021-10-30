#include <iostream>
using namespace std;

struct Stack 
{
    int* elem;
    int top;
    int stacksize;
    int incrementsize;
};

void InitStack(Stack* temp)
{
    temp->elem = new int[20];
    temp->top = -1;
    temp->stacksize = 20;
}

// 清空栈
void ClearStack(Stack* temp)
{
    temp->top = -1;
}

// 判断栈是否为空
bool StackEmpty(Stack* temp)
{
    if(temp->top >= 0)
    {
        return false;
    }

    return true;
}

// 插入元素e为新的栈顶
void Push(Stack* temp, int e)
{
    if(temp->top>19)
    {   
        cout<<"StackOverflow~"<<endl;
    }
    temp->elem[++temp->top] = e;
}

// 删除栈的栈顶元素并用e返回其值
void Pop(Stack* temp, int* e)
{
    if(temp->top<0)
    {
        cout<<"StackUnderflow~"<<endl;
        return;
    }

    *e = temp->elem[temp->top--];
}

void Traverse(Stack* temp)
{
    int a = temp->top;
    while(a >= 0)
    {
        cout<<temp->elem[a--]<<" "<<endl;
    }
}