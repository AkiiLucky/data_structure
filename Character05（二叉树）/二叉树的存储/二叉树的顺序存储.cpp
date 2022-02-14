#include <stdio.h>

#define ElemType int
#define MaxSize 100

struct TreeNode{
	ElemType value;
	bool isEmpty;
};



void Init(TreeNode t[])
{
	for (int i = 0; i < MaxSize; i++)
	{
		t[i].isEmpty = true;
	}
}

void Print(TreeNode t[])
{
	for (int i = 0; i < MaxSize; i++)
	{
		printf("%d ", t[i].isEmpty);
	}
}
int main()
{
	TreeNode t[MaxSize];
	Init(t);
	Print(t);
	return 0;
}
