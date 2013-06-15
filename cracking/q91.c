#include <stdio.h>

/*int Ways (int n) {*/
/*	int m;*/
/*	if (n>3) {*/
/*		m = 3;*/
/*		n = n - 3;*/
/*		return m*Ways(n);*/
/*	}*/
/*	else if (n==0) return 0;*/
/*	else  return n;*/
/*}*/

int Ways(int n) {
	int m;
	if (n == 0) return 1;
	else if (n < 0) return 0;
	else {
		return Ways(n-1) + Ways(n-2) + Ways(n-3);
	}
}


int main() {
	int result;

	result = Ways(11);

	printf("result is %d\n", result);

	return 0;
}
