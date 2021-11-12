#include <iostream>
using namespace std;
// 二叉树基本操作
typedef struct BiTNode
{
    int data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode;


// 构造一棵空的二叉树
void InitBiTree(BiTNode& T)
{

}

// 二叉树存在
// 销毁二叉树T
void DestroyBiTree(BiTNode& T)
{

}

// definiton给出二叉树T的定义
// 按definition给出的定义构造二叉树T
void CreateBiTree(BiTNode& T, int definition)
{

}

// 二叉树T存在
// 返回T的深度
void BiTreeDepth(BiTNode T)
{

}

// 先序遍历
void PerOrder(BiTNode* T)
{
	if(T!=NULL)            // T != NULL 
	{
		cout << T->data << " ";
		PerOrder(T->lchild);            
		PerOrder(T->rchild);          
	}
} 

// 二叉树存在，e是T中的某个节点
// 若e是T的非根节点，则返回它的双亲，否则返回“空”
void Parent(BiTNode* T, int e)
{
    if(T==NULL)
    {
        return;
    }


	if(T->lchild->data!=e && T->rchild->data!=e)            // T != NULL 
	{
		Parent(T->lchild, e); 
		Parent(T->rchild, e);          
	}
    else
    {
        cout<<"双亲是:"<<T->data<<endl;
        return;
    }

}

// 二叉树存在，e是T中的某个节点
// 返回e的左孩子，若e无左孩子，则返回“空”
void LeftChild(BiTNode T, int e)
{

}

// 二叉树存在，e是T中的某个节点
// 返回e的右孩子，若e无右孩子，则返回“空”
void RightChild(BiTNode T, int e)
{
    
}

void LeftSibling(BiTNode T, int e)
{
    
}

void RightSibling(BiTNode T, int e)
{
    
}

void InsertChild(BiTNode T, BiTree p, int LR, BiTNode C)
{
    
}


void DeleteChild(BiTNode T, BiTree p, int LR)
{
    
}


void Traverse(BiTNode T)
{

}



int main()
{
	BiTNode* root;
	
	cout << "请输入数据先序创建一棵二叉树：";
	root = PerCreateTree();               //先序创建一棵二叉树 
	
	return 0;
}

