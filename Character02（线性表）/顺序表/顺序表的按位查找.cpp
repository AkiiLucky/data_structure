#include <stdio.h>

#define ElemType int

//æ≤Ã¨∑÷≈‰
#define MaxSize 10
typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;

ElemType GetElem(SqList &L, int i)
{
	return L.data[i-1];
}

//∂ØÃ¨∑÷≈‰
#define InitSize 10
typedef struct {
	ElemType *data;
	int Max_Size;
	int length;
}SeqList;

ElemType GetElem(SeqList &L, int i)
{
	return L.data[i-1];
}

int main()
{
	
	return 0;
}
