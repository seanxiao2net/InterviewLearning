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

int DeleteElem(iElem **head, int val)
{
	iElem *current = *head;
	iElem *deleteme;

	if (!(*head))
	{
		return 0;
	}

	if (current->data == val)	//indicate the head of LL
	{
		*head = current->next;
		free(current);
		return 1;
	}

	while (current)
	{
		if (current->next->data == val)
		{
			//item found
			deleteme = current->next;
			current->next = deleteme->next;
			free(deleteme);
			return 1;
		}
		current = current->next;
	}
	return 0;
}

int InsertElem(iElem **head, int ElemLoc, int val)
{
	iElem *current = *head;
	iElem *newElem;

	if (current->data == ElemLoc)
	{
		newElem = malloc (sizeof(iElem));
		newElem->next = current;
		newElem->data = val;
		*head = newElem;
		return 1;
	}

	while (current)
	{
		if (current->next->data == ElemLoc)
		{
			newElem = malloc (sizeof(iElem));
			newElem->next = current->next;
			current->next = newElem;
			newElem->data = val;
			return 1;
		}

		current = current->next;
	}

	return 0;
}

void DeleteList(iElem **head)
{
	iElem *current;
	iElem *delete;

	while (current)
	{
		delete = current;
		current = current->next;
		free(delete);		
	}

	*head = 0;

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

int main()
{
	iElem *head =0;

	InsertFront(&head, 9);
	InsertFront(&head, 2);
	InsertFront(&head, 1);
	InsertFront(&head, 3);
	InsertFront(&head, 2);
	InsertFront(&head, 1);
	InsertFront(&head, 3);
	InsertFront(&head, 2);
	InsertFront(&head, 1);

	//DeleteElem(&head,9);

	InsertElem(&head,1,8);

	DeleteList(&head);

	traverse(head);

	DeleteList(&head);

	return 0;
}
