#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char uniqueC(const char * str, int strsize)	//This one need additional data structure
{
	//we suppose it is ascii
	unsigned char ucTab[256];
	int i;

	for (i =0; i<256; i++)
	{
		ucTab[i] = 0;
	}

	for (i=0; i<strsize; i++)
	{
		ucTab[*(str+i)]++;

		if (ucTab[*(str+i)] > 1)
		{
			return *(str+i);
		}
	}

	return 0;
}


int main()
{
	const char* str= "idontsaymuchfnti";

	printf("the result is %c \n", uniqueC(str, strlen(str)));

	return 0;
}
