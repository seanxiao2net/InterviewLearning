#include <stdio.h>
#include <stdlib.h>

int F(int i)
{
	if (i == 1)
		return 1;
	else
	{
		return i*F(i-1);
	}
}

int F_tail(int i, int a)
{

	if (i < 1)
	{
		return a;
	}
	else
	{
		return F_tail (i-1, i*a);
	}
}

int main()
{
	int result;

	//result = F(5);
	result = F_tail(5,1);

	printf("resukt is %d\n",result);

	return 0;
}
