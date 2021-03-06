#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* add(const char*a, const char *b)
{
	int i,iA,iB,ix=0;
	char *result;
	char *pA, *pB;

	i = (strlen(a)>strlen(b)) ? strlen(a):strlen(b);

	result = malloc(i+2);
	*(result+i+1) = '\0';

	pA = a + strlen(a) -1;
	pB = b + strlen(b) -1;

	for (; i>=0; i--)
	{
		if (pA >= a)
		{
			iA = *(pA)-'0';
		}
		else iA=0;

		if (pB >= b) iB = *(pB)-'0';
		else iB = 0;

		*(result+i) = (iA + iB +ix) %10 + '0';
		ix = (iA + iB +ix) /10;

		pA--;
		pB--;

	} 

	if (*(result) == '0')
	{
		for (i=0; i<strlen(result)-1; i++)
			*(result+i) = *(result+i+1);
	}

	return result;
}


char* multi(const char*a, const char *b)
{
	char *pA, *pB;
	int i,j, tmp, res;
	char *result;
	int iB,iA;

	i = strlen(a) + strlen(b) +1;
	
	result = malloc(i);

	for (tmp=0; tmp<i-1;tmp++)
		*(result+tmp)='0';

	i--;
	*(result+i) = '\0';

	pB = b + strlen(b) -1;
	tmp = 0;
	

	for (;pB>= b; pB--)
	{
		i--;
		iB = *(pB)-'0';
		pA = a + strlen(a) -1;
		j = i;

		for (;pA>=a-1; pA--)
		{
			if (pA >= a)	iA = *(pA) -'0';
			else iA = 0;
			res = *(result+j) - '0';
			*(result+j) = (iA*iB+tmp+res)%10 +'0';
			tmp = (iA*iB+tmp+res)/10;

			j--;
		}
		printf("haha result is %s\n", result);
	}


	return result;
}

int main()
{
	const char* A = "65535";
	const char* B = "575423";

	char* res;

	//res = add(A,B);

	res = multi(A,B);

	printf("result is %s\n", res);

	free(res);

	return 0;
}
