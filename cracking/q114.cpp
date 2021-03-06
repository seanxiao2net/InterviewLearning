#include <string>
using std::string;

void swap (string &s1, string &s2) {
	string tmp;
	tmp = s1;
	s1 = s2;
	s2 = tmp;
}

void qs(string in[], int begin, int end) {
	int l = begin, r = end;
	int mid = (l+r)/2;
	string pvt = in[mid];

	while (l<r) {
		while (in[l].compare(pvt) < 0) ++l;
		while (in[r].compare(pvt) > 0) --r;

		if (l<r) {
			swap(in[l], in[r]);
			++l;--r;
		}
	}

	if (r>begin)
		qs(in, begin, r);
	if (l<end)
		qs(in, l, end);

}

void Merge(string in1[], string in2[], string output[], int sz1, int sz2) {
	int i=0,j=0,k=0;

	while ((i<=sz1)&&(j<=sz2)) {
		if (in1[i].compare(in2[j]) < 0) {
			output[k] = in1[i];
			++k;++i;
		} else {
			output[k] = in2[j];
			++k;++j;
		}
	}

	while (i<=sz1) {
		output[k] = in1[i];
		++k;++i;
	}

	while (j<=sz2) {
		output[k] = in2[j];
		++k;++j;
	}
}


int main() {



	return 0;
}
