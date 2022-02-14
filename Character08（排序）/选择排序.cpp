#include <stdio.h>

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}


/* 简单选择排序 */ 
void SelectSort(int A[], int n)
{
	int i, j, min;
	for (i=0; i<n-1; i++)					//一共进行 n-1 趟 
	{
		min = i;
		for (j=i+1; j<n; j++)
		{
			if (A[j] < A[min]) min = j;		//选择 A[i...n]中最小的元素	
		}
		if (min != i) swap(A[i], A[min]);	//封装的 swap 共移动元素 3 次 
	}
}



/* 堆排序 */
void HeadAdjust(int A[], int k, int len)	
//将以 k 为根的子树调整为大根堆 
{
	A[0] = A[k];							//用 A[0] 暂存子树的根结点 
	int i;
	for (i=k*2; i<=len; i*=2)				//沿着关键字较大的字结点向下筛选 
	{
		if (i<len && A[i]<A[i+1]) i++;		//取关键字较大的子结点的下标 
		if (A[0] >= A[i]) 
		{
			break;							//筛选结束 
		} 
		else
		{
			A[k] = A[i]; 					//A[k]调整到双亲结点上 
			k = i;							//修改 k 值 
		}
	} 
	A[k] = A[0];							//被筛选结点的值放入最终位置 
}

void BuildMaxHeap(int A[], int len)
//建立大根堆 
{
	int i;
	for (i=len/2; i>0; i--)					//从 i=[n/2]~1 ,反复调整堆 
	{
		HeadAdjust(A, i, len);
	}
}

void HeapSort(int A[], int len)
//堆排序 
{
	BuildMaxHeap(A, len);					//初始建堆 
	int i;
	for (i=len; i>1; i--)					//n-1趟的交换和建堆过程 
	{
		swap(A[1], A[i]);					//输出堆顶元素（与堆低元素交换） 
		HeadAdjust(A, 1, i-1);				//调整，把剩余的 i-1 个元素整理成堆 
	} 
}

int main()
{
	/* 简单选择排序 */ 
	int A[10] = {3,8,6,5,4,1,2,0,9,7};
	SelectSort(A, 10);
	int i;
	for (i=0; i<10; i++) printf("%d ", A[i]);
	printf("\n");
	
	
	/* 堆排序 */
	int A1[11] = {-1,3,8,6,5,4,1,2,0,9,7};
	HeapSort(A1, 10);
	for (i=1; i<11; i++) printf("%d ", A1[i]);
	printf("\n");
	
	
	return 0;
} 
