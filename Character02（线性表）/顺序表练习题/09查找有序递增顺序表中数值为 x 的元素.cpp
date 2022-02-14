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
void SearchExchangeInsert(SeqList &L, int x) //采用顺序查找 
{
	int i = 0;
	while (L.data[i] < x) i++;
	if (L.data[i] == x && i != L.length - 1)
	{
		int temp;
		temp = L.data[i];
		L.data[i] = L.data[i + 1];
		L.data[i + 1] = temp;
		return ;
	}
	if (L.data[i] > x)
	{
		for (int j = L.length; j > i; j--)
		{
			L.data[j] = L.data[j - 1];
		}
		L.data[i] = x;
		L.length++;
		return ;
	}
}

void SearchExchangeInsert_Mid(SeqList &L, int x) //采用折半查找，递增有序的顺序表用二分法查找更快 
{
	int low = 0, high = L.length-1, mid;
	
	while (low <= high)
	{
		mid = (low + high)/2;
		if (L.data[mid] == x) break;
		if (L.data[mid] < x)
		{
			low = mid + 1;
		}
		if (L.data[mid] > x)
		{
			high = mid - 1;
		}
	}
	if (L.data[mid] == x && mid != L.length - 1)
	{
		int temp;
		temp = L.data[mid];
		L.data[mid] = L.data[mid + 1];
		L.data[mid + 1] = temp;
	}
	if (low > high)
	{
		for (int j = L.length -1; j >= high + 1; j--)
		{
			L.data[j + 1] = L.data[j];
		}
		L.data[high + 1] = x;
		L.length++;
	}
} 
int main()
{
	SeqList L1;
	InitList(L1);
	PrintList(L1);
	
	SeqList L2;
	L2.MaxSize = InitSize;
	L2.length = 0;
	L2.data = (int *)malloc(sizeof(int)*L2.MaxSize);
	for (int i=0; i<L2.MaxSize; i++)
	{
		L2.data[i] = i * 2;
		L2.length++;
	}
	PrintList(L2);
	/*填入所要执行的函数......*/
	//SearchExchangeInsert(L1, 5);
	SearchExchangeInsert_Mid(L1, 5);
	PrintList(L1);
	
	//SearchExchangeInsert(L2, 5);
	SearchExchangeInsert_Mid(L2, 5);
	PrintList(L2);
	
	return 0;
}
