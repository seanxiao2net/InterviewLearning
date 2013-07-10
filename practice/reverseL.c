#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node* next;
}Node;

Node* reverse(Node* root) {
	Node* prev = NULL;
	Node* token = NULL;
	while (root) {
		token = head->next;
		head->next = prev;
		prev = head;
		head = token;
	}
	return prev;
}

Node* reverseList(Node* root) {
	Node *new_list=NULL, *curr=root, *token = NULL;
	while (curr) {
		token = curr;
		curr = curr->next;
		if (new_list==NULL) {
			new_list = token;
			new_list->next = NULL;
		} else {
			token->next = new_list;
			new_list = token;
		}
	}
	return new_list;
}

int main() {
	Node *head=NULL;
	
	return 0;
}
