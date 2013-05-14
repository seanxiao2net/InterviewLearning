#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node *next;
	struct Node *prev;
	struct Node *child;
	int val;
}Node;

void appendList(Node *child, Node **tail)
{
	Node *curr = child;
	child->prev = *tail;
	(*tail)->next = child;
	
	while (curr->next)
	{
		curr = curr->next;
	}
	*tail = curr;
}

void flattenList(Node *head, Node **tail)	//we need to mod tail ptr to the next sublist
{
	Node *curr = head;
	while (curr)
	{
		if (curr->child)
		appendList(curr->child, tail);

	curr = curr->next;
	}
}

void appendList_notail(Node *head, Node *last)
{
	Node *curr = head;

	while (curr->next)
	{
		curr = curr->next;
	}

	curr->next = last->next;
	last->next = curr;
}

void flattenList_notail(Node *head)
{
	Node *curr = head;
	while (curr)
	{
		if (curr->child)
		appendList_notail(curr->child, curr);

		curr = curr->next;
	}
}


int main()
{

	return 0;
}
