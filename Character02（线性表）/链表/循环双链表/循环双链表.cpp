#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct DNode{
	ElemType data;
	struct DNode *prior, *next;
} DNode, *DLinkList;

bool InitList(DLinkList &L) //��ʼ��Ϊ��ͷ�ڵ�Ŀձ� 
{
	L = (DNode *)malloc(sizeof(DNode));
	if (L == NULL)
		return false;
	L->prior = L;
	L->next = L;
	return true;
}

bool Empty(DLinkList L)
{
	if (L->next == L && L->prior == L)
		return true;
	else
		return false;
}

bool isTail(DLinkList &L, DNode *p) //�ж��Ƿ�Ϊ��β��� 
{
	if (p->next == L && L->prior == p)
		return true;
	else
		return false; 
} 

bool InsertNextDNode(DNode *p, DNode *s) //�� p ���֮����� s ���  
{
	if (p == NULL || s == NULL)
		return false;
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}

bool DeleteNextDNode(DNode *p) //ɾ�� p ���ĺ�̽��
{
	if (p == NULL)
		return false;
	DNode *q = p->next;
	p->next = q->next;
	q->next->prior = p;
	free(q); 
	return true;
} 

int main()
{
	DLinkList L;
	InitList(L);
	if (Empty(L))
	{
		printf("ѭ��˫����Ϊ��"); 
	}
	return 0;
}
