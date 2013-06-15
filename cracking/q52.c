#include <stdio.h>
#include <stdlib.h>

void print(double in) {
	char buf[33];
	int i = 0;

	if ((in<0)||(in>1.0))	{
		printf("Error\n");
		return;
	}

	while (in>0) {
		if (i>31) {
			printf("Error\n");
			return;
		}
		in *=2;

		if (in>=1) {
			in-=1;
			buf[i]='1';
		}
		else {
			buf[i]='0';
		}
		++i;
	}

	buf[i]='\0';
	printf("%s\n",buf);
}

int main()
{
	double test;

	test = 0.7;

	print(test);

return 0;
}
