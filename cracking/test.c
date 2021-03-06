void DeleteNode(Node* node)
{
	if (node && node->next)
	{
		Node* del;
		node->val = node->next->val;
		del = node->next;
		node->next = del->next;

		free(del);
	}

}

void partition(Node** header, int x)
{
	Node *list1=NULL, *list2=NULL;
	Node *list1_h=NULL, *list2_h=NULL;
	Node *curr;
	if (*header == NULL)	return;

	curr = *header;

	while(*curr)
	{
		if (curr->val < x)
		{
			if (list1 == NULL)	list1 = curr, list1_h=curr;
			else	list1->next = curr, list1 = curr, list1->next = NULL;
		}
		else
		{
			if (list2 == NULL)	list2 = curr, list2_h=curr;
			else	list2->next = curr, list2 = curr, list2->next = NULL;
		}

		curr = curr->next;
	}

	if (list1 == NULL)	*header = list2_h;
	else
	{
		list1->next = list2_h;
		*header = list1_h;
	}
}

Node* sum(Node* num1, Node* num2, int carry)
{
	int val=0;
	Node* curr;

	if (num1 == NULL)&&(num2 = NULL)&&(carry = 0)	return NULL;

	if (num1 != NULL) val +=num1->val;

	if (num2 != NULL) val +=num2->val;

	val +=carry;

	curr = malloc(sizeof(Node));

	curr->val = val%10;

	curr->next = sum((num1==NULL)?NULL:num1->next, (num2==NULL)?NULL:num2->next, (val>=10)?1:0);

	return curr;
}

Node* sum_forward(Node* num1, Node* num2, int carry)
{
	int val = 0;
	Node* curr;

	if ((num1 == NULL)&&(num2 == NULL)) return NULL;




}
