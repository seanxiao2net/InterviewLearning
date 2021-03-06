#include <stdlib.h>
#include <stdio.h>

void swap(int * num1, int * num2)
{
	int tmp;
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void QuickSort(int arr[], int begin, int end)
{
	int pvot, l, r;
	if (end > begin +1)
	{
		pvot = arr[begin];
		l = begin +1;
		r = end;

		while (l<r)
		{
			if (arr[l]<=pvot)
			{
				l++;
			}
			else
			{
				swap(&arr[l],&arr[r--]);
			}
		}

		swap (&arr[begin], &arr[--l]);
		QuickSort(arr, begin, l);
		QuickSort(arr, r, end);
	}
}

int main()
{
	int arr[] = {54,76,12,34,143,34,878,443};
	printf("result: %d %d %d %d %d %d %d %d\n", arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7]);

	QuickSort(arr,0,sizeof(arr)/sizeof(int)-1);
	printf("result: %d %d %d %d %d %d %d %d\n", arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7]);

	return 0;
}
