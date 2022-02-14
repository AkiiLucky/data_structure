#include <stdio.h>
#include <stdlib.h>

#define ElemType int
#define MaxSize 100

typedef struct BiTNode{
	ElemType data;                    //数据域 
	struct BiTNode *lchild, *rchild;  //左右孩子指针 
}BiTNode, *BiTree;

void InitTree(BiTree &boot)
{
	//创建根节点 
	boot = (BiTree)malloc(sizeof(BiTree));
	boot->data = 1;
	boot->lchild = NULL;
	boot->rchild = NULL;
	
	//插入新结点 
	BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
	p->data = 2;
	p->lchild = NULL;
	p->rchild = NULL;
	boot->lchild = p;   //作为根节点的左孩子 
}



int main()
{
    BiTree T = NULL;
	InitTree(T);
	return 0;
}
