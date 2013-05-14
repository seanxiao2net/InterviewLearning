#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i2a(char * str)
{
	int res = 0;
	int i = 0;
	unsigned char neg = 0;

	if (str[0] == '-')
	{
		neg = 1;
		i = 1;
	}

	while (i<strlen(str))
	{
		res = res*10 + (str[i] - '0');
		i++;
	}

	if (neg == 1)
		res = res*(-1);
	return res;
}

int a2i(int input, char * output)
{
	char res[15];
	unsigned char neg = 0;
	int tmp;
	int i = 0, j=0;

	if (input < 0)
	{
		neg = 1;
		input *= -1;
	}

	do
	{
		tmp = input % 10;
		input /= 10;
		res[i] = '0'+tmp;
		i++;
	}while (input >= 1);

	if (neg == 1)
	{
		res[i] = '-';
		i++;
	}

	i--;
	while (i>=0)
	{
		output[j] = res[i];
		i--;
		j++;
	}
		output[j] = '\0';

	return 0;
}

int main()
{
char str[] ="-138";
char output[15];
int res;

res = i2a(str);
printf("result is %d\n",res);

res = 0;

a2i(res, output);

printf("result is %s\n",output);

return 0;
}
