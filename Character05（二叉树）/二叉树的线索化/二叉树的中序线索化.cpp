#include <stdio.h>

//������������� ������ÿ�����������͵ĳ�����

void proc()
{
	int a;
	scanf("%d", &a);		//�����float ��ʹ��%f;�����double ��ʹ��%lf 

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