#include <stdio.h>

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}


/* 冒泡排序 */
void BubbleSort(int A[], int n)
{
	int i, j, flag=1;				//flag表示这趟排序时数组 A 是否已经有序 
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
		if (flag == 1) return ;		//提前结束 
	}
	return ;
}


/* 快速排序 */
int Partition(int A[], int low, int high)		//用第一个元素将待排序序列划分为左右两个部分
{
	int pivot = A[low];							//第一个元素作为枢轴 
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
		int pivotpos = Partition(A, low, high);	//划分 
		QuickSort(A, low, pivotpos-1);			//划分左子表 
		QuickSort(A, pivotpos+1, high);			//划分右子表 
	}
}


int main()
{
	/* 冒泡排序 */
	int A[10] = {3,1,9,6,2,5,7,4,0,8};
	BubbleSort(A, 10);
	int i;
	for (i=0; i<10; i++) printf("%d ", A[i]);
	printf("\n");
	
	/* 快速排序 */
	int B[10] = {3,1,9,6,2,5,7,4,0,8};
	QuickSort(B, 0, 9);
	for (i=0; i<10; i++) printf("%d ", B[i]);
	printf("\n");
	
	
	return 0;
}
