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

int append(iElem **head, int val, iElem *lastptr)
{
	iElem *curr = *head;
	iElem *newElem;

	if (*head == 0) return 0;

	while (curr->next)
	{
		curr = curr->next;
	}

	newElem = malloc(sizeof(iElem));
	if (!newElem) return 0;

	curr->next = newElem;
	newElem->data = val;
	newElem->next = lastptr;
	return 1;
}

int Find (iElem *head, int val, iElem ** ptrret)
{
	iElem * curr = head;
	while (curr)
	{
		if (curr->data == val)
		{
			*ptrret = curr;
			return 1;
		}
		curr = curr->next;
	}
	return 0;
}

int NullCycle(iElem *head)
{
	iElem *curr1 = head;
	iElem *curr2 = head;

	while (curr2)
	{
		curr1 = curr1->next;

		if (curr2 && curr2->next)
		curr2 = curr2->next->next;
		else return 0;

		if (curr1 == curr2) return 1;
	}
	return 0;
}

int main()
{
	iElem *head =0;
	
	iElem *temp;

	int NullCyc;

	InsertFront(&head, 9);
	InsertFront(&head, 2);
	InsertFront(&head, 1);
	InsertFront(&head, 3);
	InsertFront(&head, 4);
	InsertFront(&head, 1);
	InsertFront(&head, 3);
	InsertFront(&head, 2);
	InsertFront(&head, 1);

	//DeleteElem(&head,9);

	InsertElem(&head,1,8);

	//DeleteList(&head);

	Find(head, 4, &temp);

	//DeleteList(&head);

	append(&head, 21, temp);

	//traverse(head);

	NullCyc = NullCycle(head);

	printf ("the result is %d\n",NullCyc);

	return 0;
}
