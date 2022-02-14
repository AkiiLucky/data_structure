#include <stdio.h>

#define ElemType int
#define MaxSize 10              //����ջ����Ԫ�ص������� 

typedef struct {
	ElemType data[MaxSize];     //��̬������ջ��Ԫ�� 
	int top;                    //ջ��ָ�룬���ջ��Ԫ�ص������±� 
} SqStack;

void InitStack(SqStack &S)
{
	S.top = -1;
}

bool Empty(SqStack S) 
{
	if (S.top == -1)
		return true;
	else 
		return false;
}

bool Push(SqStack &S, ElemType x)  //��ջ 
{
	if (S.top == MaxSize - 1)
		return false;
	S.top = S.top + 1;
	S.data[S.top] = x;
	return true;
}

bool Pop(SqStack &S, ElemType &x)  //��ջ 
{
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	S.top = S.top - 1;
	return true;
}

bool GetTop(SqStack &S, ElemType &x)  //��ȡջ��Ԫ�� 
{
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	return true;
}

int main()
{
	SqStack S;
	InitStack(S);
	int x = 1;
	Push(S, x);
	GetTop(S, x);
	printf("x = %d\n", x);
	Pop(S, x);
	if(Empty(S)) printf("ջΪ�գ�\n");
	return 0;
}
