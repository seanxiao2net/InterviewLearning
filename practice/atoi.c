#include <stdio.h>
#include <stdlib.h>

int ato(const char* str)
{
	int neg = 1, num=0;

	if (*str++ == '-')
	{
		neg = -1;
	}

	while (*str != '\0')
	{
		num = num*10 + *str - '0';
		++str;
	}

	return num*neg;
}

int main()
{
	char* str = "-23123";
	int result;

	result = atoi(str);

	printf("result is %d\n", result);

	return 0;
}
