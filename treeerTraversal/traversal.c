#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct BiNode{
	char data;
	struct BiNode *lchild,*rchild;
}BiTNode,*BiTree;

void InitBiTree(BiTree T){
	T=NULL;
}
 
void Create(BiTree &T)
{
    char ch[2];
    scanf("%s",&ch[0]);
    if(strcmp(ch,"@")==0) {
    T=NULL;
	}else{
        T=(BiTree)malloc(sizeof(BiNode));
        T->data=ch[0];
        Create(T->lchild);
        Create(T->rchild);
    }
}
 
void visit(char c){
	printf("%c",c);
}
 
void PreOrderTraverse(BiTree T){
	if(T){
		visit(T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
 
void InOrderTraverse(BiTree T){
	if(T){
	 InOrderTraverse(T->lchild);
	 visit(T->data);
	 InOrderTraverse(T->rchild); 
	}
}
 
 
void PostOrderTraverse(BiTree T){
	if(T){
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		visit(T->data);
	}
}
 
int depth(BiTree T){
	int ldeep,rdeep;
	if(!T) return 0;
	else{
		ldeep=depth(T->lchild);
		rdeep=depth(T->rchild);
		return ldeep>rdeep?ldeep+1:rdeep+1;
	}
} 
 
int main(){
	BiTree T;
	int deep;
	InitBiTree(T);
 
		printf("请输入序列\n");
	Create(T);
	deep=depth(T);
	printf("\n深度：%d\n二叉树构建完毕",deep);
	printf("\n先序遍历二叉树："); 
	PreOrderTraverse(T);
	printf("\n中序遍历二叉树：");
	InOrderTraverse(T);
	printf("\n后序遍历二叉树：");
	PostOrderTraverse(T);
 
	return 0;
}
