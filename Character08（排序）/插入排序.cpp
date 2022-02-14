#include <stdio.h>

/* 直接插入排序 */
void InsertSort(int a[], int n)
{
	int i, j, tmp;
	for (i=1; i<n; i++)				//将各元素插入到已排好的序列中 
	{
		if (a[i-1] > a[i])			//若 a[i] 的直接前驱比它大 
		{
			tmp = a[i];				//用 tmp 暂存 a[i] 
			for (j=i-1; j>=0 && a[j] > tmp; j--)	//检查所有前面已排号序的元素 
			{
				a[j+1] = a[j];		//将大于 tmp 的所有元素后移一位 
			}
			a[j+1] = tmp;			//将 tmp 复制到插入位置 
		}
	}
}


/* 折半插入排序 */
void HulfInsertSort(int A[], int n)
{
	int i, j, low, high, mid;
	for (i=2; i<=n; i++)
	{
		A[0] = A[i];		//A[0]作为哨兵，暂存待插入元素 
		low = 1;
		high = i-1;
		
		while (low <= high)
		{
			mid = (low + high)/2;
			if (A[mid] > A[0]) high = mid-1;
			else low = mid+1;
		}
		for (j=i-1; j>=high+1; j--)	//将 [low, i-1] 的元素后移一位 
		{
			A[j+1] = A[j];
		}
		A[high+1] = A[0];				//插入到指定位置 
	}
}
 
 
/* 希尔排序 */
void ShellSort(int A[], int n)
{
	int d, i, j;
	for (d=n/2; d>=1; d=d/2)		//每轮 d 缩小一半 
	{
		for (i=d+1; i<=n; i++)
		{
			if (A[i] < A[i-d])		//这里的 A[0]只是临时存储单元，不是哨兵 
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
	/* 直接插入排序 */
	int arr1[10] = {6,3,0,1,9,2,4,5,8,7};
	InsertSort(arr1, 10);
	int i;
	for (i=0; i<10; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	
	
	/* 折半插入排序 */
	int arr2[11] = {-1,6,3,1,9,2,4,7,5,0,8};
	HulfInsertSort(arr2, 10);
	for (i=1; i<=10; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");
	
	
	/* 希尔排序 */
	int arr3[11] = {-1,6,3,1,9,2,4,7,5,0,8};
	ShellSort(arr3, 11);
	for (i=1; i<=10; i++)
	{
		printf("%d ", arr3[i]);
	}
	printf("\n");
	
	
	return 0;
} 
