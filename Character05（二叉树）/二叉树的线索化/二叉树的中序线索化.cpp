#include <stdio.h>

//针对先输入组数 再输入每组数据是整型的程序框架

void proc()
{
	int a;
	scanf("%d", &a);		//如果是float 则使用%f;如果是double 则使用%lf 

	int i;
	for (i = 2; i <= a; i++)
	{
		if (a % i == 0)
		{
			printf("%d*", i);
			a = a / i;
			i = 2;

		}

	}
	printf("\n");
}

int main()
{
	int n = 0, i = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		proc();
	}
	return 0;
}