#include <stdio.h>
#include <stdlib.h>

typedef struct treeElem
{
	struct treeElem * left;
	struct treeElem * right;
	int val;
}treeElem;

void BSTinsert(treeElem ** root, int inputList[], int begin, int end)
{
	int mid;

	if (begin > end)
		return;

	mid = (begin + end)/2;

	*root = malloc (sizeof(treeElem));

	(*root)->val = inputList[mid];
	(*root)->right = 0;
	(*root)->left = 0;

	//printf("begin %d mid %d end %d\n", begin, mid, end);

	BSTinsert(&((*root)->left), inputList, begin, mid-1);
	BSTinsert(&((*root)->right), inputList, mid+1, end);
}




void makelist (int **list, int list_len)
{
	int i;
	*list = malloc(sizeof(int)*list_len);

	for (i = 0; i<list_len; i++)
		*(*list+i) = i+1;
}

int BSTInorder(treeElem *root)
{
	if (root == 0) return 0;
	BSTInorder(root->left);
	printf("%d ", root->val);
	BSTInorder(root->right);

	return 1;
}


int MaxDepth(treeElem* root)
{
	int left, right, max;
	if (root == 0)
		return 0;
	else
	{
		left = MaxDepth(root->left);
		right = MaxDepth(root->right);
		max = (left > right) ? left:right;
		return max +1;
	}
}

int isBalanced(treeElem* root)
{
	if (root == 0)
		return 1;
	else
	{
		return isBalanced(root->left)&&isBalanced(root->right)&&(abs(MaxDepth(root->left)-MaxDepth(root->right)) <= 1);
	}

}

int ElemCounts(treeElem* root)
{
	//static int count = 0;
	int left, right;

	if (root == 0)
		return 0;
	
	left = ElemCounts(root->left);
	right = ElemCounts(root->right);

	return left+right+1;
}

void _tree2arr(treeElem *root, int *arr)
{
	static int i =0;
	if (root == 0)	return;
	_tree2arr(root->left, arr);
	*(arr+i) = root->val;
	i++;
	_tree2arr(root->right, arr);
}


void tree2arr(treeElem* root, int **arr, int arr_size)
{
	*arr = malloc(sizeof(int) *arr_size);
	_tree2arr(root, *arr);
}


int main()
{
	int * testlist=0;
	int *testlist2=0;
	int testlist_len=100;
	treeElem* root;
	int test, i;

	makelist(&testlist, testlist_len);	// a list for test is built

	BSTinsert(&root, testlist, 0, testlist_len-1);

	BSTInorder(root);
	printf("\n");

	//printf("value = %d\n",testlist[0]);

	test = MaxDepth(root);

	printf("it has %d lvls\n", test);

	test = isBalanced(root);

	printf("balance condition is %d\n", test);

	test = ElemCounts(root);

	printf("this tree contains %d of elements\n", test);

	tree2arr(root, &testlist2, test);

	for (i=0; i<100; i++)
		printf("%d ",testlist2[i]);

	printf("\n");

	free(testlist);
	return 0;
}
