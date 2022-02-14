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

bool ListDelete(SqList &L, int i, int &num)  //删除第 i 个元素并把第 i 个元素的值赋给 num 
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
	SqList L;            //声明一个顺序表 
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
		printf("第 %d 个元素已被删除\n",i1);
		printf("被删除的元素的值为 %d\n",num);
	}
	
	return 0;
}
