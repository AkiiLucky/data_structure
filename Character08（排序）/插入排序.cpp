#include <stdio.h>

/* ֱ�Ӳ������� */
void InsertSort(int a[], int n)
{
	int i, j, tmp;
	for (i=1; i<n; i++)				//����Ԫ�ز��뵽���źõ������� 
	{
		if (a[i-1] > a[i])			//�� a[i] ��ֱ��ǰ�������� 
		{
			tmp = a[i];				//�� tmp �ݴ� a[i] 
			for (j=i-1; j>=0 && a[j] > tmp; j--)	//�������ǰ�����ź����Ԫ�� 
			{
				a[j+1] = a[j];		//������ tmp ������Ԫ�غ���һλ 
			}
			a[j+1] = tmp;			//�� tmp ���Ƶ�����λ�� 
		}
	}
}


/* �۰�������� */
void HulfInsertSort(int A[], int n)
{
	int i, j, low, high, mid;
	for (i=2; i<=n; i++)
	{
		A[0] = A[i];		//A[0]��Ϊ�ڱ����ݴ������Ԫ�� 
		low = 1;
		high = i-1;
		
		while (low <= high)
		{
			mid = (low + high)/2;
			if (A[mid] > A[0]) high = mid-1;
			else low = mid+1;
		}
		for (j=i-1; j>=high+1; j--)	//�� [low, i-1] ��Ԫ�غ���һλ 
		{
			A[j+1] = A[j];
		}
		A[high+1] = A[0];				//���뵽ָ��λ�� 
	}
}
 
 
/* ϣ������ */
void ShellSort(int A[], int n)
{
	int d, i, j;
	for (d=n/2; d>=1; d=d/2)		//ÿ�� d ��Сһ�� 
	{
		for (i=d+1; i<=n; i++)
		{
			if (A[i] < A[i-d])		//����� A[0]ֻ����ʱ�洢��Ԫ�������ڱ� 
			{
				A[0] = A[i];
				for (j=i-d; j>0 && A[j]>A[0]; j-=d)
				{
					A[j+d] = A[j];
				}
				A[j+d] = A[0];
			}
		}
	}
}


int main()
{
	/* ֱ�Ӳ������� */
	int arr1[10] = {6,3,0,1,9,2,4,5,8,7};
	InsertSort(arr1, 10);
	int i;
	for (i=0; i<10; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	
	
	/* �۰�������� */
	int arr2[11] = {-1,6,3,1,9,2,4,7,5,0,8};
	HulfInsertSort(arr2, 10);
	for (i=1; i<=10; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");
	
	
	/* ϣ������ */
	int arr3[11] = {-1,6,3,1,9,2,4,7,5,0,8};
	ShellSort(arr3, 11);
	for (i=1; i<=10; i++)
	{
		printf("%d ", arr3[i]);
	}
	printf("\n");
	
	
	return 0;
} 
