#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

int search(string in[], const string &val, int l, int r) {
	int mid = (l+r)/2;


	if ((val.empty())||(l>r)) return -1;


	if (in[mid].empty()) {
		int left = mid-1, right= mid+1;
		while(1) {
			if ((left<l)&&(right>r)) {
				return -1;
			} else if ((left>=l)&&(!in[left].empty())) {
				mid = left;
				break;
			} else if ((right <= r)&&(!in[right].empty())) {
				mid = right;
				break;
			}
			++l;--r;
		}
	}

	if (in[mid].compare(val) == 0) return mid;
	else if (in[mid].compare(val) < 0) {
		return search(in, val, mid+1, r);
	} else {
		return search(in, val, l, mid-1);
	}

}

int main() {
	string test[10];
	string tmp;
	int result;

	test[0] = "aaa";
	test[1] = "bbb";
	test[3] = "ccc";
	test[5] = "ddd";
	test[8] = "eee";
	test[9] = "fff";

	tmp = test[0];

	result = search(test, tmp, 0, 9);

	cout<<result<<endl;

	return 0;
}
