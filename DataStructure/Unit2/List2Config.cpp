#include <iostream>
using namespace std;
// 头节点存数据
// 初始化链表
struct LinkList {
    int data;
    struct LinkList* next;
};

typedef struct LinkList node;

void Init(node* head)
{
    int num;
    int a;
    cout<<"请输入要输入数的个数:"<<endl;
    cin>>num; 

    cin>>a;
    node* temp=head;

    for(int i=0; i<num; i++)
    {
        temp = new node;
        temp->data = a;
        temp->next = NULL;
        cin >> a;
    }

    cout<<"dfaksdhf"<<head->data;
}

void ListTraverse(node* head)
{
    node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" "<<endl;
    }
    
}

