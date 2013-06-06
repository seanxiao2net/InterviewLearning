#include <stdio.h>
#include <stdlib.h>


int bits (unsigned char v)
{
	int counter = 0;

	while (v>0)
	{
		if (v%2) counter++;
		v/=2;
	}

	return counter;
}

int bits_speed(unsigned char v)
{
	static int map[256];
	static unsigned char isFirstTime = 1;
	int i;

	if (isFirstTime)		//build a look-up table
	{
		for (i=0; i<256; i++)
			map[i]=bits(i);
		isFirstTime = 0;
	}

	return map[v];

}

int main()
{
	//unsigned char temp = 0b01110010;
	unsigned char temp = 0b00100000;
	int result;

	result = bits(temp);
	printf("result is %d\n", result);

	result = bits_speed(temp);
	printf("result is %d\n", result);

	result = bits_speed(temp+1);
	printf("result is %d\n", result);
	return 0;
}
