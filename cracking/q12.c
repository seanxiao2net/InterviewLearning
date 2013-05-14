#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void reverse(char* str)   reverse a null-terminated string

void reverse(char* str)
{
	char *head, *end;
	char tmp;

	if ((str == 0)||(strlen(str) ==1))
		return;

	head = str;
	end = head + strlen(str) -1;

	printf("end %c",*end);

	while (head < end)
	{
		tmp = *head;
		*head = *end;
		*end = tmp;

		++head;
		--end;	
	}
}

int main()
{
	const char *test = "what the heck";
	char *str;

	str = malloc(strlen(test)+1);
	*(str+strlen(test)) = '\0';

	strcpy(str,test);

	reverse(str);

	printf("result is: %s\n",str);

	return 0;
}
