#include <stdio.h>
#include <stdlib.h>

int firstMissingPos(int arr[], int size)
{
	int i,token,tmp;

	token=size-1;
	i=0;

	for (i=0;i<token;)
	{
		if (arr[i]<=0)
		{
			tmp = arr[i];
			arr[i]=arr[token];
			arr[token]=tmp;
			token--;
			i--;
		}
		i++;
	}

	for (i=0;i<token;i++)
	{
		if ((arr[i]!= i+1)&&(arr[i]<i+1)&&(arr[i]<token))
		{
			tmp = arr[i];
			arr[i] = arr[tmp-1];
			arr[tmp-1] = tmp;
			//i--;
		}

	}

	for (i=0;i<size;i++)
	{
		if (arr[i] != i+1)
			return i+1;

	}

	return 0;
}

int main()
{
	int arr[] = {1,2,-2,3,-4,5,-8,6,7,12,8,0};

	//int arr[] = {3,4,-1,1};
	int res;

	res = firstMissingPos(arr,sizeof(arr)/sizeof(int));

	printf("resulr is %d\n",res);

	return 0;
}
