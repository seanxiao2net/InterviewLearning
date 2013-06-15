#include <stdio.h>


void PrintP(int total, int l, int r, char* buf, int token) {
	if (token >= 2*total) {
		*(buf+token) = '\0';
		printf("%s\n", buf);
		return;
	}

	if (l<total) {
		*(buf+token) = '(';
		PrintP(total, l+1, r, buf, token+1);
	}

	if (r<l) {
		*(buf+token) = ')';
		PrintP(total, l, r+1, buf, token+1);
	}

}


int main() {

	char buf[20+1];

	PrintP(3, 0, 0, buf, 0);


	return 0;
}
