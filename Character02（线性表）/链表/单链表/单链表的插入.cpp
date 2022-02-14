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

bool ListInsert(LinkList &L, int i, ElemType e)  //�ڵ� i ��λ�ò���ֵΪ e �Ľ�� , T(n) = O(n)
{
	if (i < 1) return false;
	int j = 0;
	LNode *p = L;
	while (p != NULL && j < i-1)    //Ѱ�ҵ� i-1 ��λ�� 
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

bool InsertNextNode(LNode *p, ElemType e) // ���������ڽ�� p ֮�����Ԫ�� e , T(n) = O(1)
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

bool InsertPriorNode(LNode *p, ElemType e) //ǰ��������ڽ�� p ֮ǰ����Ԫ�� e , T(n) = O(1)
{
	if (p == NULL) 
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if (s == NULL) 
		return false;
	s->data = e;
	s->next = p->next;   //�Ƚ���� s ���뵽��� p �ĺ���  
	p->next = s;
	ElemType temp;
	temp = p->data;      //�ٽ���� s �ͽ�� p �������򽻻� 
	p->data = s->data;
	s->data = temp;
	return true;
}

int main()
{
	
	LinkList L;
	List_TailInsert(L);
	PrintList(L);
		
	ListInsert(L, 3, 66); // ��Ԫ�� 66 ���뵽�� 3 ��λ��
	PrintList(L);
	
	LNode *p = GetElem(L, 5); //���ҵ� 5 ��λ�õĽ�� 
	InsertNextNode(p, 100);   //�ڵ� 5 ��λ��֮�����Ԫ�� 100 
	InsertPriorNode(p, 100);  //�ڵ� 5 ��λ��֮ǰ����Ԫ�� 100 
	PrintList(L);
	return 0;
}
