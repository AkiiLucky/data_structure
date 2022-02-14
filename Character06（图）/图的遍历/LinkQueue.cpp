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
//初始化队列（带头结点） 
{
	Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));  //初始时，front, rear 都指向头结点 
	Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

void EnQueue(LinkQueue &Q, ElemType x)   //入队，增加一个元素到队尾 
{
	LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;                    //新结点插入到 rear 之后 
	Q.rear = s;                          //修改队尾指针 
} 

bool DeQueue(LinkQueue &Q, ElemType &x)  //出队, 队头元素出队 
{
	if (Q.front == Q.rear)
		return false;                    //队列为空，返回 false 
	LinkNode *tmp = Q.front->next;       
	x = tmp->data; 
	Q.front->next = tmp->next;
	if (tmp->next == NULL)               //最后一个结点出队需要修改队尾指针 
		Q.rear = Q.front;
	free(tmp);
	return true;
} 


