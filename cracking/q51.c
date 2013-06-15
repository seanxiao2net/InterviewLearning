#include <stdio.h>
#include <stdlib.h>

unsigned int bits(unsigned int N, unsigned int M, unsigned int i, unsigned int j)
{
	int mask = 0;
	int ret;
	
	mask = ~mask;	//all ones
	mask <<=j;
	mask|= ((1<<i)-1);
	N&=mask;
	M<<=i;
	
	ret = N|M;

	return ret;
}

int main()
{

	unsigned int N = 0b10000000000;
	unsigned int M = 0b10011;
	unsigned int res;

	res = bits(N,M,2,6);

	printf("res is %d\n",res);

	return 0;
}
