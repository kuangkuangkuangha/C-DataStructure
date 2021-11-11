#include <iostream>
using namespace std;
 
// typedef int ElementType;             //给int起别名为ElementType, typedef是起别名的意思 
typedef struct BitTreeNode              //定义二叉树节点数据类型 
{
	char data;
	struct BitTreeNode *lchild, *rchild;
} BitNode;           //BitNode*为指向BitNode这种结构的指针
 
 
 
//先序创建一棵二叉树 
void  PerCreateTree(BitNode * &T)
{
	char item;
	cin >> item;
	if(item == '#')              //叶节点数据标志：其后根两个# 
	    T = NULL;            //若某一节点为叶子结点，则其左右子树均为NULL，#表示建空树

	else
	{
        T = new BitNode;
		T->data = item;
		
	    PerCreateTree(T->lchild);             //递归创建其左子树 
	    PerCreateTree(T->rchild);            //递归创建其右子树 
	}                        //返回根节点 
}

//先序递归遍历二叉树
void PreOrder(BitNode* T)
{
	if(T!=NULL)             
	{
		cout << T->data << " ";
		PreOrder(T->lchild);            
		PreOrder(T->rchild);           
	}
} 
 

//先序递归遍历二叉树
void Parent(BitNode* T,char e)
{
	if(T!=NULL)// T != NULL 
	{
		// cout << T->data << " ";
		if(T->lchild!=NULL &&  T->lchild->data == e)
		{
			cout<<"双亲是："<<T->data<<endl;
			return;
		}
		
		if(T->rchild!=NULL && T->rchild->data == e)
		{
			cout<<"双亲是："<<T->data<<endl;
			return;
		}

		Parent(T->lchild,e);

		
		Parent(T->rchild,e);
	}
} 

void LeftChild(BitNode* T,char e)
{
	if(T!=NULL)// T != NULL 
	{
		// cout << T->data << " ";
		if(T->lchild!=NULL &&  T->lchild->data == e)
		{
			cout<<"双亲是："<<T->data<<endl;
			return;
		}
		
		if(T->rchild!=NULL && T->rchild->data == e)
		{
			cout<<"双亲是："<<T->data<<endl;
			return;
		}

		LeftChild(T->lchild,e);
		LeftChild(T->rchild,e);
	}
} 

//中序递归遍历二叉树
void InOrder(BitNode* T)
{
	if(T!=NULL)             
	{
		
		InOrder(T->lchild);            
        cout << T->data << " ";
		InOrder(T->rchild);           
	}
} 

//后序递归遍历二叉树
void BehindOrder(BitNode* T)
{
	if(T!=NULL)          
	{
		
		BehindOrder(T->lchild); 
		BehindOrder(T->rchild); 
        cout << T->data << " ";
	}
} 

void Parent2(BitNode* T, int e)
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

 
int main()
{
	BitNode* root;
	
	cout << "请输入数据先序创建一棵二叉树：";
	PerCreateTree(root);               //先序创建一棵二叉树 

	int temp;


	
	cout << "先序遍历的结果："; 
	PreOrder(root);             
	cout << endl;

	Parent(root, 'E');
	

    // cout << "中序遍历的结果："; 
	// InOrder(root);             
	// cout << endl;

	// cout << "后序遍历的结果："; 
	// BehindOrder(root);             
	// cout << endl;
	
	return 0;
}
