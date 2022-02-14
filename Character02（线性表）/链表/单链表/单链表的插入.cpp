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

bool ListInsert(LinkList &L, int i, ElemType e)  //在第 i 个位置插入值为 e 的结点 , T(n) = O(n)
{
	if (i < 1) return false;
	int j = 0;
	LNode *p = L;
	while (p != NULL && j < i-1)    //寻找第 i-1 个位置 
	{
		p = p->next;
		j++;
	}
	if (p == NULL && j > i-1) return false; 
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
	
}

bool InsertNextNode(LNode *p, ElemType e) // 后插操作：在结点 p 之后插入元素 e , T(n) = O(1)
{
	if (p == NULL) 
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if (s == NULL) 
		return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;	
} 

bool InsertPriorNode(LNode *p, ElemType e) //前插操作：在结点 p 之前插入元素 e , T(n) = O(1)
{
	if (p == NULL) 
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if (s == NULL) 
		return false;
	s->data = e;
	s->next = p->next;   //先将结点 s 插入到结点 p 的后面  
	p->next = s;
	ElemType temp;
	temp = p->data;      //再将结点 s 和结点 p 的数据域交换 
	p->data = s->data;
	s->data = temp;
	return true;
}

int main()
{
	
	LinkList L;
	List_TailInsert(L);
	PrintList(L);
		
	ListInsert(L, 3, 66); // 将元素 66 插入到第 3 个位置
	PrintList(L);
	
	LNode *p = GetElem(L, 5); //查找第 5 个位置的结点 
	InsertNextNode(p, 100);   //在第 5 个位置之后插入元素 100 
	InsertPriorNode(p, 100);  //在第 5 个位置之前插入元素 100 
	PrintList(L);
	return 0;
}
