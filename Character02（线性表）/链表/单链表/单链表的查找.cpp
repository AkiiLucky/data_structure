#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct LNode{      //���嵥���������� 
	ElemType data;         //������ 
	struct LNode *next;    //ָ���� 
}LNode, *LinkList;

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

LNode *GetElem(LinkList &L, int i) // ��λ���ҵ�������ͷ��㣩�� i ����� 
{
	int j = 1; // ��������ʼΪ 1 
	LNode *p;
	p = L->next;
	if (i == 0) return L; // �� 0 ��������ͷ��� 
	if (i < 0) return NULL;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

LNode *LocateElem(LinkList &L, ElemType e) // ��ֵ���ҵ�������ͷ��㣩�� i ����� 
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
	printf("�� %d ��Ԫ�ص�ֵΪ %d\n", i, p->data); 
	
	
	
}
