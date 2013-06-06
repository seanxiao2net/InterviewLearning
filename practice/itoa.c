#include <stdio.h>
#include <stdlib.h>

void itoa(int num, char str[])
{
	int length=0;
	int tmp = num;
	if (num < 0)
	{
		*str++ = '-';
		num = -num;
	}

	do
	{
		tmp /=10;
		++length;
	} while (tmp != 0);

	for (tmp=length-1; tmp>=0; --tmp)
	{
		*(str+tmp) = num%10+'0';
		num/=10;
	}

	*(str+length) = '\0';
}


int main()
{
	char result[20];
	int input = 21342;
	itoa(input, result);

	printf("the output is %s\n", result);
	return 0;
}
