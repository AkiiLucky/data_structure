#include <stdio.h>

//˳���ľ�̬����
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
	printf("˳���ĳ���Ϊ %d\n",L.length);
}

int main()
{
	SqList L;            //����һ��˳��� 
	InitList(L);
	PrintList(L);
	return 0;
}
