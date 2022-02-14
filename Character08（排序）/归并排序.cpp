#include <stdio.h>
#include <stdlib.h>
#define ElemType int

/* �鲢���� */
ElemType *B = (ElemType *)malloc(10*sizeof(ElemType));
void Merge(ElemType A[], int low, int mid, int high)	//�����������ӱ�ϲ� 
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
		int mid = (low + high)/2;		//���м仮������������ 
		MergeSort(A, low, mid);			//����������еݹ����� 
		MergeSort(A, mid+1, high);		//���Ҳ������еݹ����� 
		Merge(A, low, mid, high);		//�鲢 
	} 
	
}


int main()
{
	/* �鲢���� */
	ElemType A[10] = {2,6,1,9,7,3,4,5,0,8};
	MergeSort(A, 0, 9);
	int i;
	for (i=0; i<10; i++) printf("%d ", A[i]);
	printf("\n");
	
	return 0;
} 
