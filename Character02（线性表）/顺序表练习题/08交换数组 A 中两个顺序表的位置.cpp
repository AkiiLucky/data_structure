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
void Init_A(int A[], SeqList &L1, SeqList &L2)
{
	for (int i = 0; i < L1.length; i++)
	{
		A[i] = L1.data[i];
	}
	for (int j = 0; j < L2.length; j++)
	{
		A[j + L1.length] = L2.data[j];
	}
}

void Reverse(int A[], int left, int right, int arraySize)
{
	if (left >= right || right >= arraySize)
	{
		return ;
	}
	int temp;
	while (left <= right)
	{
		temp = A[left];
		A[left] = A[right];
		A[right] = temp;
		left++;
		right--;
	}
}

void Exchange_L1_L2(int A[], int m, int n, int arraySize)
{
	Reverse(A, 0, m + n -1, arraySize);//先将 A[m + n] 中全部元素逆置 
	Reverse(A, 0, n - 1, arraySize);//再逆置前面的顺序表 
	Reverse(A, n, m + n - 1, arraySize);////再逆置后面的顺序表 
}
int main()
{
	SeqList L1;
	InitList(L1);
	for (int i=0; i<L1.MaxSize; i++)
	{
		L1.data[i] = i;
		L1.length++;
	}
	PrintList(L1);
	
	SeqList L2;
	InitList(L2);
	for (int i=0; i<6; i++)
	{
		L2.data[i] = 9 - i;
		L2.length++;
	}
	PrintList(L2);
	
	/*填入所要执行的函数......*/
	int arraySize = L1.length + L2.length;
	int A[arraySize];
	Init_A(A, L1, L2);
	printf("初始时数组 A[]:");
	for (int i = 0; i < arraySize; i++)
	{	
		printf("%d ",A[i]);
	}
	printf("\n");
	
	Exchange_L1_L2(A, L1.length, L2.length, arraySize);
	printf("交换两个顺序表的位置后数组 A[]:");
	for (int i = 0; i < arraySize; i++)
	{	
		printf("%d ",A[i]);
	}
	printf("\n");
	return 0;
}
