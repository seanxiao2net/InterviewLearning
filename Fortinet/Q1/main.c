#include <stdio.h>
#include <stdlib.h>


/* Question 1: Delete an item in a linked list */

typedef struct _list_item {
    int value;
    struct _list_item* next;
} list_item;

void del_item(list_item (*root)[], int val)
{
	list_item *lp = *root;
	//determine if the first item need to be deleted
	if (lp->value == val)
	{
		if (lp->next == 0)	//It is the only element in array, it cannot be deleted
		{
			printf("Cannot delete the last element\n");
			return;
		}
		else			//copy the second item to first, delete second
		{
			lp-> value = lp->next->value;
			lp-> next = lp ->next->next;
			return;
		}
	}

	while (lp->next)
	{
		if (lp->next->value == val)
		{
			lp->next = lp->next->next;
			return;
		}

		lp = lp->next;
	}

}

void print_list(list_item *root)
{
	list_item* lp = root;
	while(lp) {
		printf("%d\n", lp->value);
		lp = lp->next;
	}
}

int main()
{
	list_item list[6];

	list[0].value=1; list[0].next=list+1;
	list[1].value=2; list[1].next=list+2;
	list[2].value=3; list[2].next=list+3;
	list[3].value=4; list[3].next=list+4;
	list[4].value=5; list[4].next=list+5;
	list[5].value=6; list[5].next=0;

	printf("test to delete list item whose value is 3\n");
	del_item(&list, 3);	//assume the question want me to pass &list
	print_list(list);

	return 0;
}

