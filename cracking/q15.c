#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*void writeBuffer(char* str, char val, int *writePos, int maxlength)*/
/*{*/
/*	if (*writePos<maxlength)*/
/*	{*/
/*		*(str+*writePos) = val;*/
/*		(*writePos)++;*/
/*	}*/
/*	else*/
/*		return;*/

/*}*/


int digitNum(int i)
{
	int digit=0;

	while (i>0)
	{
		digit++;
		i/=10;
	}
	return digit;
}

void writeNum(int num, char* str)
{
	int digit;

	digit = digitNum(num);

	while (digit)
	{
		*(str+digit-1) = '0' + num%10;
		num/=10;
		digit--;
	}
}

int CompressionLength(char *str)
{
	int length, i, newlength=0;
	char indicator;
	int count;



	length = strlen(str);

	indicator = *str;
	count =1;
	for (i=1; i<length; i++)
	{
		if (*(str+i) == indicator)
		{
			count++;
		}
		else
		{
			newlength = newlength +1 + digitNum(count);
			count = 1;
			indicator = *(str+i);
		}
	}
	newlength = newlength +1 + digitNum(count);

	return newlength;
}

int Compression(char *str)
{
	int length, newlength, count;
	int i,j;
	char* tmp;
	char indicator;

	if ((str == 0)||(strlen(str)==0))
		return -1;

	length = strlen(str);
	newlength = CompressionLength(str);

	if (newlength>length)
		return -2;

	tmp = malloc(newlength+1);
	for (i=0;i<newlength;i++)
		*(tmp+i)=0;

	*(tmp+newlength) = '\0';

	indicator = *str;
	count =1;
	for (i=0,j=0; i<length; i++)
	{
		if (*(str+i) == indicator)
		{
			count++;
		}
		else
		{
			*(tmp+j) = indicator;
			j++;
			writeNum(count, (tmp+j));
			j = j + digitNum(count);
			count = 1;
			indicator = *(str+i);
		}
	}
	*(tmp+j) = indicator;
	writeNum(count, tmp+j+1);

	strcpy(str, tmp);
	return 1;
}


int main()
{
	//char* original = "aabcccccaaa";
	char* original = "abcdef";
	char* test;
	int res;

	test = malloc(strlen(original)+1);
	strcpy(test, original);

	res = CompressionLength(test);

	printf("result length is %d\n", res);

	Compression(test);

	printf("%s\n",test);
	//printf("%c\n",*(test+0));

	return 0;
}
