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

bool InsertNextDNode(DNode *p, DNode *s) //在 p 结点之后插入 s 结点  
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

bool DeleteNextDNode(DNode *p) //删除 p 结点的后继结点
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

void DestoryList(DLinkList &L) //销毁双链表 
{
	while (L->next != NULL) //循环释放各个结点数据 
		DeleteNextDNode(L);
	free(L); //释放头节点 
	L = NULL; //头指针指向 NULL 
}

bool SearchPriorDNode(DNode *p, DNode *s, ElemType e) //按值查找结点 p 之前结点，并把地址返回给 s  
{
	while (p->prior != NULL) //从 p 结点向前遍历 
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
		printf("双链表为空"); 
	return 0;
}
