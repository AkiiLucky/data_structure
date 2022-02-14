#include <stdio.h>
#include <stdlib.h> 
#define ElemType int
 
typedef struct{
	ElemType *elem;
	int TableLen;
}SSTable;

void Init(SSTable &L)
{
	L.elem = (ElemType *)malloc(sizeof(ElemType) * 10);
	L.TableLen = 0;
	int i; 
	for (i=0; i<10; i++)
	{
		L.elem[i] = i+1;
		L.TableLen++;
	}
}

void Print(SSTable L)
{
	printf("����� L: ");
	for (int i=0; i<L.TableLen; i++)
	{
		printf("%d ", L.elem[i]);
	}
	printf("\n");
}

int Binary_Search(SSTable L, ElemType key)		//�۰���� �������˳��� 
{
	int low = 0, high = L.TableLen-1, mid;
	while (low <= high)
	{
		mid = (low + high)/2;
		if (L.elem[mid] == key)
		{
			return mid;
		}
		else if(L.elem[mid] > key)
		{
			high = mid-1;
		}
		else
		{
			low = mid+1;
		}
	}
	return -1;		//����ʧ�� 
}

int main()
{
	SSTable L;
	Init(L);
	Print(L);
	int key, pos;
	printf("����Ҫ���ҵ�ֵ: ");
	scanf("%d", &key);
	pos = Binary_Search(L, key);
	if (pos != -1)
	{
		printf("��ֵ�ڵ� %d λ\n", pos+1);
	}
	else
	{
		printf("����ʧ��");
	} 
	return 0;
}
