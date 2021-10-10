#include<stdio.h>
#include<stdlib.h>
typedef struct BitreeNode
{
    char data;
    int index;
    struct BitreeNode *lchild;
    struct BitreeNode *rchild;
}BitreeNode,*Bitree;

typedef struct Stack
{
    Bitree data[100];
    int top;
}Stack;

typedef struct queue
{
    Bitree data[100];
    int front;
    int rear;
}Queue;
Queue Q;
void init_Queue()
{
    Q.front=0;
    Q.rear=0;
}
void push(Bitree root)
{
    Q.data[Q.rear++]=root;
}
Bitree pop()
{
    return Q.data[Q.front++];
}
int isEmpty()
{
    return Q.front==Q.rear;
}
void createBitree(Bitree*root)
{
    char date;
    scanf("%c",&date);
    if(date=='#')
        *root=NULL;
    else
    {
        *root=(Bitree)malloc(sizeof(BitreeNode));   
        (*root)->data=date;
        createBitree(&(*root)->lchild);
        createBitree(&(*root)->rchild);
    }
}
void PreOrder(Bitree root)//先序遍历 
{
    if(root==NULL)
        return;
    printf("%c ",root->data);
    PreOrder(root->lchild);
    PreOrder(root->rchild);
}
void InOrder(Bitree root)//中序遍历 
{
    if(root==NULL)
        return;
    InOrder(root->lchild);
    printf("%c ",root->data);
    InOrder(root->rchild);
}
void PostOrder(Bitree root)//后序遍历 
{
    if(root==NULL)
        return;
    PostOrder(root->lchild);
    PostOrder(root->rchild);
    printf("%c ",root->data);
}
void PreOrderNonRecursion(Bitree root)//非递归先序遍历 
{
    Stack S;
    S.top=-1;
    if(root)
    {
        Bitree p;
        S.data[++S.top]=root;
        while(-1 !=S.top)
        {
            p=S.data[S.top--];
            printf("%c ",p->data);
            if(p->rchild)
                S.data[++S.top]=p->rchild;
            if(p->lchild)
                S.data[++S.top]=p->lchild;
        }
    }
}
void InOrderNonRecursion(Bitree root)//非递归中序遍历 
{
    Stack s;
    s.top=-1;
    Bitree p=root;
    while(s.top>-1 || p)
    {
        while(p)
        {
            s.data[++s.top]=p;
            p=p->lchild;
        }
        p=s.data[s.top--];
        printf("%c ",p->data);
        p=p->rchild;
    }
}
void PostOrderNonRecursion(Bitree root)//非递归后序遍历 
{
    Stack s;
    s.top=-1;
    Bitree p=root;
    while(p || s.top !=-1)
    {
        while(p)
        {
            p->index=1;
            s.data[++s.top]=p;
            p=p->lchild;
        }
        if(s.top!=-1)
        {
            p=s.data[s.top--];
            if(p->index==1)
            {
                p->index++;
                s.data[++s.top]=p;
                p=p->rchild;
            }
            else if(p->index==2)
            {
                printf("%c ",p->data);
                p=NULL;    
            }

        }
    }
}
void LevelTraversal(Bitree root)//层序遍历 
{
    Bitree p=root;
    push(p);
    while(!isEmpty())
    {
        p=pop();
        printf("%c ",p->data);
        if(p->lchild)
            push(p->lchild);
        if(p->rchild)
            push(p->rchild);
    }
}
int main()
{
    Bitree root=(Bitree)malloc(sizeof(BitreeNode));
    createBitree(&root);
    init_Queue();
    printf("\nPreOrder!\n");
    PreOrder(root);
    printf("\nNonRecursion!\n");
    PreOrderNonRecursion(root);
    printf("\nInOrder\n");
    InOrder(root);
    printf("\nInOrderNonRecursion\n");
    InOrderNonRecursion(root);
    printf("\nPostOrder\n");
    PostOrder(root);
    printf("\nPostOrderNonRecursion\n");
    PostOrderNonRecursion(root);
    printf("\nlevelTraversal\n");
    LevelTraversal(root);
    return 0;
}
