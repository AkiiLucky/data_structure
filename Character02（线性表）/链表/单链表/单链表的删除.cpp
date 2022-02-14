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

bool ListDelete(LinkList &L, int i, ElemType &e) //删除第 i 个位置的结点，并把值返回给 e 
{
	int j = 0;
	LNode *p = L;
	while(p != NULL && j < i-1) //先找到第 i-1 个结点 
	{
		p = p->next;
		j++;
	}
	if (p == NULL || p->next == NULL)
		return false;
	LNode *s = p->next;    // s 指向第 i 个结点
	e = s->data;
	p->next = s->next;     ////将 *s 从链中断开  
	free(s); 
}

bool DeleteNode(LNode *p) //删除指定结点 
{
	if (p == NULL && p->next == NULL) //如果 p 指向最后一个结点，不能用此方法删除  
		return false;
	LNode *q = p->next;      //令 q 指向 p 的后继结点
	p->data = p->next->data; //和后继结点交换数据域
	p->next = q->next;       //将 *q 从链中断开 
	free(q);                 //释放后继结点的存储空间 
}

int main()
{
	LinkList L;
	List_TailInsert(L);
	PrintList(L);
	
	ElemType e;
	if(ListDelete(L, 3, e))
	{
		PrintList(L);
		printf("被删除的结点的值为 %d\n", e);
	}
	
	
	return 0;
}
