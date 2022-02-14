#include <stdio.h>
#include <stdlib.h>

#define InitSize 10

typedef struct {
	int *data;
	int MaxSize;
	int length;
}SeqList;

void InitList(SeqList &L)
{
	L.MaxSize = InitSize;
	L.length = 0;
	L.data = (int *)malloc(sizeof(int)*L.MaxSize);
	for (int i=0; i<L.MaxSize; i++)
	{
		L.data[i] = i;
		L.length++;
	}
}

void IncreaseList(SeqList &L, int len)
{
	int *p = L.data;
	L.data = (int *)malloc(sizeof(int)*(L.MaxSize + len));
	for (int i = 0; i < L.length; i++)
	{
		L.data[i] = p[i];
	}
	L.MaxSize += len;
	free(p);
}

void PrintList(SeqList &L)
{
	for (int i=0; i<L.length; i++)
	{
		printf("%d ",L.data[i]);
	}
	printf("\n");
	printf("the length of SqList is %d\n",L.length);
}

/*定义练习题目要求的函数......*/ 

int main()
{
	SeqList L;
	InitList(L);
	PrintList(L);
	
	/*填入所要执行的函数......*/
	PrintList(L);
	return 0;
}
