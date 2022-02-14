#include <stdio.h>

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}


/* ð������ */
void BubbleSort(int A[], int n)
{
	int i, j, flag=1;				//flag��ʾ��������ʱ���� A �Ƿ��Ѿ����� 
	for (i=0; i<n-1; i++)
	{
		for (j=n-1; i<j; j--)
		{
			if (A[j-1] > A[j])
			{
				swap(A[j-1], A[j]);
				flag = 0;
			}
		}
		if (flag == 1) return ;		//��ǰ���� 
	}
	return ;
}


/* �������� */
int Partition(int A[], int low, int high)		//�õ�һ��Ԫ�ؽ����������л���Ϊ������������
{
	int pivot = A[low];							//��һ��Ԫ����Ϊ���� 
	while (low < high)
	{
		while (low < high && A[high] >= pivot) --high;
		A[low] = A[high];
		while (low < high && A[low] <= pivot) ++low;
		A[high] = A[low];
	} 
	A[low] = pivot;
	return low;
}

void QuickSort(int A[], int low, int high)
{
	if (low < high)
	{
		int pivotpos = Partition(A, low, high);	//���� 
		QuickSort(A, low, pivotpos-1);			//�������ӱ� 
		QuickSort(A, pivotpos+1, high);			//�������ӱ� 
	}
}


int main()
{
	/* ð������ */
	int A[10] = {3,1,9,6,2,5,7,4,0,8};
	BubbleSort(A, 10);
	int i;
	for (i=0; i<10; i++) printf("%d ", A[i]);
	printf("\n");
	
	/* �������� */
	int B[10] = {3,1,9,6,2,5,7,4,0,8};
	QuickSort(B, 0, 9);
	for (i=0; i<10; i++) printf("%d ", B[i]);
	printf("\n");
	
	
	return 0;
}
