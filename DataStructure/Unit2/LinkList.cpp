#include <iostream>
#include "LinkListConfig.cpp"
using namespace std;
// 头节点不存储数据

// 求交集
void JiaoJi(node* head1, node* head2)
{
    node* head3 = new node;     //head3 用来存储结果
    head3->next = NULL;
    int count=0;

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

    cout<<"交集结果为: ";
    ListTraverse(head3);
    DestroyList(head3);
}

// 求并集
void BingJi(node* head1, node* head2)
{
    // cout<<"haha1";          // 这里不知道有个什么BUG
    int len1 = ListLength(head1);
    int len2 = ListLength(head2);
    // cout<<"haha2";
    // node* head3 = new node;
    // head3->next = NULL;

    // node* temp = new node;
    // cout<<"haha3";
    // temp = head1->next;
    node* temp = head1->next;

    // cout<<"haha";
    for(int i=0; i<len1; i++)
    {
        int a = temp->data;
        if(!LocateElem(head2, a))
        {
            ListInsert(head2, ++len2, a);
        }
        temp = temp->next;
    }

    cout<<"并集结果是:";
    ListTraverse(head2);
    DestroyList(temp);
}


// 求差集
void ChaJi(node* head1, node* head2)
{
    node* head3 = new node;
    head3->next = NULL;
    int count=0;


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


    cout<<"差集结果是: ";
    ListTraverse(head3);
    DestroyList(head3);
}


int main()
{
    node* head1 = new node;
    node* head2 = new node;
    
    cout<<"************InputA*************"<<endl;
    cout<<"numA: ";
    Init(head1);
    cout<<"************InputB*************"<<endl;
    cout<<"numB: ";
    Init(head2);
    cout<<endl;

    
    cout<<"************Result*************"<<endl;
    cout<<"A:";
    ListTraverse(head1);
    cout<<"B:";
    ListTraverse(head2);
    cout<<"A-B";
    ChaJi(head1, head2);

    cout<<"B-A";
    ChaJi(head2, head1);

    JiaoJi(head1, head2);

    BingJi(head1, head2);

    cout<<"*******************************"<<endl;

    DestroyList(head1);
    DestroyList(head2);
    return 0;
}
