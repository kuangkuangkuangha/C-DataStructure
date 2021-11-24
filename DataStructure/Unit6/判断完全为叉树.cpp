#include <iostream>
using namespace std;

typedef struct BitTree
{
    char data;
    struct BitTree* lchild;
    struct BitTree* rchild;
}BitNode;

// 先序创建二叉树
void PreCreateTree(BitNode* &T)
{
    // cout<<"开始输入元素:"<<endl;
    char ch;
    cin>>ch;
    if(ch == '#')
        T=NULL;
    else
    {
        T = new BitNode;
        T->data = ch;
        PreCreateTree(T->lchild);
        PreCreateTree(T->rchild);
    }

    return;
}

// 先序遍历二叉树
void PreOrder(BitNode* T)
{
    if(T == NULL)
        return;
    else{
        cout<<T->data<<" ";
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}


// ******** QUenen相关操作 **********
typedef struct Sql_Quene 
{
    BitNode* elem;
    int front;
    int rear;
    int maxSize;
}Quene;

// 初始化队列
void QueneInit(Quene& Q)
{
    Q.elem = new BitNode[30];
    Q.front = Q.rear = 0;
}

// 判断队列空
int QueneEmpty(Quene& Q)
{       
    if(Q.front == Q.rear)
        return 0;

    return 1;
}

// 入队
void EnQuene(Quene& Q, BitNode e)
{
    Q.elem[Q.rear++] = e;
}

// 出队
BitNode DeQuene(Quene& Q)
{
    return Q.elem[Q.front++];
}

// 打印队列
void QueneTraverse(Quene& Q)
{
    int a = Q.front;
    int b = Q.rear;
    while (a != b)
    {
        cout<<Q.elem[a++].data<<" ";
    }
}


int main()
{
    BitNode* root;
    PreCreateTree(root);
    PreOrder(root);

    Quene q;
    QueneInit(q);
    
    EnQuene(q, *root);
    BitNode temp;
    int tag=0;

    while(QueneEmpty(q) == 1)
    {
        temp = DeQuene(q);

        if(temp.lchild==NULL && temp.rchild!=NULL)
        {
            cout<<"不是完全二叉树"<<endl;
            return 0;
        }

        if(temp.lchild==NULL || temp.rchild==NULL)
            break;

        // if(temp.lchild != NULL)
            EnQuene(q, *temp.lchild);
        // if(temp.rchild != NULL)
            EnQuene(q, *temp.rchild);
    }

    BitNode temp2;
    while(QueneEmpty(q) == 1)
    {
        temp2 = DeQuene(q);
        if(temp2.lchild!=NULL || temp2.rchild!=NULL)
            cout<<"不是完全二叉树"<<endl;

        cout<<"是完全二叉树"<<endl;
        return 0;
    }

}