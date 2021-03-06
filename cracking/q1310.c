#include <stdlib.h>

int** my2DAlloc(int row, int col) {
	int** rowptr;
	int i;

	rowptr = (int**)malloc(row*sizeof(int*));

	for (i=0; i<row; ++i) {
		rowptr[i] = (int*)malloc(col*sizeof(int));
	}
	return rowptr;
}

void DeAlloc(int** ptr, int rows) {
	while (rows >=0) {
		free(ptr[rows]);
		--rows;
	}
	free(ptr);
}

int** my2DAlloc2(int row, int col) {
	int** rowptr;
	int* blocks;
	int i;

	rowptr = (int**)malloc(row*sizeof(int*)+col*row*sizeof(int));
	if (rowptr == NULL) return NULL;

	blocks = (int*)(rowptr+row);

	for (i=0; i<row; ++i) {
		rowptr[i] = blocks + i*col;
	}
	return rowptr;
}

void DeAlloc2(int** ptr) {
	free(ptr);
}


int main() {



	return 0;
}
