#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
	if (n > 1)
		return n*factorial(n-1);
	else
		return 1;
}

int main()
{
	int result;
	result = factorial(5);

	printf("the final result is: %d\n",result);
	return 0;
}
