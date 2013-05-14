#include <stdio.h>
#include <stdlib.h>


int countone(int num)
{
	int ret=0;

	while (num != 0)
	{
		ret += num%2;
		num/=2;
	}
	return ret;
}

int main()
{
	int i=49;
	int j;

	j = countone(i);

	printf("number of ones:%d\n", j);

	return 0;
}
