#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList; 

bool InitList(LinkList &L)
{
	L = (LNode *)malloc(sizeof(LNode));
	if (L == NULL)
		return false;
	L->next = L;
	return true;
}

bool Empty(LinkList L)
{
	if (L->next == L)
		return true;
	else 
		return false;
}

bool isTail(LinkList L, LNode *p) //判断是否为表尾结点 
{
	if (p->next == L)
		return true;
	else
		return false;
}

int main()
{
	LinkList L;
	InitList(L);
	if (Empty(L))
	{
		printf("循环单链表为空"); 
	}
	return 0;
} 
