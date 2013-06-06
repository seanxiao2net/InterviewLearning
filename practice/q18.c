#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* isSubstr(const char* str, const char* tar)
{
	const char *p1, *p2;
	if (!*tar) return str;

	while (*str)
	{
		p1 = str, p2 = tar;
		while ((*p1 == *p2)&&(*p1)&&(*p2))
		{
			++p1;
			++p2;
		}

		if (!*p2)	return str;
		else	++str;
	}

	return NULL;
}

int CheckPalindrome(const char* str1, const char* str2)
{
	char* buff;

	buff = (char*)malloc(strlen(str1)*2+1);

	strcpy(buff, str1);
	strcpy(buff+strlen(str1), str1);

	return (int)isSubstr(buff, str2);

}

int main()
{
	char* test = "this is a string sample code";
	char* target = "sample";

	char* pal1 = "waterbottle";
	char* pal2 = "bottlewater";

/*	if (isSubstr(test,target))*/
/*		printf("found\n");*/

	if (CheckPalindrome(pal1, pal2))
		printf("pal!\n");



	return 0;
}
