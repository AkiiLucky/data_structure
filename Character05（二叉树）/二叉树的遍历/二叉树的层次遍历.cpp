#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct BiTNode{
	ElemType data;                    //������ 
	struct BiTNode *lchild, *rchild;  //���Һ���ָ�� 
}BiTNode, *BiTree;

void InitTree(BiTree &boot)
{
	//�������ڵ� 
	boot = (BiTree)malloc(sizeof(BiTNode));
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

void visit(BiTNode *p) 
{
	printf("%d ", p->data);
}

typedef struct LinkNode{
	BiTNode *Elems;
	struct LinkNode *next;
}LinkNode;

typedef struct LinkQueue{
	struct LinkNode *front, *rear;
}LinkQueue;

void InitQueue(LinkQueue &Q)
{
	Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));  //��ʼʱ��front, rear ��ָ��ͷ��� 
	Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

void EnQueue(LinkQueue &Q, BiTNode *p)   
{
	LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
	s->Elems = p;
	s->next = NULL;
	Q.rear->next = s;                    //�½����뵽 rear ֮�� 
	Q.rear = s;                          //�޸Ķ�βָ�� 
} 

bool DeQueue(LinkQueue &Q, BiTNode* &p)  //����� p һ��Ҫʹ�����÷��� '&'  
{
	if (Q.front == Q.rear)
		return false;                    //����Ϊ�գ����� false 
	LinkNode *tmp = Q.front->next;       
	p = tmp->Elems;
	Q.front->next = tmp->next;
	if (tmp->next == NULL)               //���һ����������Ҫ�޸Ķ�βָ�� 
	{
		Q.rear = Q.front;
		Q.rear->next = NULL;
	}
	free(tmp);
	return true;
} 

void LevelOrder(BiTree T)
{
	LinkQueue Q;
	InitQueue(Q); 
	BiTNode *p = NULL;
	
	EnQueue(Q, T);  //��������
	while (!IsEmpty(Q))
	{
		DeQueue(Q, p);  //��ͷ������
		visit(p);
		if (p->lchild != NULL)
		{
			EnQueue(Q, p->lchild);  //���������գ������������ڵ���� 
		}
		if (p->rchild != NULL)
		{
			EnQueue(Q, p->rchild);  //���������գ������������ڵ���� 
		}
		free(p);
	} 
	free(Q.front);
}

int main()
{
	
	BiTree T;
	InitTree(T);
	//visit(T);
	//visit(T->lchild);
	//visit(T->rchild);
	LevelOrder(T);
	return 0;
}
