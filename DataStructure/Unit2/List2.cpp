#include <iostream>
#include "List2Config.cpp"
using namespace std;


// 求交集
void JiaoJi(node* head1, node* head2)
{
    node* head3 = new node;     //head3 用来存储结果
    head3->next = NULL;
    int count=0;

    node* temp = head1;

    for(int i=0; i<ListLength(head1); i++)
    {
        int a = temp->data;
        if(LocateElem(head2, a))
        {
            ListInsert(&head3, ++count, a);
        }
        temp=temp->next;
    }

    cout<<"交集结果为: ";
    ListTraverse(head3);
    // DestroyList(head3);
}


int main()
{
    node* head1;
    Init(head1);
    
}