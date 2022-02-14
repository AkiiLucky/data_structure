#include <stdio.h>

//顺序表的静态分配
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
	printf("顺序表的长度为 %d\n",L.length);
}

int main()
{
	SqList L;            //声明一个顺序表 
	InitList(L);
	PrintList(L);
	return 0;
}
