#include <stdio.h>

#define MaxSize 10       //定义最大长度 
typedef struct {
	int data[MaxSize];   //用静态的数组存放数据元素 
	int length;          //顺序表当前的长度 
}SqList;                 //顺序表的类型定义（静态分配方式） 

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
	printf("顺序表当前的长度为 %d\n",L.length);
}

bool ListInsert(SqList &L, int i, int num)  //在第 i 个元素前面插入 num 
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
	SqList L;            //声明一个顺序表 
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
