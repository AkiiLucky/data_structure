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

bool ListDelete(SqList &L, int i, int &num)  //ɾ���� i ��Ԫ�ز��ѵ� i ��Ԫ�ص�ֵ���� num 
{
	if (i<1||i>L.length)
	{
		return false;
	}
	num = L.data[i-1];
	for (int j = i; j <= L.length; j++)
	{
		L.data[j-1] = L.data[j];
	}
	L.length--;
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
	int num = -1;
	int i1 = 3;
	if (ListDelete(L, i1, num))
	{
		PrintList(L);
		printf("�� %d ��Ԫ���ѱ�ɾ��\n",i1);
		printf("��ɾ����Ԫ�ص�ֵΪ %d\n",num);
	}
	
	return 0;
}
