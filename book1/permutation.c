#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void doPer(char * str, int strsize, unsigned char * perTab, char * perRes, int lvl)
{
	int i;
	if (lvl == strsize)
	{
		printf("%s\n",perRes);
		return;
	}

	for (i = 0; i < strsize; i++)
	{
		if (perTab[i] == 0)
		{
			perRes[lvl]=str[i];
			perTab[i] = 1;
			doPer(str, strsize, perTab, perRes, lvl+1);
			perTab[i] = 0;
		}

	}
}

void permutation(char * str, int strsize)
{
	int i;
	unsigned char perTab[strsize];
	char perRes[strsize+1];

	for (i=0; i<strsize; i++)
	{
		perTab[i] = 0;
	}
	perRes[strsize+1] = '\0';

	doPer(str, strsize, perTab, perRes, 0);
}

void swap(char * val1, char * val2)
{
	char tmp;
	tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
}

void perC(char * str, int strsize, int token)
{
	int i;
	if (token == strsize)
	{
		printf("%s\n", str);
		return;
	}
	else
	{
		for (i = token; i<strsize; i++)
		{
			swap(str+token,str+i);
			perC(str, strsize,token+1);
			swap(str+token,str+i);
		}
	}
}

void Per2(char* str, int strsize, int token)
{
	int i;

	if (token == strsize)
		printf("%s\n", str);

	for (i=token; i<strsize; i++)
	{
		swap(str+token, str+i);
		Per2(str, strsize, token+1);
		swap(str+token, str+i);
	}

}

void doPer3(char *str, int strsize, int perTab[],char *res, int lvl)
{
	int i;

	if (lvl == strsize)
	{
		printf("%s\n", res);
		return;
	}
	for (i=0; i<strsize; i++)
	{
		if (perTab[i] == 0)
		{
			*(res+lvl) = *(str+i);
			perTab[i] = 1;
			doPer3(str, strsize, perTab, res, lvl+1);
			perTab[i] = 0;
		}

	}
}

void per3(char *str, int strsize)
{
	int i;
	int perTab[strsize];
	char *res;

	res = malloc(strsize+1);

	*(res+strsize) = '\0';

	for (i=0;i<strsize;i++)
		perTab[i]=0;

	doPer3(str, strsize, perTab, res, 0);
}



int main()
{
	char str[] ="abcd";
	
	//permutation(str, strlen(str));

	//perC(str, strlen(str), 0);

	//Per2(str, strlen(str),0);

	per3(str,strlen(str));

	//printf("%d\n",strlen(str));

	return 0;
}
