#include <stdio.h>
#include <stdlib.h>

void Merge (int arrA[], int arrB[], int sz_a, int sz_b) {
	int i,j,k;
	i = sz_a-1; j = sz_b-1; k = sz_a+sz_b-1;
	while ((i>=0)&&(j>=0)) {
		if (arrA[i]>arrB[j]) {
			arrA[k] = arrA[i];
			--i;
		} else {
			arrA[k] = arrB[j];
			--j;
		}
		--k;
	}

	while (j>=0) {
		arrA[k] = arrB[j];
		--j;
		--k;
	}
}

int main() {
	int arrA[30] = {1,5,7,9,12,13,16,18,19,21,22,26};
	int arrB[10]= {2,3,5,6,8,9,15,17,21};
	int sz_A = 12;
	int sz_B = 9;
	int i;

	Merge(arrA, arrB, sz_A, sz_B);

	for (i=0; i<sz_A+sz_B; ++i)
		printf("%d\n", arrA[i]);

	return 0;
}
