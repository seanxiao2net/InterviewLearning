#include <stdlib.h>
#include <stdio.h>

void insert_delete(int *arr, int insert, int delete)
{
	int i, tmp;

	tmp = arr[delete];

	for (i=delete; i> insert; i--)
	{
		arr[i] = arr[i-1];
	}

	arr[insert] = tmp;
}

void swap (int * num1, int * num2)
{
	int tmp;
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

int FindMin(int *arr, int start, int end)
{
	int i, min;
	min = start;

	for (i=start+1; i<=end; i++)
	{
		if (arr[i]<arr[min])
			min = i;
	}
	return min;
}

void selectionFast(int * arr, int arr_size)
{
	int i;

	for (i=0; i<arr_size; i++)
	{
		swap(&arr[i], &arr[FindMin(arr,i,arr_size-1)]);
	}

}

void selectionStable(int * arr, int arr_size)
{
	int i;

	for (i=0; i< arr_size; i++)
	{
		insert_delete(arr, i, FindMin(arr, i, arr_size-1));
	}
}

int main()
{
	int arr[]={3,4,2,5,6,7,1,2,9};
	printf("%d %d %d %d %d %d %d %d %d\n",arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8]);

	selectionStable(arr, sizeof(arr)/sizeof(int));

	//selectionFast(arr, sizeof(arr)/sizeof(int));

	printf("%d %d %d %d %d %d %d %d %d\n",arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8]);

	return 0;
}
