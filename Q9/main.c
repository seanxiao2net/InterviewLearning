#include <stdio.h>
#include <stdlib.h>

unsigned char average(const char * filename)
{
	double averaged = 0;
	double counter = 0;
	int Buffer;
	FILE *file;
	file = fopen(filename, "r");
	
	if (file == NULL)
	{
		return -1;
	}
	
	do
	{
		Buffer = fgetc (file);
		averaged = averaged + ((double)Buffer-averaged)/(counter + 1);
		counter++;
	} while (Buffer != EOF);

	return (unsigned char)averaged;
}

int main()
{
	unsigned char result;
	char data[20]="a.txt";
	result = average(data);
	printf ("averaged value %d\n", (int)result);
}
