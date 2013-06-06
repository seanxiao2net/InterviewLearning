#include <stdio.h>
#include <stdlib.h>

unsigned char average(const char * filename)
{
	double averaged = 0;
	int counter = 0;
	int Buffer;
	FILE *file;
	file = fopen(filename, "r");
	
	if (file == NULL)
	{
		return -1;
	}

	while((Buffer = fgetc(file)) != EOF )
	{
		if (Buffer == '\n' || Buffer == '\r') continue;	//Assume we do not need to count \n and \r
		averaged = averaged + ((double)Buffer-averaged)/((double)counter + 1.0);
		counter++;
	}

	return (unsigned char)averaged;
}

int main()
{
	unsigned char result;
	char data[20]="a.txt";
	result = average(data);
	printf ("averaged value %d\n", (int)result);

	return 0;
}
