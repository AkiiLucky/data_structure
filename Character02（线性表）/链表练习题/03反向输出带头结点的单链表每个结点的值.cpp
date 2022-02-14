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

//利用头插法可以将单链表逆置输出 
void ReversePrint(LinkList L)
{
	LinkList L_copy;
	L_copy = (LNode *)malloc(sizeof(LNode));
	L_copy->next = NULL;
	LNode *q = NULL;
	LNode *p = L->next;
	while (p != NULL)
	{
		q = (LNode *)malloc(sizeof(LNode));
		q->data = p->data;
		q->next = L_copy->next;
		L_copy->next = q;
		p = p->next;
	}
	while (q != NULL)
	{
		printf("%d ", q->data);
		q = q->next;
	}
	printf("\n"); 
}

//另一种解法
void R_Print(LinkList L)
{
	if (L->next != NULL)
	{
		R_Print(L->next);
	}
	if (L != NULL) printf("%d ", L->data);
} 

void R_Ignore_Head(LinkList L)
{
	if (L != NULL) R_Print(L->next);
}

int main()
{
	LinkList L;
	InitList(L);
	PrintList(L);
	
	ReversePrint(L); 
	//R_Ignore_Head(L);
	return 0;
}
