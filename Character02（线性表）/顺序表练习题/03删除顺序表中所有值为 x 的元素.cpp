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

/*������ϰ��ĿҪ��ĺ���......*/ 
void Delete_x_1(SqList &L, int x)
{
	int j = 0; // j ��¼ֵ������ x ��Ԫ�ظ��� 
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] != x)
		{
			L.data[j] = L.data[i];
			j++;
		}
	}
	L.length = j;
}

void Delete_x_2(SqList &L, int x)
{
	int i = 0, j = 0; // j ��¼ֵ���� x ��Ԫ�ظ���
	while (i < L.length)
	{
		if (L.data[i] == x)
		{
			j++;
		}
		else
		{
			L.data[i-j] = L.data[i];	
		}
		i++;
	}
	L.length = L.length - j;
}

int main()
{
	SqList L;
	InitList(L);
	PrintList(L);
	
	/*������Ҫִ�еĺ���......*/
	Delete_x_1(L, 5);
	PrintList(L);
	Delete_x_2(L, 6);
	PrintList(L);
	return 0;
}
