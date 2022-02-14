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

bool ListDelete(LinkList &L, int i, ElemType &e) //ɾ���� i ��λ�õĽ�㣬����ֵ���ظ� e 
{
	int j = 0;
	LNode *p = L;
	while(p != NULL && j < i-1) //���ҵ��� i-1 ����� 
	{
		p = p->next;
		j++;
	}
	if (p == NULL || p->next == NULL)
		return false;
	LNode *s = p->next;    // s ָ��� i �����
	e = s->data;
	p->next = s->next;     ////�� *s �����жϿ�  
	free(s); 
}

bool DeleteNode(LNode *p) //ɾ��ָ����� 
{
	if (p == NULL && p->next == NULL) //��� p ָ�����һ����㣬�����ô˷���ɾ��  
		return false;
	LNode *q = p->next;      //�� q ָ�� p �ĺ�̽��
	p->data = p->next->data; //�ͺ�̽�㽻��������
	p->next = q->next;       //�� *q �����жϿ� 
	free(q);                 //�ͷź�̽��Ĵ洢�ռ� 
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
		printf("��ɾ���Ľ���ֵΪ %d\n", e);
	}
	
	
	return 0;
}
