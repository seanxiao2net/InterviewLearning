#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int val;
	struct Node* left;
	struct Node* right;
} Node;

//find common ancestor on a binary tree, not BST
int isNodeIn(Node* root, Node* tar)
{
	int left,right;
	if ((!root)||(!tar)) return 0;

	if (root == tar) return 1;

	left = isNodeIn(root->left, tar);
	right = isNodeIn(root->right, tar);

	return left||right;
}

Node* CommonAncestor(Node* root, Node* tar1, Node* tar2)
{
	int isLeft1, isLeft2;
	if (root == NULL) return NULL;

	if ((root == tar1)||(root == tar2)) return root;

	isLeft1 = isNodeIn(root->left, tar1);
	isLeft2 = isNodeIn(root->left, tar2);

	if (isLeft1 != isLeft2)
	{
		return root;
	}
	else if ((isLeft1)&&(isLeft2))
	{
		return CommonAncestor(root->left, tar1, tar2);
	}
	else
	{
		return CommonAncestor(root->right, tar1, tar2);
	}
}

Node* CommonAncestor2(Node* root, Node* tar1, Node* tar2)
{
	//static Node* rt=NULL;
	Node *left, *right;
	if (root == NULL) return NULL;

	if (root == tar1 || root == tar2)
	{
		return root;
	}

	left = CommonAncestor2(root->left, tar1, tar2);
	if ((left != NULL)&&(left != tar1)&&(left != tar2))	return left;
	right = CommonAncestor2(root->right, tar1, tar2);
	if ((right != NULL)&&(right != tar1)&&(right != tar2))	return right;


	if (left!=NULL && right != NULL)
	{
		return root;
	}
	else if (root == tar1 || root == tar2)
	{
		return root;
	}
	else if (left != NULL)
	{
		return left;
	}
	else if (right != NULL)
	{
		return right;
	}
	else
	{
		return NULL;
	}

}

void maketree(int arr[], int head, int tail, Node** dest)
{
	if (head > tail)
	{
		*dest = NULL;
	 	return;
	}
	int mid = (head+tail)/2;
	(*dest) = malloc(sizeof(Node));
	(*dest)->val = arr[mid];
	maketree(arr, head, mid-1, &((*dest)->left));
	maketree(arr, mid+1, tail, &((*dest)->right));
}

void inorder(Node* root)
{
	if(root == NULL) return;
	inorder(root->left);
	printf("val: %d\n", root->val);
	inorder(root->right);
}

void preorder(Node* root)
{
	if(root == NULL) return;
	printf("val: %d\n", root->val);
	preorder(root->left);
	preorder(root->right);
}


int main()
{
	Node* root;
	Node *test1, *test2, *res;
	int arr[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	maketree(arr, 0, sizeof(arr)/sizeof(int)-1, &root);

	test1 = root->left;
	test2 = root->left->right;

	res = CommonAncestor2(root, test1, test2);

	preorder(root);

	//printf("%p\n", res);

	printf("test1 %d, test2 %d, result %d\n", test1->val, test2->val, res->val);

	return 0;
}
