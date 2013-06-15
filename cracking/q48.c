#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int val;
	struct Node* left;
	struct Node* right;
} Node;

int TreeMatch(Node* t1, Node* t2)
{
	if ((t1==NULL)&&(t2==NULL)) return 1;
	if (t1==NULL || t2 ==NULL) return 0;

	return ((t1 == t2)&&TreeMatch(t1->left, t2->left)&&TreeMatch(t1->right, t2->right));
}


int SubTree(Node* t1, Node* t2)
{
	if (t1 == NULL) return 0;

	if (t1 == t2) return TreeMatch(t1, t2);
	return (SubTree(t1->left, t2) || SubTree(t1->right, t2));
}


int ContainTrees(Node* T1, Node* T2)
{
	if (T2 == NULL) return 1;

	return SubTree(T1, T2);
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

	test1 = root;
	test2 = root->left->right;

	preorder(root);

	printf("Contain result %d\n",ContainTrees(test1, test2));

	return 0;
}
