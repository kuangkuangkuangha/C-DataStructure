#include <iostream>
#include "LinkListConfig.cpp"
using namespace std;


// 求交集
void JiaoJi()
{
    node* head1 = new node; 
    node* head2 = new node;
    node* head3 = new node;     //head3 用来存储结果
    head3->next = NULL;
    int count=0;

    Init(head1);
    Init(head2);

    node* temp = head1->next;

    for(int i=0; i<ListLength(head1); i++)
    {
        int a = temp->data;
        if(LocateElem(head2, a))
        {
            ListInsert(head3, ++count, a);
        }
        temp=temp->next;
    }

    ListTraverse(head3);

    DestroyList(head1);
    DestroyList(head2);
    DestroyList(head3);
    // DestroyList(temp);
}

// 求并集
void BingJi()
{
    node* head1 = new node;
    node* head2 = new node;

    Init(head1);
    Init(head2);                // 这里不知道有一个什么傻逼BUG

    cout<<"haha";
    int len1 = ListLength(head1);
    node* temp = head1->next;

    for(int i=0; i<len1; i++)
    {
        int a = temp->data;
        if(!LocateElem(head2, a))
        {
            ListInsert(head1, ++len1, a);
        }
        temp = temp->next;
    }

    cout<<"交集结果是："<<endl;
    ListTraverse(head1);

    DestroyList(head1);
    DestroyList(head2);
}


// 求差集
void ChaJi()
{
    node* head1 = new node;
    node* head2 = new node;
    node* head3 = new node;
    head3->next = NULL;
    int count=0;

    Init(head1);
    Init(head2);

    node* temp1 = head1->next;
    for(int i=0; i<ListLength(head1); i++)
    {
        int a = temp1->data;
        if(!LocateElem(head2, a))
        {
            ListInsert(head3, ++count, a);
        }
        temp1 = temp1->next;
    }

    node* temp2 = head2->next;
    for(int i=0; i<ListLength(head2); i++)
    {
        int a = temp2->data;
        if(!LocateElem(head1, a))
        {
            ListInsert(head3, ++count, a);
        }
        temp2 = temp2->next;
    }

    cout<<"差集结果是："<<endl;
    ListTraverse(head3);

    DestroyList(head1);
    DestroyList(head2);
    DestroyList(head3);
}

int main()
{
    BingJi();
    return 0;
}
