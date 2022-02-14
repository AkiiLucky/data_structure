#include <stdio.h>
#include <stdlib.h>
#define ElemType int

/* 归并排序 */
ElemType *B = (ElemType *)malloc(10*sizeof(ElemType));
void Merge(ElemType A[], int low, int mid, int high)	//将两个有序子表合并 
{
	int i, j, k;
	for (k=low; k<=high; k++) B[k] = A[k];
	for (k=low,i=low,j=mid+1; i<=mid && j<=high; k++)
	{
		if (B[i] <= B[j]) A[k] = B[i++];
		else A[k] = B[j++];
	}
	while (i<=mid) A[k++] = B[i++];
	while (j<=high) A[k++] = B[j++];
}

void MergeSort(ElemType A[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high)/2;		//从中间划分两个子序列 
		MergeSort(A, low, mid);			//对左侧子序列递归排序 
		MergeSort(A, mid+1, high);		//对右侧子序列递归排序 
		Merge(A, low, mid, high);		//归并 
	} 
	
}


int main()
{
	/* 归并排序 */
	ElemType A[10] = {2,6,1,9,7,3,4,5,0,8};
	MergeSort(A, 0, 9);
	int i;
	for (i=0; i<10; i++) printf("%d ", A[i]);
	printf("\n");
	
	return 0;
} 
