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

bool Empty(LinkList L) //判断单链表是否为空表 
{
	if (L->next == NULL) return true;
	else return false;
}

int main()
{
	LinkList L;
	InitList(L);
	if (Empty(L)) printf("这是一个空表"); 
	return 0;
}
