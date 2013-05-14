#include <stdio.h>
#include <stdlib.h>

typedef struct treeElem
{
	struct treeElem * left;
	struct treeElem * right;
	int val;
}treeElem;

typedef struct BSTstack
{
	treeElem * val;
	struct BSTstack * next;
}BSTstack;



void push(BSTstack **head, treeElem *val)
{
	BSTstack *newItem;
	newItem = malloc(sizeof(BSTstack));
	newItem->val = val;
	newItem->next = *head;
	*head = newItem;
}

int pop1(BSTstack **head, treeElem **ret)
{
	BSTstack *del;
	if (*head)
	*ret = (*head)->val;
	//*ret = 0;
	else
	*ret = 0;


	del = (*head);
	(*head) = (*head)->next;
	free(del);
	return 0;
}

treeElem* pop(BSTstack **head)
{
	BSTstack *del;
	treeElem *ret;

	if ((*head) ==0) return 0;

	ret = (*head)->val;
	del = (*head);
	(*head) = (*head)->next;
	free(del);

	return ret;
}


int BSTPreorder(treeElem *root)
{
	if (root == 0) return 0;
	printf("%d ", root->val);
	BSTPreorder(root->left);
	BSTPreorder(root->right);
	return 1;
}

int BSTInorder(treeElem *root)
{
	if (root == 0) return 0;
	BSTInorder(root->left);
	printf("%d ", root->val);
	BSTInorder(root->right);

	return 1;
}

int BSTPostorder(treeElem *root)
{
	if (root == 0) return 0;
	BSTPostorder(root->left);
	BSTPostorder(root->right);
	printf("%d ", root->val);

	return 1;
}

int BSTPreorder2(treeElem *root)
{
	BSTstack *stack =0;
	treeElem *tmp =root;

	push(&stack, root);
	while (1)
	{
		tmp = pop(&stack);
		if (tmp == 0) return 0;
		printf("%d ", tmp->val);
		if (tmp->right) push(&stack, tmp->right);
		if (tmp->left) push(&stack, tmp->left);
	}
	return 0;
}

int insertSub(treeElem *node, int val)
{
	if(val < node->val)
	{
		if (node->left == 0)
		{
			node->left = malloc(sizeof(treeElem));
			node->left->val = val;
		}
		else
		{
			insertSub(node->left, val);
		}
	}
	else
	{
		if (node->right == 0)
		{
			node->right = malloc(sizeof(treeElem));
			node->right->val = val;
		}
		else
		{
			insertSub(node->right, val);
		}
	}
	return 1;
}

int insert(treeElem **root, int val)
{
	if (*root == 0)
	{
		*root = malloc(sizeof(treeElem));
		(*root)->val = 100;
	}
	else
	{
		insertSub(*root, val);
	}
	return 0;
}

int main()
{
	treeElem *root=0;
	
	insert(&root, 100);
	insert(&root, 50);
	insert(&root, 150);
	insert(&root, 25);
	insert(&root, 75);
	insert(&root, 125);
	insert(&root, 175);
	insert(&root, 110);

	BSTPreorder(root);
	printf("\n");
	BSTInorder(root);
	printf("\n");
	BSTPostorder(root);
	printf("\n");
	BSTPreorder2(root);
	printf("\n");


	return 0;
}
