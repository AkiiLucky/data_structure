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
bool DeleteMinElem(SqList &L,int &min)
{
	if (L.length == 0)
	{
		printf("SqList is Null");
		return false;
	}
	if (L.length > 0 && L.length <= MaxSize)
	{
		min = L.data[0];
		int j = 0;
		for (int i = 0; i < L.length; i++)
		{
			if (L.data[i] < min)
			{
				min = L.data[i];
				j = i;
			}
		}
		L.data[j] = L.data[L.length-1];//空出的位置由最后一个元素填补 
		L.length--;
		return true;
	}
}

int main()
{
	SqList L;
	InitList(L);
	PrintList(L);
	
	/*填入所要执行的函数......*/
	int min = -1;
	if (DeleteMinElem(L,min))
	{
		printf("the deleted Elem is %d\n",min);
	}
	PrintList(L);
	return 0;
}
