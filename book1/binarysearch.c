#include <stdio.h>
#include <stdlib.h>

/*int binarysearch(int * array, int lower, int upper, int target)*/
/*{*/
/*	int mid, range;*/
/*	*/
/*	range = upper - lower;*/
/*	mid = ((range)/2) +lower;*/
/*	if (range < 0)*/
/*		return -1;*/
/*	else if ((range == 0) && (array[lower]!=target))*/
/*	{*/
/*		return -2;*/
/*	}*/
/*	if (array[lower]>array[upper])*/
/*		return -3;*/


/*	if (array[mid] == target)*/
/*		return mid;*/
/*	else if (array[mid] > target)*/
/*	{*/
/*		return binarysearch(array, lower, mid -1, target);*/
/*	}*/
/*	else*/
/*	{*/
/*		return binarysearch(array, mid +1, upper, target);*/
/*	}*/
/*}*/

int binarysearch (int * arr, int lower, int upper, int tar)
{
	int mid;	

	mid = (lower+upper)/2;

	if (arr[lower]>arr[upper])
		return -3;

	if (lower > upper)
		return -1;
	else if ((lower == upper)&&(arr[lower]!=tar))
		return -2;

	if (arr[mid] == tar)
		return mid;
	else if (arr[mid] < tar)
	{
		return binarysearch(arr, mid+1, upper, tar);
	}
	else
		return binarysearch(arr, lower, mid-1, tar);

}

int binarysearch2 (int * arr, int lower, int upper, int tar)
{
	int mid;

	while (1)
	{
		mid = (lower+upper)/2;

		if (arr[lower] > arr[upper])
			return -3;

		if (lower > upper)
		{
			return -2;
		}
		else if (lower == upper && arr[lower]!=tar)
		{
			return -1;
		}
		else if (arr[mid]==tar)
		{
			return mid;
		}
		else if (arr[mid] < tar)
		{
			lower = mid+1;
		}
		else
		{
			upper = mid -1;
		}
	}

}

int main()
{
	int arr[10] = {1,2,3,4,5,6,8,9,10,11};
	int i,res;

	for (i=0;i<10;i++)
		//printf("%d\n",arr[i]);
	res = binarysearch2(arr, 0, 9, 7);
	printf("%d\n",res);

	return 0;
}
