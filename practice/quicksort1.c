#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b)
{
	if (a == b) return;
	*a = *a + *b;
	*b = *b - *a;	//-a
	*a = *a + *b;
	*b = -*b;
} 

/*void swap(int *a, int *b)*/
/*{*/
/*	int tmp;*/
/*	tmp = *a;*/
/*	*a = *b;*/
/*	*b = tmp;*/
/*}*/

void QS(int arr[], int start, int end)
{
	int mid = (start+end)/2;
	int pivot = arr[mid];
	int l=start, r=end;

	while (l<=r)
	{
		while (arr[l]<pivot) ++l;
		while (arr[r]>pivot) --r;

		if(l<=r)	
			swap(&arr[l++],&arr[r--]);
	}

	if (start < r)	QS(arr, start, r);
	if (end > l)	QS(arr, l, end);
}

int main()
{
	int arr[] = {54,76,12,34,143,34,878,443};
	printf("result: %d %d %d %d %d %d %d %d\n", arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7]);
	QS(arr,0,sizeof(arr)/sizeof(int)-1);
	printf("result: %d %d %d %d %d %d %d %d\n", arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7]);
	return 0;
}
