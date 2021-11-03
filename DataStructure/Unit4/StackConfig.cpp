#include <iostream>
using namespace std;

struct Stack 
{
    int* elem;
    int top;
    int stacksize;
    int incrementsize;
};

// 初始化空栈
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

// 输出栈中的所有元素
void Traverse(Stack* temp)
{
    int a = temp->top;
    while(a >= 0)
    {
        cout<<temp->elem[a--]+1<<" ";
    }
    cout<<endl;
}

// 销毁栈
void DestroyStack(Stack* temp)
{
    delete [] temp->elem;
    temp->top = -1;
}

// 栈的长度
int StackLength(Stack* temp)
{   
    if(!StackEmpty(temp))
    {
        cout<<"栈为空栈"<<endl;
        return -1;
    }
    return temp->top+1;
}

// 获得栈顶元素
void GetTop(Stack* temp, int& e)
{
    e = temp->elem[temp->top];
}