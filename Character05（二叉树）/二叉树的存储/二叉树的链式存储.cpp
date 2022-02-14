#include <stdio.h>
#include <stdlib.h>

#define ElemType int
#define MaxSize 100

typedef struct BiTNode{
	ElemType data;                    //������ 
	struct BiTNode *lchild, *rchild;  //���Һ���ָ�� 
}BiTNode, *BiTree;

void InitTree(BiTree &boot)
{
	//�������ڵ� 
	boot = (BiTree)malloc(sizeof(BiTree));
	boot->data = 1;
	boot->lchild = NULL;
	boot->rchild = NULL;
	
	//�����½�� 
	BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
	p->data = 2;
	p->lchild = NULL;
	p->rchild = NULL;
	boot->lchild = p;   //��Ϊ���ڵ������ 
}



int main()
{
    BiTree T = NULL;
	InitTree(T);
	return 0;
}
