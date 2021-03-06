#include <vector>
#include <cstdlib>

template <class K, class V>
class cell {
public:
cell(V value): val(value), next(NULL){}
void SetNext(cell *n) {next = n;}
void DeleteNext(cell *n) {
cell* tmp;
if (next == NULL) return;
tmp = next;
next = next->next;
delete (tmp);
}
V GetVal() {return val;}
cell* Next(){return next;}
bool isEnd() {return (next == NULL);}
K GetKey() {return key;}
bool equivalent(K k) {return k==key;}
bool equivalent(cell<K,V> c) {return equivalent(c.GetKey); }

private:
K key;
V val;
cell* next;
};

template <class K, class V>
class LinkedList {
public:
LinkedList(): root(NULL), sz(0){}
~LinkedList() {
	cell<K,V>* curr = root;
	cell<K,V>* del;
	while (curr)
	{
		del = curr;
		curr = curr->next;
		delete(del);
	}
}
void push_front(K k, V v);
void Delete(K k, V v);
cell<K,V>* Search(K k);

private:
cell<K,V>* root;
int sz;
};

template <class K, class V>
class Hash {
public:
int hashKey(K key);
void put(K key, V val) {
	int h = hashKey(key);
	items[h].push_front(key, val);
}
V get(K key) {
	int h = hashKey(key);
	return items[h].Search(key)->GetVal();
}

private:
LinkedList<K,V> items[97];
};

int main() {


	return 0;
}
