#include <stdio.h>

#define ElemType int
#define MaxSize 10              //����ջ����Ԫ�ص������� 

//����ջ������ջ����ͬһƬ�ռ� 
typedef struct {
	ElemType data[MaxSize];     //��̬������ջ��Ԫ�� 
	int top0;                   //0��ջ��ָ��        
	int top1;                   //1��ջ��ָ��             
} ShStack;

void InitStack(ShStack &S)
{
	S.top0 = -1;
	S.top1 = MaxSize;
	
}

bool Empty(ShStack S) 
{
	;
}

bool Push(ShStack &S, ElemType x)  //��ջ 
{
	;
}

bool Pop(ShStack &S, ElemType &x)  //��ջ 
{
	;
}

bool GetTop(ShStack &S, ElemType &x)  //��ȡջ��Ԫ�� 
{
	;
}

int main()
{
	ShStack S;
	InitStack(S);
	int x = 1;
	
	return 0;
}
