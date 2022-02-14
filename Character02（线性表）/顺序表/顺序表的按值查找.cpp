#include <stdio.h>

#define ElemType int

//æ≤Ã¨∑÷≈‰
#define MaxSize 10
typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;

int LocateElem(SqList &L, ElemType e)
{
	for (int i=0; i<L.length; i++)
	{
		if (L.data[i] == e) return (i+1);
	}
	return 0;
}

//∂ØÃ¨∑÷≈‰
#define InitSize 10
typedef struct {
	ElemType *data;
	int Max_Size;
	int length;
}SeqList;

int LocateElem(SeqList &L, ElemType e)
{
	for (int i=0; i<L.length; i++)
	{
		if (L.data[i] == e) return (i+1);
	}
	return 0;
}

int main()
{
	
	return 0;
}
