#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

//Define the structure for linklist elements
typedef struct LISTElmt_
{
	void	*data;
	struct LISTElmt_ *next;
} ListElmt;

//define the structure for link list
typedef struct List_
{
	int size;
	int (*match)(const void *key1, const void *key2);
	void (*destroy)(void *data);

	ListElmt	*head;
	ListElmt	*tail;
} List;


//Public Interfaces
void list_init(List *list, void (*destroy)(void *data));





#endif
