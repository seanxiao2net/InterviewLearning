#include <stdio.h>
#include <stdlib.h>

typedef struct _tree_item {
    int value;
    struct _tree_item *left;
    struct _tree_item *right;
} tree_item;

int traverse(tree_item* root)	//pre-order traversal
{
	printf("%d ", root->value);
	if (root->left != 0)
		traverse(root->left);
	if (root->right != 0)
		traverse(root->right);

	return 0;
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
	tree[2].left= 0;
	tree[2].right= 0;
	tree[3].value=3;
	tree[3].left= 0;
	tree[3].right= 0;
	tree[4].value=4;
	tree[4].left= &tree[5];
	tree[4].right= 0;
	tree[5].value=5;
	tree[5].left= 0;
	tree[5].right= 0;


	traverse(&tree[0]);

	return 0;
}
