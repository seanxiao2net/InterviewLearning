#include <map>
#include <iostream>

using std::map;
using std::cout;
using std::endl;


typedef struct Node {
	struct Node* ptr1;
	struct Node* ptr2;
} Node;

Node* CopyRecursive(Node* root, map<Node*, Node*> &visited) {
	if (root == NULL)	return NULL;
	map<Node*, Node*>::iterator it = visited.find(root);
	if (it != visited.end()) {
		return it->second;
	}

	Node* node = new Node;
	visited[root] = node;
	node->ptr1 = CopyRecursive(root->ptr1, visited);
	node->ptr2 = CopyRecursive(root->ptr2, visited);

	return node;
}

Node* CopyStruct(Node* root) {
	map<Node*, Node*> visited;
	return CopyRecursive(root, visited);

}

int main() {

return 0;
}
