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
	
	//插入新结点 
	BiTNode *q = (BiTNode *)malloc(sizeof(BiTNode));
	q->data = 3;
	q->lchild = NULL;
	q->rchild = NULL;
	boot->rchild = q;   //作为根节点的右孩子 
}

void visit(BiTNode *T) 
{
	printf("%d ", T->data);
}

//前序遍历 
void PreOrder(BiTree &T)
{
	if (T != NULL)
	{
		visit(T);              //访问根节点 
		PreOrder(T->lchild);   //递归遍历左子树 
		PreOrder(T->rchild);   //递归遍历右子树
	}
}

//中序遍历 
void InOrder(BiTree &T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);    //递归遍历左子树
		visit(T);              //访问根节点 
		InOrder(T->rchild);    //递归遍历右子树
	}
}

//后序遍历
void PostOrder(BiTree &T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);   //递归遍历左子树 
		PostOrder(T->rchild);   //递归遍历右子树
		visit(T);               //访问根节点
	}
} 

//求二叉树的深度
int treeDepth(BiTree &T) 
{
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		int l = treeDepth(T->lchild);
		int r = treeDepth(T->rchild);
		return l > r ? l+1 : r+1 ;
	}
}

int main()
{
    BiTree T = NULL;
	InitTree(T);
	
	PreOrder(T);
	printf("\n");
	InOrder(T);
	printf("\n");
	PostOrder(T); 
	printf("\n");
	
	printf("二叉树的深度为 %d", treeDepth(T));

	return 0;
}
