#include <stdio.h>
#include <stdlib.h>

//˳���Ķ�̬����
#define ElemType int   //Ԫ������Ϊ���� 
#define InitSize 10    //˳���ĳ�ʼ���� 
typedef struct {
	ElemType *data;    //ָʾ��̬���������ָ�� 
	int MaxSize;       //˳����������� 
	int length;        //˳���ĵ�ǰ����
}SeqList; 

void InitList(SeqList &L)
{
	L.data = (ElemType *)malloc(sizeof(ElemType)*InitSize);
	L.MaxSize = InitSize;
}

void IncreaseSize(SeqList &L,int len) //����˳���ĳ��� 
{
	ElemType *p = L.data;
	L.data = (ElemType *)malloc(sizeof(ElemType)*(L.MaxSize+len));
	for (int i=0; i<L.length; i++)
	{
		L.data[i] = p[i];  //�����ݸ��Ƶ������� 
	}
	L.MaxSize = InitSize + len;
	free(p);              //�ͷ�ԭ�����ڴ�ռ� 
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
	IncreaseSize(L,5);   //��˳����������� 
	return 0;
}
