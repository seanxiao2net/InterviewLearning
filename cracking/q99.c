#include <stdio.h>
#include <stdlib.h>

int Check(int row, int col, int result[]) {
	int i;

	for (i=0; i<row; ++i) {
		if( abs(row-i) == abs(col - result[i])) return 0;
	}

	return 1;
}

void placeQ(int buf[], int result[], int dim, int row) {
	int i;
	if (row == dim) {
		printf("solution\n");
		for (i=0; i<dim; ++i)
			printf("Queen %d on (%d, %d)\n", i, i, result[i]);
		return;
	}

	for (i=0; i<dim; ++i) {
		if ((buf[i]==0)&&(Check(row, i, result))) {
			result[row] = i;
			buf[i] = 1;
			placeQ(buf, result, dim, row+1);
			buf[i] = 0;
		}
	}
}



int main() {
	int col[8];
	int result[8];
	int i;
	for (i=0; i<8; ++i)
		col[i] = 0;

	placeQ(col, result, 8, 0);

	return 0;
}
