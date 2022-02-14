#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct LNode{      //定义单链表结点类型 
	ElemType data;         //数据域 
	struct LNode *next;    //指针域 
}LNode, *LinkList;

bool InitList(LinkList &L) //初始化一个单链表（带头结点） 
{
	L = (LNode *)malloc(sizeof(LNode));
	if(L == NULL) //内存不足分配空间失败 
	{
		return false;
	}
	L->next = NULL;
	return true;
}

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

LinkList List_HeadInsert(LinkList &L) //头插法建立单链表 
{
	LNode *s;
	ElemType x;
	L = (LinkList)malloc(sizeof(LNode)); //创建头结点 
	L->next = NULL;
	scanf("%d", &x);
	while (x != -1)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
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

int main()
{
	LinkList L;
	List_TailInsert(L);
	//List_HeadInsert(L);
	PrintList(L);
	return 0;
}
