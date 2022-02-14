#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct BiTNode{
	ElemType data;                    //数据域 
	struct BiTNode *lchild, *rchild;  //左右孩子指针 
}BiTNode, *BiTree;

void InitTree(BiTree &boot)
{
	//创建根节点 
	boot = (BiTree)malloc(sizeof(BiTNode));
	boot->data = 1;
	boot->lchild = NULL;
	boot->rchild = NULL;
	
	//插入新结点 
	BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
	p->data = 2;
	p->lchild = NULL;
	p->rchild = NULL;
	boot->lchild = p;   //作为根节点的左孩子 
	
	//插入新结点 
	BiTNode *q = (BiTNode *)malloc(sizeof(BiTNode));
	q->data = 3;
	q->lchild = NULL;
	q->rchild = NULL;
	boot->rchild = q;   //作为根节点的右孩子 
}

void visit(BiTNode *p) 
{
	printf("%d ", p->data);
}

typedef struct LinkNode{
	BiTNode *Elems;
	struct LinkNode *next;
}LinkNode;

typedef struct LinkQueue{
	struct LinkNode *front, *rear;
}LinkQueue;

void InitQueue(LinkQueue &Q)
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

void EnQueue(LinkQueue &Q, BiTNode *p)   
{
	LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
	s->Elems = p;
	s->next = NULL;
	Q.rear->next = s;                    //新结点插入到 rear 之后 
	Q.rear = s;                          //修改队尾指针 
} 

bool DeQueue(LinkQueue &Q, BiTNode* &p)  //这里的 p 一定要使用引用符号 '&'  
{
	if (Q.front == Q.rear)
		return false;                    //队列为空，返回 false 
	LinkNode *tmp = Q.front->next;       
	p = tmp->Elems;
	Q.front->next = tmp->next;
	if (tmp->next == NULL)               //最后一个结点出队需要修改队尾指针 
	{
		Q.rear = Q.front;
		Q.rear->next = NULL;
	}
	free(tmp);
	return true;
} 

void LevelOrder(BiTree T)
{
	LinkQueue Q;
	InitQueue(Q); 
	BiTNode *p = NULL;
	
	EnQueue(Q, T);  //根结点入队
	while (!IsEmpty(Q))
	{
		DeQueue(Q, p);  //队头结点出队
		visit(p);
		if (p->lchild != NULL)
		{
			EnQueue(Q, p->lchild);  //左子树不空，则左子树根节点入队 
		}
		if (p->rchild != NULL)
		{
			EnQueue(Q, p->rchild);  //右子树不空，则右子树根节点入队 
		}
		free(p);
	} 
	free(Q.front);
}

int main()
{
	
	BiTree T;
	InitTree(T);
	//visit(T);
	//visit(T->lchild);
	//visit(T->rchild);
	LevelOrder(T);
	return 0;
}
