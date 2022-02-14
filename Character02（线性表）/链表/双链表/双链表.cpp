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
	L->prior = NULL;
	L->next = NULL;
	return true;
}

bool Empty(DLinkList L)
{
	if (L->next == NULL)
		return true;
	else
		return false;
}

bool InsertNextDNode(DNode *p, DNode *s) //�� p ���֮����� s ���  
{
	if (p == NULL || s == NULL)
		return false;
	s->next = p->next;
	if (p->next != NULL)
		p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}

bool DeleteNextDNode(DNode *p) //ɾ�� p ���ĺ�̽��
{
	if (p == NULL || p->next == NULL)
		return false;
	DNode *q = p->next;
	p->next = q->next;
	if (q->next != NULL)
		q->next->prior = p;
	free(q); 
	return true;
} 

void DestoryList(DLinkList &L) //����˫���� 
{
	while (L->next != NULL) //ѭ���ͷŸ���������� 
		DeleteNextDNode(L);
	free(L); //�ͷ�ͷ�ڵ� 
	L = NULL; //ͷָ��ָ�� NULL 
}

bool SearchPriorDNode(DNode *p, DNode *s, ElemType e) //��ֵ���ҽ�� p ֮ǰ��㣬���ѵ�ַ���ظ� s  
{
	while (p->prior != NULL) //�� p �����ǰ���� 
	{
		if (p->data == e)
		{
			s = p;
			return true;
		}
		p = p->prior;
	}
	return false;
}

int main()
{
	DLinkList L;
	InitList(L);
	if (Empty(L)) 
		printf("˫����Ϊ��"); 
	return 0;
}
