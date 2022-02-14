#include <stdio.h>

#define MaxSize 10

typedef struct {
	int data[MaxSize];
	int length;
}SqList;

void InitList(SqList &L)
{
	L.length = 0;
	for (int i=0; i<3; i++)
	{
		L.data[i] = 0;
		L.length++;
	}
	L.data[0] = 1;
	L.data[1] = 1;
	L.data[2] = 2;
	L.data[3] = 3;
	L.data[4] = 4;
	L.data[5] = 4;
	L.data[6] = 4;
	L.data[7] = 5;
	L.data[8] = 6;
	L.data[9] = 6;
	L.length = 10;
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
bool Del_Same(SqList &L)
{
	int i, j;
	for (i = 0,j = 1; j < L.length; j++)
	{
		if (L.data[i] != L.data[j])
		{
			L.data[i + 1] = L.data[j];
			i = i + 1;
		}
	}
	L.length = i + 1;
	return true;
} 

int main()
{
	SqList L;
	InitList(L);
	PrintList(L);
	
	/*填入所要执行的函数......*/
	Del_Same(L);
	PrintList(L);
	return 0;
}
