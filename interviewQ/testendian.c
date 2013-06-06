#include <stdlib.h>
#include <stdio.h>

int endian2()
{
	union
	{
		int integer;
		char character;
	} name;

	name.integer = 1;
	return name.character;
}

int main()
{
	int test = 1;
	char * endian = (char*)&test;

	printf("result is %d\n", *endian);
	printf("result2 is %d\n", endian2());

	return 0;
}
