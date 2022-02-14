#include <stdio.h>

#define MaxSize 10       //������󳤶� 
typedef struct {
	int data[MaxSize];   //�þ�̬������������Ԫ�� 
	int length;          //˳���ǰ�ĳ��� 
}SqList;                 //˳�������Ͷ��壨��̬���䷽ʽ�� 

void InitList(SqList &L)
{
	int i = 0;
	for (i;i < MaxSize;i++)
	{
		L.data[i] = 0;
	}
	L.length = 0;
}

void PrintList(SqList &L)
{
	int i = 0;
	for (i;i < MaxSize;i++)
	{
		printf("%d ",L.data[i]);
	}
	printf("\n");
	printf("˳���ǰ�ĳ���Ϊ %d\n",L.length);
}

bool ListInsert(SqList &L, int i, int num)  //�ڵ� i ��Ԫ��ǰ����� num 
{
	if (L.length >= MaxSize)
	{
		return false;
	}
	if (i<1||i>L.length+1)
	{
		return false;
	}
	for (int j = L.length+1; j >= i; j--)
	{
		L.data[j] = L.data[j-1];
	}
	L.data[i-1] = num;
	L.length++;
	return true;
}

int main()
{
	SqList L;            //����һ��˳��� 
	InitList(L);
	for (int i=0; i<5; i++)
	{
		L.data[i] = i + 1;
		L.length++;
	}
	PrintList(L);
	if (ListInsert(L, 3, 666))
	{
		PrintList(L);
	}
	
	return 0;
}
