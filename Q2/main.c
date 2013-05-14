#include <stdio.h>
#include <stdlib.h>

typedef struct _tree_item {
    int value;
    struct tree_item *left;
    struct tree_item *right;
} tree_item;


int traverse(tree_item* root)
{
	printf("%d ",root->value);
	if ( root->left != NULL)
	{
		traverse (root->left);
	}
	if (root ->right != NULL)
	{
		traverse (root->right);
	}
}

int main()
{
	tree_item tree[5];

	tree[0].value=0;
	tree[0].left= &tree[1];
	tree[0].right= &tree[4];
	tree[1].value=1;
	tree[1].left= &tree[2];
	tree[1].right= &tree[3];
	tree[2].value=2;
	tree[2].left= NULL;
	tree[2].right= NULL;
	tree[3].value=3;
	tree[3].left= NULL;
	tree[3].right= NULL;
	tree[4].value=4;
	tree[4].left= &tree[5];
	tree[4].right= NULL;
	tree[5].value=5;
	tree[5].left= NULL;
	tree[5].right= NULL;


	traverse(&tree);

	getchar();
	return 0;
}
