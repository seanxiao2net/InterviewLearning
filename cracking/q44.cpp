#include <iostream>
#include <list>

using namespace std;

typedef struct Node
{
	int val;
	struct Node* left;
	struct Node* right;
} Node;

int height(Node* root)
{
	int left,right;
	if (root==NULL) return 0;

	left = height(root->left);
	right = height(root->right);

	return ((left >right)? left:right)+1;
}

void maketree(int arr[], int head, int tail, Node** dest)
{
	if (head > tail)
	{
		*dest = NULL;
	 	return;
	}
	int mid = (head+tail)/2;
	(*dest) = new Node;
	(*dest)->val = arr[mid];
	maketree(arr, head, mid-1, &((*dest)->left));
	maketree(arr, mid+1, tail, &((*dest)->right));
}

void inorder(Node* root)
{
	if(root == NULL) return;
	inorder(root->left);
	cout<<root->val<<endl;
	inorder(root->right);
}

void preorder(Node* root)
{
	if(root == NULL) return;
	cout<<root->val<<endl;
	preorder(root->left);
	preorder(root->right);
}

void makeQ_do(Node* root, list<int> q[], int lvl)
{
	if (root == NULL) return;
	q[lvl].push_back(root->val);
	makeQ_do(root->left, q, lvl+1);
	makeQ_do(root->right, q, lvl+1);
}

void makeQueues(Node* tree)
{
	int hei = height(tree);
	list<int> q[hei];
	makeQ_do(tree, q, 0);

	list<int>::iterator it;
	for (int i=0; i<hei; i++)
	{
		for(it = q[i].begin(); it!=q[i].end();++it)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
}


int main()
{
	Node* root;
	int arr[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	maketree(arr, 0, sizeof(arr)/sizeof(int)-1, &root);

	preorder(root);

	makeQueues(root);

	return 0;
}
