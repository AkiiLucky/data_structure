#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct LNode{      //���嵥���������� 
	ElemType data;         //������ 
	struct LNode *next;    //ָ���� 
}LNode, *LinkList;

bool InitList(LinkList &L) //��ʼ��һ����������ͷ��㣩 
{
	L = (LNode *)malloc(sizeof(LNode));
	if(L == NULL) //�ڴ治�����ռ�ʧ�� 
	{
		return false;
	}
	L->next = NULL;
	return true;
}

LinkList List_TailInsert(LinkList &L) //β�巨���������� 
{
	ElemType x;
	L = (LinkList)malloc(sizeof(LNode)); //����ͷ��� 
	LNode *s, *r = L; // r Ϊ��βָ�� 
	scanf("%d", &x);
	while (x != -1)  //���� -1 ��ʾ���� 
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

LinkList List_HeadInsert(LinkList &L) //ͷ�巨���������� 
{
	LNode *s;
	ElemType x;
	L = (LinkList)malloc(sizeof(LNode)); //����ͷ��� 
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
