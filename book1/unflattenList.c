#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node *next;
	struct Node *prev;
	struct Node *child;
	int val;
}Node;

void separateNodes(Node *start)
{
	Node * curr = start;
	while (curr)
	{
		if (curr->child)
		{
			curr->child->prev->next = 0;
			curr->child->prev = 0;
			separateNodes(curr->child);
		}

		curr = curr->next;
	}

}



void unflattenList(Node *start, Node **tail)
{
	Node *curr = start;

	separateNodes(start);

	while (curr->next)
	{
		curr = curr->next;
	}

	*tail = curr;	//update tail ptr
}

int main()
{

	return 0;
}
