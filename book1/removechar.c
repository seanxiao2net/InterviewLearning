#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ifremove(char input, char * removestr)
{
	int i;
	for (i=0; i<strlen(removestr); i++)
	{
		if (input == removestr[i])
			return 1;
	}
	return 0;
}

void removestr(char * str, char * removestr)
{
	int i;
	char * ptr = str;

	for (i=0; i<strlen(str); i++)
	{
		if (ifremove(str[i], (char*)removestr) == 0)
		{
			*ptr = str[i];
			ptr++;
		}
	}
	*ptr = '\0';
}

void removestr2(char * str, char * removestr)
{
	int i;
	char removeset[256];
	char *ptr = str;

	for (i=0; i<256; i++)
	{
		removeset[i] =0;
	}

	for (i=0; i<strlen(removestr); i++)
	{
		removeset[(int)removestr[i]] ++;
	}

	for (i=0; i<strlen(str); i++)
	{
		if (removeset[(int)str[i]] == 0)
		{
			*ptr = str[i];
			ptr++;
		}
	}
	*ptr = '\0';
}



int main()
{
	char str[] = "Battle of the Vowels: Hawaii vs. Gronzny";
	char remove[] = "aeiou";
	printf("%s\n",str);

	//removestr(str, remove);
	removestr2(str, remove);
	printf("%s\n",str);
	return 0;
}
