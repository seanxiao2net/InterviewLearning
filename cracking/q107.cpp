#include <string>
#include <map>

using std::string;
using std::map;

class Node {
public:
Node(const string &q, const string &res, Node* n) :query(q), result(res), next(n){}
void SetNext(Node* n) {next = n;}
void SetResult(const string &res) {result = res;}
string& GetQuery() {return query;}
string& GetResult() {return result;}
Node* GetNext() {return next;}

private:
string query;
string result;
Node* next;
};


class Cache {
public:
Cache() : sz(0) {}
void insertResult(const string &query, const string &result);
string& getResult(const string &query);
void RemoveResult(Node* n);
void MoveToFront(string query);
void MoveToFront(Node* n);

private:
Node *Head, *Tail;
map<string, Node*> HashTab;
int sz;
};


void Cache::insertResult(const string &query, const string &result) {
	map<string, Node*>::iterator it;
	it = HashTab.find(query);
	if (it != HashTab.end()) {
		it->second->SetResult(result);
		MoveToFront(it->second);
	} else {
		Node* newnode = new Node(query, result, Head);
		Head = newnode;
		HashTab[query] = newnode;
	}
}

string& Cache::getResult(const string &query) {
	map<string, Node*>::iterator it;
	it = HashTab.find(query);
	if (it != HashTab.end()) {
		return it->second->GetResult();
	}
	else {
		//do search here
		//return it->second->GetResult();
	}
}

int main() {

	return 0;
}
