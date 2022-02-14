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
	L->next = NULL;
	LNode *tail = L;
	ElemType x;
	scanf("%d", &x);
	LNode *p = NULL;
	while(x != -1)
	{
		p = (LNode *)malloc(sizeof(LNode));
		p->data = x;
		if (L->next == NULL)
		{	
			L->next = p;
		}
		else
		{
			tail->next = p;
		}
		tail = p;
		scanf("%d", &x);
	}
	tail->next = NULL;
	return true;
}

void PrintList(LinkList L)
{
	LNode *p = L->next;
	while(p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//利用头插法将链表逆置 
LinkList ReverseList(LinkList L) 
{
	LNode *p = L->next;
	LNode *q = NULL; //q 为 p 的后继，以防断链 
	L->next = NULL;
	while (p != NULL)
	{
		q = p->next; //暂存 p 的后继 
		p->next = L->next;
		L->next = p;
		p = q;
	}
	return L;
}

int main()
{
	LinkList L;
	InitList(L);
	PrintList(L);
	
	ReverseList(L);
	PrintList(L);
	return 0;
}
