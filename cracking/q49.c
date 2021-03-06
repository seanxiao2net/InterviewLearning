#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int val;
	struct Node* left;
	struct Node* right;
} Node;

int height(Node* root)
{
	int left, right;
	if (root == NULL) return 0;

	left = height(root->left);
	right = height(root->right);

	return ((left > right) ? left: right)+1;
}

void print(int arr[], int start, int end)
{
	int i;

	for (i=start; i<=end; ++i)
		printf("%d ", arr[i]);
	printf("\n");

}

void FindSumDo(Node* root, int sum, int arr[], int lvl)
{
	int i, tmp;

	if (root == NULL) return;

	arr[lvl] = root->val;


	tmp = 0;
	for (i=lvl; i>=0; --i)	
	{
		tmp += arr[i];
		if (tmp == sum)
			print(arr, i, lvl);
	}

	//check for the possible solutions

	FindSumDo(root->left, sum, arr, lvl+1);
	FindSumDo(root->right, sum, arr, lvl+1);
}

void FindSum(Node* root, int sum)
{
	int *num;
	num = (int*)malloc(height(root)*sizeof(int));

	FindSumDo(root, sum, num, 0);

	free(num);
	num = NULL;
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
//	Node *test1, *test2, *res;
	int arr[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	maketree(arr, 0, sizeof(arr)/sizeof(int)-1, &root);

/*	test1 = root;*/
/*	test2 = root->left->right;*/

/*	preorder(root);*/

	FindSum(root, 21);


	return 0;
}
