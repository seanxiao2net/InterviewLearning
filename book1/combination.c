#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void combineproc(const char *str, int strsize, char *result, int lvl, int token)
{
	int i;

	i = token;

	for (;i<strsize;i++)
	{
		*(result+lvl) = *(str+i);
		*(result+lvl+1) = '\0';
		printf("%s\n",result);

		if (i<strsize)
		{
			combineproc(str, strsize, result, lvl+1, i+1);
		}
	}
}

void combine(const char *str, int strsize)
{
	char *res;
	
	res = malloc(strsize+1);

	combineproc(str, strsize, res, 0, 0);

	free(res);
}



void doCombine(const char * str, int strsize, char * result, int lvl, int token)
{
	int i;

	i = token;

	for (;i<strsize;i++)
	{
		*(result + lvl) = *(str+i);
		*(result + lvl+1) = '\0';
		printf("%s\n",result);

		if (i<strsize)
		{
			doCombine(str, strsize, result, lvl+1, i+1);
		}
		//else return;

	}

}

void cominations(const char *str, int strsize)
{
	char * result;

	result = malloc(strsize+1);

	doCombine(str, strsize, result, 0, 0);
	
	free(result);
}

int main()
{
	const char * str = "wxyz";
	
	//cominations(str, strlen(str));
	combine(str, strlen(str));

	return 0;
}
