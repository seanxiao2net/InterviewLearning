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

/*Given a node, find the next largest node in the BST;*/
/*(1) if the node has left child, search that child for maximum node*/
/*(2) if the node has no left child, find the nearest parent which smaller than its child node. use this node as max node.*/

treeElem* FindParent(treeElem *root, int node_val)
{
	treeElem *curr, *prev;

	curr = root;
	prev = 0;

	while ((curr->val != node_val))
	{
		if (node_val > curr->val)
		{
			prev = curr;
			curr = curr->right;
		}
		else
		{
			prev = curr;
			curr = curr->left;
		}

		if (curr == 0)
			return 0;
	}

	return prev;
}

treeElem* FindMax(treeElem *root)
{
	treeElem *curr;

	curr = root;

	while (curr->right != 0)
		curr = curr->right;

	return curr;
}

treeElem* FindNextLarge(treeElem *root, treeElem *node)
{
	treeElem *child, *parent;
	if (node->left != 0)
		return FindMax(node->left);
	else
	{
		parent = node;
		do
		{
		child = parent;
		parent = FindParent(root, child->val);
		//printf("here %d\n", parent->val);
		if (parent == 0)	return 0;
		}while (parent->val > child->val);
	}

	return parent;
}

//question ended here;

//solution 2
treeElem* FindMax2(treeElem *root)
{
	treeElem* curr = root;

	while (curr->right != 0)
		curr = curr->right;

	return curr;
}

treeElem* FindNextLarge2(treeElem* root, treeElem* Node)
{
	treeElem *curr, *next;
	
	if (Node->left != 0)
		return FindMax2(Node->left);
	else
	{
		curr = root;
		next = 0;
		while (root != 0)	
		{
			if (curr->val > Node->val)
				curr = curr-> left;
			else if (curr->val < Node->val)
			{
				next = curr;
				curr = curr->right;
			}
			else	break;
		}
	}

	return next;
}

treeElem* FindNode(treeElem *root, int val)
{
	treeElem * curr;
	curr = root;

	while (curr->val != val)
	{
		if (val > curr->val)
			curr = curr->right;
		else
			curr = curr->left;

		if (curr == 0)
			return 0;
	}

	return curr;
}

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
	treeElem *curr, *prev;

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

	//prev = FindParent(root, 175);

	//printf("father is %d\n", prev->val);

	curr = FindNode(root, 25);

	//prev = FindNextLarge(root, curr);

	prev = FindNextLarge2(root, curr);

	if (prev == 0)
		printf ("already the smallest\n");
	else
		printf("result is %d\n", prev->val);



	return 0;
}
