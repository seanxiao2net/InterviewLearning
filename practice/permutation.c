#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void doPer(const char* str, int sz, char* output, int used[], int wpos)
{
	int i;
	if (wpos == sz)
	{
		*(output+wpos) = '\0';
		printf("%s\n", output);
		return;
	}

	for(i=0; i<sz; i++)
	{
		if(used[i])	continue;
		else
		{
			used[i] = 1;
			output[wpos] = str[i];
			doPer(str, sz, output, used, wpos+1);
			used[i] = 0;
		}
	}
}

void swap (char* a, char* b)
{
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void doPer2(const char* str, int sz, char* output, int token)
{
	int i;
	if(token == sz)
	{
		printf("%s\n", output);
		return;
	}

	for (i=token; i<sz; i++)
	{
		swap(&output[token], &output[i]);
		doPer2(str, sz, output, token+1);
		swap(&output[token], &output[i]);
	}
}

void Permutation(const char* str, int sz)
{
	int used[sz];
	char* output;
	int i;

	for (i=0; i<sz; i++)
	{
		used[i] = 0;
	}

	output = (char*)malloc(sz+1);

//	doPer(str, sz, output, used, 0);

	strcpy(output, str);
	doPer2(str, sz, output, 0);
}


int main()
{
	char* str = "ABCD";

	Permutation(str, 4);

	return 0;
}
