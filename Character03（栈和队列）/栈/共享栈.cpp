#include <stdio.h>

#define ElemType int
#define MaxSize 10              //定义栈中最元素的最大个数 

//共享栈，两个栈共享同一片空间 
typedef struct {
	ElemType data[MaxSize];     //静态数组存放栈中元素 
	int top0;                   //0号栈顶指针        
	int top1;                   //1号栈顶指针             
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

bool Push(ShStack &S, ElemType x)  //进栈 
{
	;
}

bool Pop(ShStack &S, ElemType &x)  //出栈 
{
	;
}

bool GetTop(ShStack &S, ElemType &x)  //获取栈顶元素 
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
