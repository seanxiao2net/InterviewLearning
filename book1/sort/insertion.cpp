#include <cstdlib>
#include <iostream>
#include <vector>

using std::vector;

void InsertionSort(vector<int> input)
{
	vector<int> tmp = input;
	input.empty();

	for (vector<int>::iterator i=tmp.begin(); i<tmp.size(); i++)
	{
		int val = tmp[i];

		for (vector<int>::iterator j=tmp.begin(); j<i; j++)
		{
			if(input.at(j) > val)
			{
				input.insert(j, val);
				break;
			}

		}

	}

}

int main()
{
	vector<int> test;
	test.push_back(123);
	test.push_back(43);
	test.push_back(645);
	test.push_back(1);
	test.push_back(12);

	return 0;
}




//class Node
//{
//public:
//	Node(int val =0, Node * next=0): _value(val), _next(next){}
//	int val() {return _value;}
//	Node* next() {return _next;}
//	void setnext(Node * next) {_next = next;}
//	void setval(int val) {_value = val;}

//private:
//	int _value;
//	Node *_next;
//};

//class List
//{
//public:
//	List() :_head(NULL), _tail(NULL){}
//	//~List();
//	void Append(int val);
//	void Insert(int val, int pos = 0);
//	void Traverse();
//private:
//	Node *_head,*_tail;
//};

//void List::Append(int val)
//{
//	if (_head == NULL)
//	{
//		_head = new Node;
//		if (_head == NULL) return;

//		_tail = _head;
//		_head->setnext(0);
//		_head->setval(val);
//	}
//	else
//	{
//		Node *tmp = new Node;
//		if (tmp == NULL) return;
//		_tail->setnext(tmp);
//		tmp->setnext(0);
//		tmp->setval(val);
//		_tail = tmp;
//	}
//}

//void List::Traverse()
//{
//	using std::cout;
//	using std::endl;
//	Node *curr;

//	if (_head == NULL)
//		return;

//	curr =_head;
//	//cout<<curr->next()->val()<<' ';

//	while (curr)
//	{
//		cout<<curr->val()<<' ';
//		curr = curr->next();
//	}
//	cout<< endl;
//}

//void List::Insert(int val, int pos)
//{
//	Node* curr;
//	if (_head == 0) return;

//	if (pos == 0)	//insert at head
//	{
//		curr = new Node;
//		if (curr == 0) return;

//		curr->setnext(_head);
//		curr->setval(val);
//		_head = curr;
//	}
//	else
//	{
//		curr = _head;
//		while (pos > 1)
//		{
//			pos--;
//			if (curr==NULL) return;
//			curr = curr->next();
//		}

//		Node* newNode = new Node(val, curr->next());
//		if (newNode == 0) return;
//		curr->setnext(newNode);
//	}

//}


//int main()
//{
//	List mylist;
//	mylist.Append(32);
//	mylist.Append(364);
//	mylist.Append(27);
//	mylist.Append(18);
//	mylist.Insert(15,3);

//	mylist.Traverse();
//}
