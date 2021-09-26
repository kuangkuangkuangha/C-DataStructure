#include <iostream>
using namespace std;
// 头节点存数据

struct node
{
    int data;
    struct node* next;
};

void InvertLinkedList(node* head)
{
    node* pre=NULL;
    node* cur=head;

    while(cur!=NULL)
    {
        node* temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;

    }
}

int main()
{
    
}