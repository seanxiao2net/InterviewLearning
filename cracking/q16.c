#include <stdio.h>
#include <stdlib.h>



void rotate (int *matrix, int n)
{
	int i,j;
	int tmp,offset;
	int first, last;

	for (i=0; i<n/2; i++)
	{
		first = i;
		last = n-i-1;
		for (j=first; j<last; j++)
		{
			offset = last - j;
			tmp = matrix[first][i];
			matrix[first][j] = matrix[first][last-offset];
			matrix[first][last-offset] = matrix[last][last-offset];
			matrix[last][last-offset] = matrix[j][last];
			matrix[j][last] = tmp;
		}
	}
}


