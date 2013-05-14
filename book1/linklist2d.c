#include <stdio.h>
#include <stdlib.h>

typedef struct iElem
{
	int data;
	struct iElem *next;
}iElem;

typedef struct sList
{
	iElem *head;
	iElem *tail;
}sList;

void initList(sList *list)
{
	list->head = 0;
	list->tail = 0;
}

int InsertFront(sList *list, int val)
{
	iElem *newdata;

	newdata = malloc(sizeof(iElem));
	if (newdata == 0) return 0;
	
	newdata->next = list->head;
	newdata->data = val;

	list->head = newdata;
	if (list->tail == 0)
	{
		list->tail = newdata;
	}

	return 1;
}

int DeleteElem(sList *list, int val)
{
	iElem *current = list->head;
	iElem *deleteme;

	if (!current)
	{
		return 0;
	}

	if (current->data == val)	//indicate the head of LL
	{
		list->head = current->next;
		if (current == list->tail)
		{
			list->tail = 0;
		}
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
			if (deleteme == list->tail)
			{
				list->tail = current;
			}
			free(deleteme);
			return 1;
		}
		current = current->next;
	}
	return 0;
}

int InsertElem(sList *list, int ElemLoc, int val)
{
	iElem *current = list->head;
	iElem *newElem;

	if (current->data == ElemLoc)
	{
		newElem = malloc (sizeof(iElem));
		newElem->next = current;
		newElem->data = val;
		list->head = newElem;
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

int FindM(const sList *list, int Mth, int *ret)
{
	iElem * current = list->head;
	iElem * M;
	int i;

	for (i=0; i<Mth; i++)
	{
		if (current == 0) return 0;	//linklist is not long enough
		current = current->next;
	}

	M = list->head;

	while (current)
	{
		M = M->next;
		current = current->next;
	}

	*ret = M->data;
	return 1;
}

void DeleteList(sList *list)
{
	iElem *current = list->head;
	iElem *delete;

	while (current)
	{
		delete = current;
		current = current->next;
		free(delete);		
	}

	list->head = 0;
	list->tail = 0;

}

void traverse(sList *list)
{
	iElem *current = list->head;

	while (current != 0)
	{
		printf("current value %d tail value %d\n",current->data, list->tail->data);
		current = current->next;
	}
	
}

int main()
{
	sList list;
	int ret;

	initList(&list);

	InsertFront(&list, 9);
	InsertFront(&list, 2);
	InsertFront(&list, 1);
	InsertFront(&list, 3);
	//traverse(&list);
	InsertFront(&list, 2);
	InsertFront(&list, 1);
	InsertFront(&list, 3);
	InsertFront(&list, 2);
	InsertFront(&list, 1);

	if (FindM(&list, 6, &ret))
	printf ("return value %d\n", ret);

	DeleteElem(&list,9);

	if (FindM(&list, 6, &ret))
	printf ("return value %d\n", ret);

	InsertElem(&list,1,8);

	DeleteList(&list);

	traverse(&list);

	//DeleteList(&list);

	return 0;
}
