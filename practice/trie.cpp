#include <iostream>
#include <string>

using namespace std;

const int maxsz = 28;

typedef struct trie_node
{
	string data;
	trie_node *branch[maxsz];
	trie_node();
}Node;

trie_node::trie_node()
{
	for (int i=0; i<maxsz; i++)
		branch[i] = NULL;
}


class Trie
{
public:
	Trie() { root = NULL;}
	void Trie_insert(const char* newdata);
	int Trie_search(const char* key, string& x);
	void Trie_delete(const char* key);
	
private:
	int alpha_order(char c);
	void Trie_delete_do(const char* key, Node*& location, int pos);
	Node *root;
};

int Trie::alpha_order(char c)
{
	if ((c >= 'a')&&(c <= 'z')) return c-'a';
	if ((c >= 'A')&&(c <= 'Z')) return c-'A';
	return 27;
}


void Trie::Trie_insert(const char* newdata)
{
	if (root == NULL)	root = new Node;
	int position = 0;
	Node* location = root;
	char nextchar;

	while (location != NULL && (nextchar = newdata[position])!='\0')
	{
		int nextposition = alpha_order(nextchar);
		if (location->branch[nextposition] == NULL) location->branch[nextposition] = new Node;
		location = location->branch[nextposition];
		++position;
	}

	if (location->data.empty() == true)
	{
		location->data = newdata;
		//cout<<"inserting "<<location->data<<endl;
	}
}

int Trie::Trie_search(const char* key, string& x)
{
	int position = 0;
	Node* location = root;
	char nextchar;

	while ((location != NULL)&&((nextchar = key[position])!='\0'))
	{
		location = location->branch[alpha_order(nextchar)];
		++position;
	}

	if (location != NULL && location->data.empty() == false)
	{
		x = location->data;
		return 1;
	}

	return 0;

}

void Trie::Trie_delete(const char* key)
{
	Trie_delete_do(key, root, 0);
}

void Trie::Trie_delete_do(const char* key, Node*& location, int pos)
{
	char nextchar;
	if ((location != NULL)&&((nextchar = key[pos])!='\0'))
	{
		Trie_delete_do(key, location->branch[alpha_order(nextchar)], pos+1);
	}
	else if (location != NULL && location->data.empty() == false)
	{
		location->data.clear();
	}

	for (int i=0; i<maxsz; i++)
	{
		if (location->branch[i] != NULL)	return;
	}

	//delete this node
	cout<<"delete node"<<endl;
	delete location;
	location = NULL;
}

int main()
{
	Trie test1;
	string rtval;
	int rt;

	test1.Trie_insert("Han");
	test1.Trie_insert("Tidi");
	test1.Trie_insert("Haa");
	test1.Trie_delete("Han");
	test1.Trie_delete("Haa");
	test1.Trie_delete("Tidi");
	rt = test1.Trie_search("Han", rtval);

	cout<<rt<<" "<<rtval<<endl;
	return 0;
}
