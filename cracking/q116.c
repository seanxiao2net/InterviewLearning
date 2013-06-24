#include <stdio.h>

int Find(int m[][4], int val, int *x, int *y) {
	int i,j;
	i = 3; j = 0;

	while ((i>=0)&&(j<4)) {
		if (m[j][i] == val) {
			*x = i; *y = j;
			return 1;
		} else if (m[j][i] > val) {
			--i;
		} else {
			++j;
		}
	}
	return 0;
}

int main() {
	int m[4][4] = {{15,20,40,85}, {20,35,80,95}, {30,55,95,105}, {40,80,100,120}};
	int res, res_x, res_y;	

	res = Find(m, 120, &res_x, &res_y);

	printf("res %d, x %d, y %d\n", res, res_x, res_y);
	return 0;
}
