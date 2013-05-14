#include <stdio.h>
#include <stdlib.h>

typedef struct _list_item {
    int value;
    struct list_item *next;
} list_item;

void del_item(list_item *root, int val)
{
	list_item *lp = root;
	list_item *tp = root;

	//Determine if the first element need to be deleted
	if ((lp -> value) == val)
	{
		if ((lp -> next) == 0)	//It is the only element in the link list
		{
			printf("you cannot delete the last element without destroy func");
		}
		else
		{
			tp = lp -> next;
			lp -> value = tp -> value;
			lp -> next = tp -> next;
		}
		return;
	}

	//Find the position of the element to be removed
	while (lp)	
	{
		if ((lp -> value) == val)
		{
			break;
		}
		lp=lp -> next;
	}

	//Delete the element if it is found
	while (tp && (lp != 0))	
	{
		if ((tp -> next) == lp)			//Find the pos-1
		{
			tp -> next = lp -> next;	//Delete the element
			
			break;
		}
		tp=tp -> next;
	}
}

void print_list(list_item *root)
{
	list_item *lp = root;
	while(lp) {
		printf("%d\n", lp -> value);
		lp=lp -> next;
	}
}

int main()
{
	list_item list[5];

	list[0].value=1; list[0].next=list+1;
	list[1].value=2; list[1].next=list+2;
	list[2].value=3; list[2].next=list+3;
	list[3].value=4; list[3].next=list+4;
	list[4].value=5; list[4].next=list+5;
	list[5].value=6; list[5].next=0;

	printf("test to delete list item whose value is 3\n");
	del_item(list, 3);
	
	print_list(list);

	return 0;

}
