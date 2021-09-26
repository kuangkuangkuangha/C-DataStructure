#include <iostream>
using namespace std;
// 双向链表
// 头节点不存数据

struct doubleLink{
    int data;
    struct doubleLink* prior;
    struct doubleLink* next;
};

typedef doubleLink node;

// 初始化一个双向链表
void Init(node* head)
{
    int a;
    cout<<"请输入你想一组数据的个数："<<endl;
    cin>>a;

    cout<<endl;

    node* pre = head;
    for(int i=0; i<a; i++)
    {
        node* temp = new node;
        cin>>temp->data;

        pre->next = temp;

        temp->prior = pre;
        // temp->next = head;
    
        pre = temp;
    }

    head->prior = pre;
    pre->next = head;
}

// 在带头节点的的双向链表L中p结点之前插入s结点
void InsertLink(node* head, node* p, node* s)
{
    node* temp = p->prior;

    s->next = p;
    s->prior = p->prior;

    temp->next = s;
    p->prior = s;
}


// 输出一个双向链表的所有元素 
void ListTraverse(node* head)
{
    cout<<"链表数据为："<<endl;
    node* temp=head->next;
    
    while(temp!=head)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

// 销毁双向链表
void DestroyLinkList(node* head)
{
    node* pre=head;
    node* cur=head;

    while(cur!=NULL)
    {
        cur = cur->next;

        delete pre;

        pre = cur;
    }
}

// 删除链表L中的p结点，并用e返回
void DeleteLinkList(node* head, node* p, int* e)
{   
    *e = p->data;

    p->prior->next = p->next;
    p->next->prior = p->prior;

    delete p;
}   



int main()
{
    node* head1 = new node;

    node* s = new node;
    s->data = 5;

    // node* p = head1->next->next;

    Init(head1);

    node* p = head1->next->next->next;

    InsertLink(head1, p, s);
    ListTraverse(head1);

    delete s;
}