#include <stddef.h>

template <class T>
class PTR {
public:
PTR(T* ptr): p(ptr) { count = new unsigned int; *count = 1;}
PTR(PTR<T> &obj): p(obj.p), count(obj.count) {++(*count);}
~PTR() {remove();}
T getval() {return *p;}
PTR<T>& operator=(PTR<T> &rhs);

private:
void remove();
T* p;
unsigned int *count;
};


template <class T>
void PTR<T>::remove() {
	--(*count);
	if (*count == 0) {
		delete p;
		delete count;
		p = NULL;
		count = NULL;
	}
}

template <class T>
PTR<T>& PTR<T>::operator=(PTR<T> &rhs) {
	if (this == &rhs)	return *this;
	if (count>0) {
		remove();
	}

	p = rhs.p;
	count = rhs.count;
	++(*count);
	return *this;
}


int main() {

	return 0;
}
