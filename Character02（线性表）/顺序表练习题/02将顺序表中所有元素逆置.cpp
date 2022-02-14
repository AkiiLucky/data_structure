#include <stdio.h>

#define MaxSize 10

typedef struct {
	int data[MaxSize];
	int length;
}SqList;

void InitList(SqList &L)
{
	L.length = 0;
	for (int i=0; i<MaxSize; i++)
	{
		L.data[i] = i;
		L.length++;
	}
}

void PrintList(SqList &L)
{
	for (int i=0; i<L.length; i++)
	{
		printf("%d ",L.data[i]);
	}
	printf("\n");
	printf("the length of SqList is %d\n",L.length);
}

/*定义练习题目要求的函数......*/ 
void ReverseList(SqList &L)
{
	int temp;
	for (int i = 0; i < L.length/2 ; i++)
	{
		temp = L.data[i];
		L.data[i] = L.data[L.length-1-i];
		L.data[L.length-1-i] = temp;
	}
}

int main()
{
	SqList L;
	InitList(L);
	PrintList(L);
	
	/*填入所要执行的函数......*/
	ReverseList(L);
	PrintList(L);
	
	return 0;
}
