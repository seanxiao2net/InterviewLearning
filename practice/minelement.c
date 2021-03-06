#include <stdio.h>

int bsearch(int arr[], int sz)
{
	int l=0, r = sz-1;
	int mid = (l+r)/2;

	while (arr[l]>arr[r])
	{
		mid = (l+r)/2;
		if (arr[mid]>arr[r])
			l = mid+1;
		else
			r = mid;
	}

	return arr[l];
}

int findMin(int arr[], int sz)
{
	int l=0, r, mid;
	//int rt;

	r = sz-1;

	while (arr[l]>arr[r])
	{
		mid = (l+r)/2;

		if (arr[mid]>arr[r])
		{
			l = mid+1;
		}
		else
		{
			r = mid;
		}

	}
	return arr[l];
}

int main()
{
	//int arr[] = {3,4,5,6,7,1,2};
	int arr[] = {1,2,3,4,5,6,7};
	int sz = sizeof(arr)/sizeof(int);
	int result;
	
	//result = findMin(arr, sz);
	result = bsearch(arr, sz);

	printf("resulr is %d\n", result);
	return 0;
}
