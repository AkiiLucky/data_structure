#include <stdio.h>

#define ElemType int 
#define MaxSize 10 //��̬�������󳤶� 
typedef struct {   //��̬����ṹ���͵Ķ��� 
	ElemType data; //�洢����Ԫ�� 
	int next;      //��һ��Ԫ�ص������±� 
} SLinkList[MaxSize];



int main()
{
	SLinkList a;
	a[0].next = -1; //��ʼ����ͷ�����һ��Ԫ�ص������±���Ϊ -1 
	
	return 0;
}
