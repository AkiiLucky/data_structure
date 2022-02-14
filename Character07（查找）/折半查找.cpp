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
	printf("有序表 L: ");
	for (int i=0; i<L.TableLen; i++)
	{
		printf("%d ", L.elem[i]);
	}
	printf("\n");
}

int Binary_Search(SSTable L, ElemType key)		//折半查找 有序递增顺序表 
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
	return -1;		//查找失败 
}

int main()
{
	SSTable L;
	Init(L);
	Print(L);
	int key, pos;
	printf("输入要查找的值: ");
	scanf("%d", &key);
	pos = Binary_Search(L, key);
	if (pos != -1)
	{
		printf("该值在第 %d 位\n", pos+1);
	}
	else
	{
		printf("查找失败");
	} 
	return 0;
}
