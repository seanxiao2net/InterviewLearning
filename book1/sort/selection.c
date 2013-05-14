#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int * arr, int arrsize)
{
	int i,token, tmp;

	for (i=0;i<arrsize;i++)
	{
		for (token=i+1; token<arrsize;token++)
		{
			if (arr[token]<arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[token];
				arr[token] = tmp;
			}	
		}
	}

}

void swap(int * num1, int * num2)
{
	int tmp;
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

int FindMin(int * arr, int start, int arrsize)
{
	int min;
	min = start++;
	//printf("start %d min %d\n", start, min);
	while (start < arrsize)
	{
		if (arr[start]<arr[min])
			min = start;
		start++;
	}
	return min;
}

void SelectionSortRecursive(int * arr, int start, int arrsize)
{
	int i;
	i = FindMin(arr, start, arrsize);
	//printf("min %d\n", i);
	swap (&arr[start], &arr[i]);
	if (start < arrsize-1)
		SelectionSortRecursive(arr, start+1, arrsize);

}

int main()
{
	int arr[]={3,4,2,5,6,7,1,2,9};
	printf("%d %d %d %d %d %d %d %d %d\n",arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8]);

	//SelectionSort(arr,sizeof(arr)/sizeof(int));
	SelectionSortRecursive(arr, 0, sizeof(arr)/sizeof(int));

	printf("%d %d %d %d %d %d %d %d %d\n",arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8]);

	return 0;
}
