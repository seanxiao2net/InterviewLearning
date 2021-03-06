#include <stdlib.h>
#include <stdio.h>

typedef struct BST
{
	int val;
	struct BST* left;
	struct BST* right;
}BST;

BST *root =0;

void insertsub(BST* root, int val)
{
	BST* newItem;
	if (val < root->val)	//insert left
	{
		if (root->left == 0)
		{
			newItem = malloc(sizeof(BST));
			root->left = newItem;
			newItem->val = val;
			newItem->left = 0;
			newItem->right = 0;
		}
		else
		{
			insertsub(root->left, val);
		}
	}
	else
	{
		if (root->right == 0)
		{
			newItem = malloc(sizeof(BST));
			root->right = newItem;
			newItem->val = val;
			newItem->left = 0;
			newItem->right = 0;
		}
		else
		{
			insertsub(root->right, val);
		}
	}

}

void insert (int val)
{
	if(root==0)
	{
		root=malloc(sizeof(BST));
		root->val = val;
		root->left =0;
		root->right=0;
	}
	else
	{
		insertsub(root, val);
	}

}

void preorder(BST* root)
{
	if (root == 0) return;
	printf("%d ",root->val);
	preorder(root->left);
	preorder(root->right);
}


int findMin(BST* root, int val1, int val2)
{
	while (1)
	{
		if ((root->val > val1)&&(root->val > val2))
		{
			root = root->left;
		}
		else if ((root->val < val1)&&(root->val < val2))
		{
			root = root->right;
		}
		else
			return root->val;
	}
}


int main()
{
	int res;

	insert(20);
	insert(8);
	insert(4);
	insert(12);
	insert(10);
	insert(14);
	insert(22);

	preorder(root);
	printf("\n");

	res = findMin(root, 4, 14);

	printf("%d \n",res);

	return 0;
}
