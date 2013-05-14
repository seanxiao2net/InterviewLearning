#include <stdio.h>
#include <stdlib.h>


int factorial(int num)
{
	if (num >1)
		return num*factorial(num-1);
	else
		return 1;
}

int dofac(int num, int* array, int lvl)
{
	if (num >1)
	{
		array[lvl] = num * dofac(num-1, array, lvl+1);
		return array[lvl];
	}
	else
	{
		array[lvl] = 1;
		return 1;
	}
}

int* facArray(int num)
{
	int *ret = 0;

	ret = malloc(num == 0? 1:num);

	dofac(num, ret, 0);

	return ret;
}

int main()
{
	int res;
	int * result;
	int i;

	res = factorial(5);

	printf("result: %d\n",res);

	result = facArray(5);

	for (i = 0; i< 5; i++)
	{
		printf("result: %d\n",result[i]);
	}

	return 0;
}
