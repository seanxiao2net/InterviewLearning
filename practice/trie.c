#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxsz 28

typedef struct trie_node
{
	char data[maxsz];
	struct trie_node* branch[maxsz];
}Node;

int alpha_order(char c)
{
	if ((c >= 'a')&&(c <= 'z')) return c-'a';
	if ((c >= 'A')&&(c <= 'Z')) return c-'A';
	return 27;
}


void insert(const char* newdata, Node** root)
{
	int pos=0;
	Node* location=NULL;
	char nextchar;
	int nextpos;


	if (*root == NULL)	*root = (Node*)malloc(sizeof(Node));
	location = *root;

	while ((location != NULL)&&((nextchar = newdata[pos])!='\0'))
	{
		nextpos = alpha_order(nextchar);
		if (location->branch[nextpos] == NULL)
			location->branch[nextpos] = (Node*)malloc(sizeof(Node));

		location = location->branch[nextpos];
		++pos;
	}

	if (*(location->data) == '\0')
	{
		strcpy(location->data, newdata);
		//printf("insert is %s\n", location->data);
	}
}

int search(const char* key, Node* root, char result[])
{
	int pos = 0;
	Node* location = root;
	char nextchar;

	while((location != NULL)&&((nextchar = key[pos])!='\0'))
	{
		location = location->branch[alpha_order(nextchar)];
		++pos;
	}

	if ((location != NULL)&&(*(location->data) !='\0'))
	{
		strcpy(result, location->data);
		//printf("find is %s\n", location->data);
		return 1;		
	}
	
	return 0;
}

void delete_do(const char* key, Node** root, int pos)
{
	char nextchar;
	int i;

	if ((*root != NULL)&&((nextchar = key[pos])!='\0'))
	{
		delete_do(key, &((*root)->branch[alpha_order(nextchar)]), pos+1);
	}
	else if (( *root != NULL)&&(*((*root)->data) != '\0'))
	{
		(*root)->data[0] = '\0';
	}

	for (i=0; i< maxsz; i++)
	{
		if ((*root)->branch[i] != NULL) return;
	}

	printf("delete node\n");
	free(*root);
	*root = NULL;
}

int main()
{
	Node* root = NULL;
	char result[30];
	int rt;

	insert("Han", &root);

	delete_do("ha", &root, 0);

	rt = search("Han", root, result);

	

	printf("result is %d and %s\n", rt, result);

	return 0;
}
