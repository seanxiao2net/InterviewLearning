#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee
{
	char* firstname;
	char* lastname;
} empl;

int strcompare(empl* first, empl* second)
{
	int tmp;

	tmp = strcmp(first->lastname, second->lastname);

	if (tmp!=0)
		return tmp;
	else
		return strcmp(first->firstname, second->firstname);
}

//if sort is stable, you may sort on different categories to form the final result

int main()
{
	empl han,peter;
	int x;

	han.firstname = "Han";
	han.lastname = "Xiao";
	peter.firstname = "Peter";
	peter.lastname = "Xiao";
	//strcmp(han.lastname, peter.lastname);

	x = strcompare(&han,&peter);

	if (x<=0)
		printf("result is %s %s\n",han.firstname, han.lastname);
	else
		printf("result is %s %s\n",peter.firstname, peter.lastname);

	printf("result is %d\n",x);

	return 0;
}
