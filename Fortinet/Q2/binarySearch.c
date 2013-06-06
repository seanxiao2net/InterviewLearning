#include <stdio.h>

int bsearch(int *table, int sz, int key)
{
	int min = 0, max = sz-1, mid;

	if (table == 0)
		return -2;

	while (max >= min)
	{
		mid = (min + max)/2;

		if (table[mid] > key)
		{
			max = mid-1;
		}
		else if (table[mid] < key)
		{
			min = mid +1;
		}
		else	return mid;
	}

	return -1;	//key not found
}

int main()
{
	int t[] = {1,3,5,7,9};

	int result;

	result = bsearch(t, sizeof(t)/sizeof(int), 5);

	printf("result at index %d\n", result);

	return 0;
}
