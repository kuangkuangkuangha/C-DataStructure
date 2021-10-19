#include <iostream>
using namespace std;
// 头节点不存数据

struct LinkList
{
    int data;
    struct LinkList* next;
};

typedef struct LinkList Node;

struct LinkQuene
{
    Node* front;
    Node* rear;
};

typedef struct LinkQuene Quene;

// 初始化队列
void Init(Quene& temp)
{
    int num;
    int a[20];
    temp.front = temp.rear = new Node;
    temp.front->next = NULL;

    cout<<"请输入队列元素的个数:"<<endl;
    cin>>num;
    cout<<"开始输入数据:"<<endl;
    for(int i=0; i<num; i++)
    {
        cin>>a[i];
    }

    Node* cur = temp.front;

    for(int i=0; i<num; i++)
    {
        Node* temp = new Node;
        temp->data = a[i];

        cur->next = temp;
        cur = temp;
    }

    cur->next = NULL;

    temp.rear = cur;
}  


// 插入元素e为链队列temp中新的队尾元素(入队)
// eg:1 2 3 4 -> 1 2 3 4 5
void EnQuene(Quene& temp, int e)
{
    Node* mid = new Node;
    mid->data = e;
    mid->next = NULL;

    temp.rear->next = mid;
    temp.rear = mid;
}

// 若队列不空，则删除Q的队头元素，用e返回其值，并返回TURE
// 否则返回FALSE
// eg：1 2 3 4 ->  2 3 4
bool DeQuene(Quene& Q, int& e)
{
    // 空对列直接返回false
    if(Q.front == Q.rear)
        return false;

    Node* temp = Q.front->next;
    e = temp->data;
    Q.front->next = temp->next;

// 如果只有一个结点
    if(Q.rear == temp)
    {
        Q.rear = Q.front;
        Q.front->next = NULL;
    }

    delete temp;

    return true;
}



// 输出队列的全部元素
void QueneTraverse(Quene& temp)
{
    
    Node* cur = temp.front->next;
    while(cur != NULL)
    {
        cout<<cur->data<<" ";
        cur = cur->next;
    }
}


// 销毁队列
void DestroyQuene(Quene& temp)
{   
    Node* cur = temp.front;

    while(cur != NULL)
    {
        cur = temp.front->next;
        delete temp.front;
        temp.front = cur;
    }

    cout<<"空间清理完毕"<<endl;
}