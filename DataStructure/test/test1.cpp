#include <iostream>
using namespace std;

struct LinkList 
{
    int data;
    struct LinkList* next;
};

typedef struct LinkList Node;

void Input(Node* head)
{
    int num;
    int a;
    Node* cur = head;
    cout<<"请输入链表元素的个数:"<<endl;
    cin>>num;
    cout<<" 请开始输入元素:"<<endl;

    for(int i=0; i<num; i++)
    {
        cin>>a;
        Node* temp = new Node;
        temp->data = a;

        cur->next = temp;
        cur = temp;
    }

    cur->next = NULL;
}

void Traverse(Node* head)
{
    Node* cur = head->next;

    cout<<"遍历元素:"<<endl;
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur = cur->next;
    }
    cout<<endl;
}

// 逆置
Node* Fan(Node*& head)
{
    int n;
    Node* start = head->next;

    Node* cur=head->next;
    Node* pre=head;
    cout<<"请输入你要逆置的元素个数"<<endl;
    cin>>n;
    
    for(int i=0; i<n; i++)
    {
        Node* temp = cur->next;
        cur->next = pre;
        pre = cur;

        cur=temp;;
    }

    start->next = cur;
    return pre;
}



int main()
{
    Node* head1 = new Node;
    head1->next = NULL;

    Input(head1);

    Traverse(head1);

    head1->next =  Fan(head1);;
    Traverse(head1);
}