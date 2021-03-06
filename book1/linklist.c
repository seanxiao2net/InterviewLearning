#include <stdio.h>
#include <stdlib.h>

typedef struct iElem
{
	struct iElem *next;
	int value;
}iElem;

int insertFront(iElem **head, int value)
{
	iElem *newElement;

	newElement = malloc(sizeof(iElem));
	if (newElement == 0) return 0;

	newElement->value = value;
	newElement->next = *head;
	
	*head = newElement;
	return 1;
}

int Traverse(iElem* head)
{
	iElem* current = head;
	while (current != 0)
	{
		printf("result %d\n",current->value);
		current = current->next;
	}
	return 0;
}

int main()
{
	iElem *head = 0;
	//iElem *tail = 0;

	insertFront (&head, 1);
	insertFront (&head, 2);
	insertFront (&head, 3);
	insertFront (&head, 8);

	Traverse (head);
return 0;
}
	
