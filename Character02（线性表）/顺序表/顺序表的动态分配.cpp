#include <stdio.h>
#include <stdlib.h>

//顺序表的动态分配
#define ElemType int   //元素类型为整型 
#define InitSize 10    //顺序表的初始长度 
typedef struct {
	ElemType *data;    //指示动态分配数组的指针 
	int MaxSize;       //顺序表的最大容量 
	int length;        //顺序表的当前长度
}SeqList; 

void InitList(SeqList &L)
{
	L.data = (ElemType *)malloc(sizeof(ElemType)*InitSize);
	L.MaxSize = InitSize;
}

void IncreaseSize(SeqList &L,int len) //增加顺序表的长度 
{
	ElemType *p = L.data;
	L.data = (ElemType *)malloc(sizeof(ElemType)*(L.MaxSize+len));
	for (int i=0; i<L.length; i++)
	{
		L.data[i] = p[i];  //将数据复制到新区域 
	}
	L.MaxSize = InitSize + len;
	free(p);              //释放原来的内存空间 
}

int main()
{
	SeqList L;
	InitList(L);
	for (int i=0; i<L.MaxSize; i++) 
	{
		L.data[i] = i;
		L.length++;
	}
	IncreaseSize(L,5);   //给顺序表增加容量 
	return 0;
}
