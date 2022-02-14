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

void Delete_Min(LinkList &L) 
{
	LNode *p = L->next;
	LNode *pre_p = L;
	LNode *min = L->next;
	LNode *pre_min = L;
	while (p != NULL)
	{
		if (p->data < min->data)
		{
			min = p;
			pre_min = pre_p;
		}
		pre_p = p;
		p = p->next;
	}
	pre_min->next = min->next;
	free(min);
}

int main()
{
	LinkList L;
	InitList(L);
	PrintList(L);
	
	Delete_Min(L);
	PrintList(L);
	return 0;
}
