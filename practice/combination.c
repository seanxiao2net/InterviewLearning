#include <stdio.h>
#include <stdlib.h>

void do_combine(const char* str, int length, char* output, int token, int wpos)
{
	int i;

	if (token == length)	return;

	for (i=token; i<length; i++)
	{
		*(output+wpos) = *(str+i);
		*(output+wpos+1) = '\0';
		printf("%s\n",output);
		do_combine(str, length, output, i+1, wpos+1);
	}

}

void Combination(const char* str, int length)
{
	char* output;
	output = (char*)malloc(length+1);

	do_combine(str, length, output, 0, 0);

}


int main()
{
	char* str = "ABCD";

	Combination(str, 4);

	return 0;
}
