#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct LinkNode {
	ElemType data;
	struct LinkNode *next;
} LinkNode;

typedef struct {
	LinkNode *front, *rear;
} LinkQueue;

 
void InitQueue(LinkQueue &Q)
//��ʼ�����У���ͷ��㣩 
{
	Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));  //��ʼʱ��front, rear ��ָ��ͷ��� 
	Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

void EnQueue(LinkQueue &Q, ElemType x)   //��ӣ�����һ��Ԫ�ص���β 
{
	LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;                    //�½����뵽 rear ֮�� 
	Q.rear = s;                          //�޸Ķ�βָ�� 
} 

bool DeQueue(LinkQueue &Q, ElemType &x)  //����, ��ͷԪ�س��� 
{
	if (Q.front == Q.rear)
		return false;                    //����Ϊ�գ����� false 
	LinkNode *tmp = Q.front->next;       
	x = tmp->data; 
	Q.front->next = tmp->next;
	if (tmp->next == NULL)               //���һ����������Ҫ�޸Ķ�βָ�� 
		Q.rear = Q.front;
	free(tmp);
	return true;
} 


