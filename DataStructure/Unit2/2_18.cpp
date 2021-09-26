#include <iostream>
using namespace std;

// 逆序创建链表
struct node{
    int data;
    struct node* next;
};

 void CreateList_L(node* head, int* p, int n)
{
    head=NULL;
    for(int i=n-1; i>=0; i--)
    {
        node* temp = new node;
        temp->data = p[i];
        temp->next = head;
        head = temp;
    }
}

void ListTraverse(node* head)
{
    node* temp=head;

    while(temp != NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

int main()
{
    int a[]={1,3,5,7,9};
    node* list = new node;
    CreateList_L(list, a, 5);
    ListTraverse(list);

    return 0;
}