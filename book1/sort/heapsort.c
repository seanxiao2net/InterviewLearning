#include <stdio.h>
#include <stdlib.h>

void InsertHeap(int arr[], int current, int low, int end)
{
	int large = 2*low+1;	//child of low

	while (large <= end)
	{
		if (large < end && arr[large] < arr[large+1])
			large ++;

		if (current >= arr[large])
			break;
		else
		{
			arr[low] = arr[large];
			printf("low %d", arr[low]);
			low = large;
			large = 2*low +1;
		}
	}

	arr[low] = current;
}

void HeapInit(int arr[], int begin, int end)
{
	int low;
	int current;
	for (low = end/2; low >=begin; low --)
	{
		current = arr[low];
		InsertHeap(arr, current, low, end);
	}
}

int main()
{
	int i, current;
	int arr[10] = {1,2,3,4,5,6,8,9,10,11};

	HeapInit(arr, 0, 9);

	//for (i=0;i<10;i++)
		//printf("%d\n",arr[i]);

	current = arr[9];
	arr[9] = arr[0];
	InsertHeap(arr, current, 0, 9-1);

	for (i=0;i<10;i++)
		printf("%d\n",arr[i]);

	return 0;
}
