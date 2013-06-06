#include <stdio.h>
#include <stdlib.h>

int findMin(int arr[], int sz, int *l, int *r, int *val)
{
	int i;
	int x=0,y=0,z=0;
	int l_max = 0;
	int l_min = 0;

	for (i=0; i<sz; i++)
	{
		x += arr[i];

		if (x<y)	//update local minimium
		{
			y = x;
			l_min = i;
		}

		if (x-y > z)		// find local maximum
		{
			z = x-y;
			l_max = i;


			*l = l_min+1;
			*r = l_max;
			*val = z;
		}

		printf("x:%d y:%d z:%d\n", x, y, z);
	}

	return 0;
}


int main()
{
	int arr[] = {1,-3,5,-2,9,-8,-6,4};
	int l=0,r=0,val=0;

	findMin(arr, 8, &l, &r, &val);

	printf("the largest sub array start from %d to %d, total val %d\n", l, r, val);

	return 0;
}
