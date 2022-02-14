#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct DNode{
	ElemType data;
	struct DNode *prior, *next;
} DNode, *DLinkList;

bool InitList(DLinkList &L) //初始化为带头节点的空表 
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

bool isTail(DLinkList &L, DNode *p) //判断是否为表尾结点 
{
	if (p->next == L && L->prior == p)
		return true;
	else
		return false; 
} 

bool InsertNextDNode(DNode *p, DNode *s) //在 p 结点之后插入 s 结点  
{
	if (p == NULL || s == NULL)
		return false;
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}

bool DeleteNextDNode(DNode *p) //删除 p 结点的后继结点
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
		printf("循环双链表为空"); 
	}
	return 0;
}
