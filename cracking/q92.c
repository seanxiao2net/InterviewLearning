#include <stdio.h>
#include <stdlib.h>

void FindPath(int x, int y, int dest_x, int dest_y, int *count)
{
	if ( x> dest_x || y > dest_y) return;

	if (x== dest_x && y==dest_y) {
		(*count)++;
		return;
	}
	FindPath(x+1, y, dest_x, dest_y, count);
	FindPath(x, y+1, dest_x, dest_y, count);
}


int main() {
	int result = 0;

	FindPath (0,0,4,5,&result);

	printf("the final result is %d\n", result);

	return 0;
}
