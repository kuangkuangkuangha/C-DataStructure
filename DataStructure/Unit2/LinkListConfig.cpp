#include <iostream>
using namespace std;
// 头节点存储数据

struct linklist
{
    int data;
    struct linklist* next;
};

typedef struct linklist node;

// 输入数据
void Init(node* head)
{
    int a,b;
    cout<<"请输入一组数据的个数："<<endl;
    cin>>a;
    cout<<endl;

    node* temp1=head;
    for(int i=0; i<a; i++)
    {
        node* temp = new node;
        cin>>temp->data;
        temp1->next=temp;

        temp1=temp;
    }
    temp1->next=NULL;
}

// 将数据e插入到第i个元素前面
void ListInsert(node* head, int i, int e)
{
    node* pst=head;

    node* temp = new node;
    temp->data = e;

    for(int k=1; k<i; k++)
    {
        pst=pst->next;
    }

    temp->next = pst->next;
    pst->next = temp;
}

// 返回链表的长度
int ListLength(node* head)
{
    int count=0;
    node* temp=head;

    while (temp->next!=NULL)
    {
        count++;
        temp=temp->next;
    }
    
    return count;
}



// 返回 元素在第几个位置
int LocateElem(node* La, int e)
{
    node* temp = La->next;

    for(int i=1; i<=ListLength(La); i++)
    {
        if(temp->data == e)
        {
            return i;
        }

        temp=temp->next;
    }

    return 0;
}




// 将链表中第i个元素删除
void ListDelete(node* head, int i)
{
    node* res;
    node* temp=head;

    // 找到前一个元素
    for(int k=1; k<i; k++)
    {
        temp=temp->next;
    }

    res = temp->next;
    temp->next = res->next;
    delete res;
}


// 将所有的数据输出来
void ListTraverse(node* a)
{
    cout<<"链表数据为："<<endl;
    node* temp=a->next;
    
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

// 销毁链表
void DestroyList(node* head)
{
    // node* temp = head->next;
    node* pre=head;
    node* cur=head;

    while(cur!=NULL)
    {
        cur = cur->next;

        delete pre;

        pre = cur;
    }
    
}
