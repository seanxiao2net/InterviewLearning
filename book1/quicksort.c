#include <stdio.h>
#include <stdlib.h>

void swap (int * num1, int * num2)
{
	int tmp;
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void quicksortOpt(int *arr, int start, int end)
{
	int pvot,l,r;
	l = start; r = end;
	pvot = arr[(start+end)/2];

	while (l<=r)
	{
		while (arr[l]<pvot) l++;
		while (arr[r]>pvot) r--;

		if (l<=r)
		{
			swap(&arr[l], &arr[r]);
			l++; r--;
		}
	}

	if (start < r)
		quicksortOpt(arr, start, r);
	if (l<end)
		quicksortOpt(arr, l, end);
}

void quicksort(int *arr, int start, int end)
{
	int pvot,i,j;

	if (end > start)
	{

		pvot = arr[start];
		i = start+1; j=end;

		while (i<j)
		{
			if (arr[i]>pvot)
			{
				swap(&arr[i],&arr[j]);
				j--;
			}
			else
				i++;
		}
		i--;
		swap(&arr[start], &arr[i]);

		quicksort(arr, start, i);
		quicksort(arr, i+1, end);
	}
}

int main()
{
	int arr[] = {54,76,12,34,143,34,878,443};
	printf("result: %d %d %d %d %d %d %d %d\n", arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7]);
	//quicksort(arr, 0, sizeof(arr)/sizeof(int)-1);
	quicksortOpt(arr, 0, sizeof(arr)/sizeof(int)-1);
	printf("result: %d %d %d %d %d %d %d %d\n", arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7]);
	return 0;
}
