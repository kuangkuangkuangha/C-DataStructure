#include <iostream>
using namespace std;

struct Stack 
{
    int* elem;
    int top;
};

void InitStack(Stack* temp)
{
    temp->elem = new int[20];
    temp->top = -1;
}

// 清空栈
void ClearStack()
{
    
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