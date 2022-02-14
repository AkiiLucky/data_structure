#include <stdio.h>

#define ElemType int
#define MaxSize 10              //定义栈中最元素的最大个数 

typedef struct {
	ElemType data[MaxSize];     //静态数组存放栈中元素 
	int top;                    //栈顶指针，存放栈顶元素的数组下标 
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

bool Push(SqStack &S, ElemType x)  //进栈 
{
	if (S.top == MaxSize - 1)
		return false;
	S.top = S.top + 1;
	S.data[S.top] = x;
	return true;
}

bool Pop(SqStack &S, ElemType &x)  //出栈 
{
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	S.top = S.top - 1;
	return true;
}

bool GetTop(SqStack &S, ElemType &x)  //获取栈顶元素 
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
	if(Empty(S)) printf("栈为空！\n");
	return 0;
}
