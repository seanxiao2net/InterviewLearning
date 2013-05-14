#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void replace(char * str)
{
	int i, length, newlength;
	int spaces=0;

	length = strlen(str);

	for (i=0; i<length; i++)
	{
		if (*(str+i) == ' ')
			spaces++;
	}

	newlength = length + 2*spaces;
	*(str+newlength) = '\0';

	for (i=length-1; i>=0; i--)
	{
		if (*(str+i) == ' ')
		{
			*(str+newlength-1) = '0';
			*(str+newlength-2) = '2';
			*(str+newlength-3) = '%';
			newlength -=3;
		}
		else
		{
			*(str+newlength-1) = *(str+i);
			newlength--;
		}
	}
	

	//printf("number: %d\n",space_num);
}


int main()
{
	char * original="hello everyboday this is the testing string";
	char * test;

	test = malloc(2*strlen(original));

	strcpy(test,original);

	replace(test);

	printf("result is %s\n",test);


	return 0;
}
