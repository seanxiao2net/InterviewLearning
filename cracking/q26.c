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

void makecircle(iElem *head)
{
	iElem *curr=head;
	int i;

	for (i=0;i<4;i++)
		head = head->next;

	while(curr->next)
	{
		curr = curr->next;
	}

	curr->next = head;
}

iElem* circleEntry(iElem *head)
{
	iElem *fast = head;
	iElem *slow = head;
	int count=0;

	while ((fast)&&(fast->next))
	{
		fast = fast->next->next;
		slow = slow->next;
		++count;

		if (fast == slow)	break;
	}

	if (fast == NULL) return NULL;

	slow = head;
	
	while (fast != slow)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}

int main()
{
	iElem *head =0;
	iElem *res = NULL;

	InsertFront(&head, 9);
	InsertFront(&head, 2);
	InsertFront(&head, 1);
	InsertFront(&head, 3);
	InsertFront(&head, 2);
	InsertFront(&head, 1);
	InsertFront(&head, 3);
	InsertFront(&head, 99);
	InsertFront(&head, 1);
	InsertFront(&head, 10);
	InsertFront(&head, 11);
	makecircle(head);

	res = circleEntry(head);

	printf("entry is %d\n", res->data);


	return 0;
}
