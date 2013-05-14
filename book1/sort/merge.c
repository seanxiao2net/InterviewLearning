#include <stdio.h>
#include <stdlib.h>

void Merge(int arr[], int begin, int mid, int end)
{
	int *tmp;
	int i,j,k;

	tmp = malloc((end-begin+1)*sizeof(int));

	i = 0; j = begin; k = mid+1;

	while (j<=mid && k<=end)
	{
		if (arr[j]<=arr[k])
		{
			tmp[i] = arr[j];
			i++; j++;
		}
		else
		{
			tmp[i] = arr[k];
			i++; k++;
		}
	}

	while (j<=mid)
	{
		tmp[i] = arr[j];
		i++; j++;
	}

	while (k<=end)
	{
		tmp[i] = arr[k];
		i++; k++;
	}

	for (i=0; i< end-begin+1; i++)
	{
		arr[begin+i] = tmp[i];
	}
	//printf("%d %d %d %d %d %d %d %d %d\n",arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8]);

	free(tmp);

}

void MergeSort (int arr[], int begin, int end)
{
	int mid = (begin+end)/2;
	if (end-begin <1)	return;

	//printf("begin %d mid %d ", begin, mid);
	//printf("mid+1 %d end %d\n", mid+1, end);
	MergeSort(arr, begin, mid);
	MergeSort(arr, mid+1, end);
	
	//printf("begin %d mid %d end%d\n",begin,  mid, end);
	Merge(arr, begin, mid, end);
}


int main()
{
	int arr[]={3,4,2,5,6,7,1,2,9};
	printf("%d %d %d %d %d %d %d %d %d\n\n",arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8]);

	MergeSort(arr, 0, 8);
	printf("%d %d %d %d %d %d %d %d %d\n",arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8]);



	return 0;
}
