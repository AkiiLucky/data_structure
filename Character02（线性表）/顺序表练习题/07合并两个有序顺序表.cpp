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
bool Merge(SeqList L1, SeqList L2, SeqList &L)
{
	if ((L1.length + L2.length) > L.MaxSize) return false;
	int i = 0, j = 0, k = 0;
	while (i < L1.length && j < L2.length) //两两比较，小者存入结果表 
	{
		if (L1.data[i] <= L2.data[j])
		{
			L.data[k] = L1.data[i];
			i++;
		}
		else
		{
			L.data[k] = L2.data[j];
			j++;
		}
		k++;
	}
	for (;i < L1.length; i++)              //还剩一个没有比较完的顺序表 
	{
		L.data[k] = L1.data[i];
		k++;
	}
	for (;j < L2.length; j++)
	{
		L.data[k] = L2.data[j];
		k++;
	}
	L.length = k;
	return true;
}

int main()
{
	SeqList L1, L2;
	InitList(L1);
	PrintList(L1);
	InitList(L2);
	PrintList(L2);
	
	/*填入所要执行的函数......*/
	SeqList L;
	L.MaxSize = L1.length + L2.length;
	L.data = (int *)malloc((sizeof(int))*(L.MaxSize));
	L.length = 0;
	
	Merge(L1, L2, L);
	PrintList(L);
	return 0;
}
