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

int height(treeElem *root)
{
	int left, right;
	if (root == NULL) return 0;

	left = height(root->left);
	right = height(root->right);

	return ((left>right)? left:right)+1;
}

int isBalance(treeElem *root)
{
	int diff;

	if (root == NULL) return 1;

	diff = height(root->left) - height(root->right);

	if ((abs(diff)<=1)&&(isBalance(root->left))&&isBalance(root->right))
		return 1;
	else return 0;
}

int CheckHeight(treeElem *root)
{
	int left, right, diff;

	if (root == NULL) return 0;

	left = CheckHeight(root->left);
	if (left == -1)	return -1;

	right = CheckHeight(root->right);
	if (right == -1) return -1;

	diff = left - right;

	if (abs(diff)>1) return -1;
	else return ((left>right)?left:right)+1;
}

int main()
{
	treeElem *root=0;
	//treeElem *curr, *prev;

	insert(&root, 100);
	insert(&root, 50);
	insert(&root, 150);
	insert(&root, 25);
	insert(&root, 75);
	insert(&root, 125);
	insert(&root, 175);
	insert(&root, 110);
	//insert(&root, 105);

	printf("tree height is %d\n", height(root));

	printf("tree balance is %d\n", CheckHeight(root));


	return 0;
}
