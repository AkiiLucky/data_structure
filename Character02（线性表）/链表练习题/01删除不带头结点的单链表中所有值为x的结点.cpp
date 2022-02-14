#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

bool InitList(LinkList &L)
{
	L = NULL;
	LNode *tail = L;
	LNode *p = (LNode *)malloc(sizeof(LNode));
	ElemType x;
	scanf("%d", &x);
	while(x != -1)
	{
		if (L == NULL)
		{
			p->data = x;
			L = p;
			tail = p;
		}
		else
		{
			p->data = x;
			tail->next = p;
			tail = p;
		}
		p = (LNode *)malloc(sizeof(LNode));
		scanf("%d", &x);
	}
	free(p);
	tail->next = NULL;
	return true;
}

void PrintList(LinkList L)
{
	LNode *p = L;
	while(p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//±ê×¼½â´ð
void Del_x(LinkList &L, ElemType x) 
{
	LNode *p;
	if (L == NULL)
		return ;
	if (L->data == x)
	{
		p = L;
		L = L->next;
		free(p);
		Del_x(L, x);
	}
	else
	{
		Del_x(L->next, x);
	}
}


int main()
{
	LinkList L;
	InitList(L);
	PrintList(L);
	
	Del_x(L, 1);
	PrintList(L);
}
