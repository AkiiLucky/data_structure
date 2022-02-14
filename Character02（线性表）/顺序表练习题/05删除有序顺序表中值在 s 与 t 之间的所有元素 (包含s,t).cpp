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
bool Del_s_to_t(SqList &L, int s, int t)
{
	if (s >= t || L.length == 0)
	{
		return false;
	}
	int j = 0; // j 表示有序顺序表中大于 s 且小于 t 的元素个数 
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] >= s && L.data[i] <= t)
		{
			j++;
		}
		else
		{
			L.data[i-j] = L.data[i];
		}
	}
	if (j == 0) return false; 
	L.length = L.length - j;
	return true;
}

int main()
{
	SqList L;
	InitList(L);
	PrintList(L);
	
	/*填入所要执行的函数......*/
	Del_s_to_t(L, 3, 7);
	PrintList(L);
	return 0;
}
