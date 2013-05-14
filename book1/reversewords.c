#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse (char * str, int head, int end)
{
	int i;
	char tmp;
	for (i = 0; i < (end - head)/2; i++)
	{
		tmp = str[head + i];
		str[head + i] = str[end -i];
		str[end -i] = tmp;
	}

}

void ReverseStr(char * str)
{
	int i,j;
	reverse(str,0,strlen(str)-1);

	for (i=0,j=0;i<strlen(str);i++)
	{
		if (str[i] == ' ')
		{
			reverse(str, j, i-1);
			j = i+1;
		}

	}
	reverse(str, j, i-1);
}


void ReverseStrB(char * str)
{
	char * buffer;
	int wordread, wordend, writepos=0;
	int token = strlen(str) -1;

	buffer = malloc(sizeof(char)*strlen(str)+1);

	wordend = token;

	while (token >=0)
	{
		if (str[token] == ' ')
		{
			buffer[writepos] = str[token];
			writepos++;
			token--;
		}
		else
		{
			wordend = token;

			while ((str[token] != ' ')&&(token>=0))
			{
				token--;
			}

			wordread = token +1;
			while (wordread <= wordend)
			{
				buffer[writepos] = str[wordread];
				wordread++;
				writepos++;
			}

		}
	}
	buffer[writepos] = '\0';
	strcpy(str,buffer);
}

int main()
{
	char str[] ="one two three";

	 
	//ReverseStr(str);
	ReverseStrB(str);
	printf("%s\n",str);

	return 0;
}
