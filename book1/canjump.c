#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 999

//Here is the recursive solution
int MinJump(int arr[],int begin, int end)
{
	int i, min=INT_MAX;
	int jumps;
	if (arr[begin]==0)
		return INT_MAX;

	if (begin == end)
		return 0;

	for (i=begin+1; i<=end && i<=begin + arr[begin]; i++)
	{
		jumps = MinJump (arr, i, end);
		if (jumps +1 < min)
			min = jumps+1;
	}
	return min;

}

int minJumps2(int arr[], int l, int h)
{
	int i, jumps;

   if (h == l)
     return 0;

   if (arr[l] == 0)
     return INT_MAX;

   int min = INT_MAX;
   for (i = l+1; i <= h && i <= l + arr[l]; i++)
   {
       jumps = minJumps2(arr, i, h);
       if(jumps != INT_MAX && jumps + 1 < min)
           min = jumps + 1;
   }
 
   return min;
}

//Another solution based on dynamical programming
int MinJump2(int arr[], int arrsize)
{
	int i,j, min;
	int tmp[arrsize];

	for (i=0; i<arrsize; i++)
		tmp[i] = 0;

	for (i=1; i<arrsize; i++)
	{
		min = INT_MAX;
		if (arr[i]==0)
			tmp[i] = INT_MAX;
		for (j = i; j>=0; j--)
		{
			
			if ((j+arr[j]>=i)&&(tmp[j]+1 <= min))
				tmp[i] = tmp[j]+1;

		}


	}

	return tmp[arrsize -1];
}

int minJumps(int arr[], int n)
{
    int jumps[n];  // jumps[n-1] will hold the result
    int i, j;
 
    if (n == 0 || arr[0] == 0)
        return INT_MAX;
 
    jumps[0] = 0;
 
    // Find the minimum number of jumps to reach arr[i]
    // from arr[0], and assign this value to jumps[i]
    for (i = 1; i < n; i++)
    {
        jumps[i] = INT_MAX;
        for (j = 0; j < i; j++)
        {
            if (i <= j + arr[j] && jumps[j] != INT_MAX)
            {
                 jumps[i] = jumps[j] + 1;
                 break;
            }
        }
    }
    return jumps[n-1];
}

int main()
{
	int res;
	//int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};

	int arr[]= {1, 2, 4, 1, 1, 1, 3, 1, 0, 9};

	res = minJumps2(arr, 0, sizeof(arr)/sizeof(int));

	//res = MinJump(arr, 0, sizeof(arr)/sizeof(int));

	//res = MinJump2(arr,sizeof(arr)/sizeof(int));

	//res = minJumps(arr,sizeof(arr)/sizeof(int));
	printf("result: %d\n", res);
	return 0;
}
