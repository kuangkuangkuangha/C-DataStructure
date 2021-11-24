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

// ************* 二叉树的遍历 *************

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

// 中序遍历二叉树
void InOrder(BitNode* T)
{
    if(T == NULL)
        return;
    else{
        InOrder(T->lchild);
        cout<<T->data<<" ";
        InOrder(T->rchild);
    }
}

// 后序遍历二叉树
void LastOrder(BitNode* T)
{
    if(T == NULL)
        return;
    else{
        LastOrder(T->lchild);
        LastOrder(T->rchild);
        cout<<T->data<<" ";
    
    }
}

// 层序遍历
void CengxuOrder(BitNode* T)
{

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
    BitNode* root = NULL;
    cout<<"请输入树的元素:"<<endl;
    PreCreateTree(root);
    cout<<"先序遍历结果:"<<endl;
    PreOrder(root);
    cout<<endl;

    cout<<"中序遍历结果:"<<endl;
    InOrder(root);
    cout<<endl;

    cout<<"后序遍历结果:"<<endl;
    LastOrder(root);
    cout<<endl;

    Quene q;
    QueneInit(q);
    
    EnQuene(q, *root);
    BitNode temp;

    cout<<"层序遍历结果"<<endl;
    while(QueneEmpty(q) == 1)
    {
        temp = DeQuene(q);

        cout<<temp.data<<"  ";
        if(temp.lchild != NULL)
            EnQuene(q, *temp.lchild);
        if(temp.rchild != NULL)
            EnQuene(q, *temp.rchild);
    }
}