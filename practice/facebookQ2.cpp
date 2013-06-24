#include <iostream>

using std::cout;
using std::endl;

int a[] = {1,4,0,6,7};
int sz = 5;

void reverse (int *l, int *r) {
	while (l<r) {
		int tmp;
		tmp = *l;
		*l = *r;
		*r = tmp;
		++l; --r;
	}
}

void flip(int num) {
	if (num>=sz) return;
	reverse(&a[num], &a[sz-1]);
}

void Sort(int arr[], int sz) {
	int token = 0;
	while (token < sz - 1) {
		int index = token;
		int min = arr[index];
		for (int i=token; i< sz; ++i) {
			if (arr[i]<min) {
				index = i;
				min = arr[i];
			}
		}
		cout<<index<<" "<<token<<endl;
		flip(index);
		flip(token);
		++token;
	}

}

int main() {
	Sort(a, sz);

	for (int i=0; i<sz; ++i)
		cout<<a[i]<<endl;

	return 0;
}
