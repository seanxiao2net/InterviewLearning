#include <stdio.h>
#include <stdlib.h>

int bits (unsigned char v)
{
	int num = 0;
	do
	{
		num += v%2;
		v = v/2;
	} while (v>0);
	return num;
}

int main()
{
	unsigned char temp = 0b01111010;
	int result;

	result = bits(temp);
	printf("result is %d\n", result);
	return 0;
}
