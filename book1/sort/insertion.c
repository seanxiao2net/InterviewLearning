#include <stdio.h>
#include <stdlib.h>

void Insertion(int arr[],int insert_pos, int come_from, int insert_val)
{
	int i = come_from;

	while (i>insert_pos)
	{
		arr[i] = arr[i-1];
		i--;
	}
	arr[insert_pos] = insert_val;
}

void InsertionSort(int arr[], int arr_size)
{
	int i,j;
	for (i=0; i<arr_size; i++)
	{
		for (j=0; j<i; j++)
		{
			if (arr[j]>arr[i])
			{
				Insertion(arr, j, i, arr[i]);
				break;
			}
		}
	}
}

int main()
{
	int arr[] = {54,76,12,34,143,34,878,443};

	InsertionSort(arr, sizeof(arr)/sizeof(int));
	printf("result: %d %d %d %d %d %d %d %d\n", arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7]);

	return 0;
}
