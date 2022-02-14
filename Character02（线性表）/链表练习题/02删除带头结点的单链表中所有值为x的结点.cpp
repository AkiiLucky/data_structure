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

//解法一  
void Delete_x(LinkList &L, ElemType x)
{
	LNode *p = L->next;
	LNode *pre = L;
	LNode *temp = NULL;
	while(p != NULL)
	{
		if (p->data == x)
		{
			temp = p;
			p = p->next;
			pre->next = p;
			free(temp);
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
}

//解法二  利用尾插法重新构建一个不含元素 x 的新链表 
void Del_x(LinkList &L, ElemType x) 
{
	LNode *p = L->next;
	LNode *tail = L;     //创建一个尾指针指向新表的头结点 
	LNode *temp = NULL;
	while (p != NULL)
	{
		if (p->data != x)
		{
			tail->next = p;
			tail = p;
			p = p->next;
		}
		else
		{
			temp = p;
			p = p->next;
			free(temp);
		}
	}
	tail->next = NULL;
}


int main()
{
	LinkList L;
	InitList(L);
	PrintList(L);
	
	//Delete_x(L, 1);
	Del_x(L, 1);
	PrintList(L);
	return 0;
}
