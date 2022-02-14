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
	
	//�����½�� 
	BiTNode *q = (BiTNode *)malloc(sizeof(BiTNode));
	q->data = 3;
	q->lchild = NULL;
	q->rchild = NULL;
	boot->rchild = q;   //��Ϊ���ڵ���Һ��� 
}

void visit(BiTNode *T) 
{
	printf("%d ", T->data);
}

//ǰ����� 
void PreOrder(BiTree &T)
{
	if (T != NULL)
	{
		visit(T);              //���ʸ��ڵ� 
		PreOrder(T->lchild);   //�ݹ���������� 
		PreOrder(T->rchild);   //�ݹ����������
	}
}

//������� 
void InOrder(BiTree &T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);    //�ݹ����������
		visit(T);              //���ʸ��ڵ� 
		InOrder(T->rchild);    //�ݹ����������
	}
}

//�������
void PostOrder(BiTree &T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);   //�ݹ���������� 
		PostOrder(T->rchild);   //�ݹ����������
		visit(T);               //���ʸ��ڵ�
	}
} 

//������������
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
	
	printf("�����������Ϊ %d", treeDepth(T));

	return 0;
}
