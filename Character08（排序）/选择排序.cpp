#include <stdio.h>

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}


/* ��ѡ������ */ 
void SelectSort(int A[], int n)
{
	int i, j, min;
	for (i=0; i<n-1; i++)					//һ������ n-1 �� 
	{
		min = i;
		for (j=i+1; j<n; j++)
		{
			if (A[j] < A[min]) min = j;		//ѡ�� A[i...n]����С��Ԫ��	
		}
		if (min != i) swap(A[i], A[min]);	//��װ�� swap ���ƶ�Ԫ�� 3 �� 
	}
}



/* ������ */
void HeadAdjust(int A[], int k, int len)	
//���� k Ϊ������������Ϊ����� 
{
	A[0] = A[k];							//�� A[0] �ݴ������ĸ���� 
	int i;
	for (i=k*2; i<=len; i*=2)				//���Źؼ��ֽϴ���ֽ������ɸѡ 
	{
		if (i<len && A[i]<A[i+1]) i++;		//ȡ�ؼ��ֽϴ���ӽ����±� 
		if (A[0] >= A[i]) 
		{
			break;							//ɸѡ���� 
		} 
		else
		{
			A[k] = A[i]; 					//A[k]������˫�׽���� 
			k = i;							//�޸� k ֵ 
		}
	} 
	A[k] = A[0];							//��ɸѡ����ֵ��������λ�� 
}

void BuildMaxHeap(int A[], int len)
//��������� 
{
	int i;
	for (i=len/2; i>0; i--)					//�� i=[n/2]~1 ,���������� 
	{
		HeadAdjust(A, i, len);
	}
}

void HeapSort(int A[], int len)
//������ 
{
	BuildMaxHeap(A, len);					//��ʼ���� 
	int i;
	for (i=len; i>1; i--)					//n-1�˵Ľ����ͽ��ѹ��� 
	{
		swap(A[1], A[i]);					//����Ѷ�Ԫ�أ���ѵ�Ԫ�ؽ����� 
		HeadAdjust(A, 1, i-1);				//��������ʣ��� i-1 ��Ԫ������ɶ� 
	} 
}

int main()
{
	/* ��ѡ������ */ 
	int A[10] = {3,8,6,5,4,1,2,0,9,7};
	SelectSort(A, 10);
	int i;
	for (i=0; i<10; i++) printf("%d ", A[i]);
	printf("\n");
	
	
	/* ������ */
	int A1[11] = {-1,3,8,6,5,4,1,2,0,9,7};
	HeapSort(A1, 10);
	for (i=1; i<11; i++) printf("%d ", A1[i]);
	printf("\n");
	
	
	return 0;
} 
