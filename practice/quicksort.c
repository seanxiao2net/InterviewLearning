#include <stdio.h>
#include <stdlib.h>

void swap(int *num1, int *num2)
{
	int tmp;
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void QuickSort(int arr[], int begin, int end)
{
	int pivot, l, r;
	if (end > begin +1)
	{

		pivot = arr[begin];
		l = begin +1;
		r = end;

		while (l < r)
		{
			if (arr[l]<=pivot)
				l++;
			else
			{
				swap(&arr[l], &arr[r]);
				r--;
			}
		}

		swap(&arr[begin], &arr[--l]);
		//--l;
		QuickSort(arr, begin, l);
		QuickSort(arr, l+1, end);
	}
}

void QuickSortFast(int arr[], int begin, int end)
{
	int pivot, i, j, mid;

	mid = (begin + end)/2;

	pivot = arr[mid];
	i = begin; j = end;

	while (i<=j)
	{
		while (arr[i]<pivot) i++;
		while (arr[j]>pivot) j--;

		if (i<=j)
		{
			swap(&arr[i], &arr[j]);
			++i;--j;
		}
	}

	if (begin<j)
		QuickSortFast(arr, begin, j);

	if (i<end)
		QuickSortFast(arr, i, end);

}

int main()
{
	int arr[] = {54,76,12,34,143,34,878,443};
	printf("result: %d %d %d %d %d %d %d %d\n", arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7]);

	//QuickSort(arr,0,sizeof(arr)/sizeof(int)-1);
	QuickSortFast(arr, 0, sizeof(arr)/sizeof(int)-1);
	//QuickSortFast1(arr);
	printf("result: %d %d %d %d %d %d %d %d\n", arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7]);

	return 0;
}
