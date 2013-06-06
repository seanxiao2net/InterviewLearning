#include <stdio.h>
#include <stdlib.h>


typedef struct iElem
{
	int data;
	struct iElem *next;
}iElem;

int InsertFront(iElem **head, int val)
{
	iElem *newdata;

	newdata = malloc(sizeof(iElem));
	if (newdata == 0) return 0;

	newdata->next = *head;
	newdata->data = val;

	*head = newdata;
	return 1;
}

void traverse(iElem *head)
{
	iElem *current = head;

	while (current != 0)
	{
		printf("current value %d\n",current->data);
		current = current->next;
	}
}

int isPal(iElem *head, int length, iElem **next)
{
	int ret;
	int num1,num2;
	iElem *returnval=NULL;


	if (length == 0)
	{
		*next = head;
		return 1;
	}
	if (length == 1)
	{
		*next = head->next;
		return 1;
	}

	num1 =head->data;

	ret = isPal(head->next, length-2, &returnval);

	num2 =returnval->data;
	if (next != NULL)
	{
		*next = returnval->next;
	}
/*	printf("%p\n",returnval);*/
/*	printf("%d\n",returnval->data);*/

	if ((num1 == num2)&&(ret == 1))	return 1;
	else return 0;
}

int main()
{
	iElem *head=NULL;
	int result;
	iElem *useless=head;
	
	InsertFront(&head, 0);
	InsertFront(&head, 1);
	InsertFront(&head, 2);
	InsertFront(&head, 3);
	InsertFront(&head, 4);
	InsertFront(&head, 5);
	InsertFront(&head, 5);
	InsertFront(&head, 4);
	InsertFront(&head, 3);
	InsertFront(&head, 2);
	InsertFront(&head, 1);
	InsertFront(&head, 0);

	result = isPal(head, 12,NULL);

	printf("result is %d\n", result);

	traverse(head);

	return 0;
}
