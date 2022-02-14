#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct LNode{      //定义单链表结点类型 
	ElemType data;         //数据域 
	struct LNode *next;    //指针域 
}LNode, *LinkList;

LinkList List_TailInsert(LinkList &L) //尾插法建立单链表 
{
	ElemType x;
	L = (LinkList)malloc(sizeof(LNode)); //创建头结点 
	LNode *s, *r = L; // r 为表尾指针 
	scanf("%d", &x);
	while (x != -1)  //输入 -1 表示结束 
	{
		s = (LNode *)malloc(sizeof(LNode));
		
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

void PrintList(LinkList &L)
{
	LNode *p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

LNode *GetElem(LinkList &L, int i) // 按位查找单链表（带头结点）第 i 个结点 
{
	int j = 1; // 计数，初始为 1 
	LNode *p;
	p = L->next;
	if (i == 0) return L; // 第 0 个结点就是头结点 
	if (i < 0) return NULL;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

LNode *LocateElem(LinkList &L, ElemType e) // 按值查找单链表（带头结点）第 i 个结点 
{
	LNode *p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}

int main()
{
	LinkList L;
	List_TailInsert(L);
	int i = 3;
	LNode *p = GetElem(L, i);
	printf("第 %d 个元素的值为 %d\n", i, p->data); 
	
	
	
}
