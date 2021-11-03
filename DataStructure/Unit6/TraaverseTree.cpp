#include <iostream>
using namespace std;
#define STACKSIZE 10;

// 树🌲中的某个节点
struct BiTNode
{
    int data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
};
typedef struct BiTNode BNode;

// 每个节点和他的工作状态
typedef struct {
    BiTNode* ptr;
    TaskType task;
} Data2Type;

// 定义工作状态{1:工作状态是遍历  0:工作状态是访问}
typedef enum { Travel=1, Visit=0} TaskType;

// 使用链栈
// struct Leader
// {
//     BNode* head;    // top指针
//     int stackSize;
//     int increment;
// };

// 使用顺序栈存储 树🌲 中的元素
struct Leader
{
    BNode* elem;
    int top;
    int stacksize;
    int increment;
};

void InitStack(Leader& lead)
{
}

int main()
{
    
}