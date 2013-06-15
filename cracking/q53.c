#include <stdio.h>
#include <stdlib.h>

int next(int num) {
	unsigned int buff;
	int i=0,j=0,k;

	if (num<=0) return -1;

	buff = num;
	//first step, find first 1
	while ((buff & 0x01) == 0) {
		buff>>=1;
		++i;
	}

	//find next 0, count 1s
	while (buff&0x01) {
		buff >>=1;
		++j;
	}

	if (i+j == 31) return -1;

	k = i+j;
	num |= 1<<k;
	num &= ~((1 << k) -1);
	num |= (1 << (j-1)) -1;

	return num;
}

int prev(int num) {
	unsigned int buff;
	int i=0,j=0,k=0;

	if (num<=0) return -1;

	buff = num;

	while ((buff & 0x01))
	{
		buff >>=1;
		++i;
	}

	while ((buff & 0x01) == 0)
	{
		buff >>=1;
		++j;
	}

	k = i+j;	//unset this bit

	num &= ((~0)<<(k+1));
//	num &= (~((1<<(k+1))-1));
//	printf("%d\n", num);
	num |= (((1<<(i+1))-1)<<(j-1));
//	num |= (((1<<(k))-1)&(~((1<<(j-1))-1)));

	return num;
}

int main()
{
	int num, res;

	num = 799;

	res = next(num);

	res = prev(num);

	printf("res is %d\n",res);

	return 0;
}
