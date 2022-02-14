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

bool Empty(LinkList L) //�жϵ������Ƿ�Ϊ�ձ� 
{
	if (L->next == NULL) return true;
	else return false;
}

int main()
{
	LinkList L;
	InitList(L);
	if (Empty(L)) printf("����һ���ձ�"); 
	return 0;
}
