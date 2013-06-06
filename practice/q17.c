#include <stdio.h>

void FillUp(int m[5][5], int dim)
{
	int x[dim];
	int y[dim];
	int i,j;

	for (i=0;i<dim;++i)	x[i]=1,y[i]=1;

	for (i=0;i<dim;++i)
		for (j=0; j<dim; ++j)
		{
			if (m[i][j] == 0)
			{
				x[j] = 0;
				y[i] = 0;
			}
		}

	for (j=0;j<dim;++j)
	{
		for (i=0;i<dim;++i)
		{
			if((y[j]==0)||(x[i]==0))
				m[j][i] = 0;
		}
	}
}

void print(int m[5][5])
{
	int i,j;

	for (j=0;j<5;++j)
	{
		for (i=0;i<5;++i)
		{
			printf("%d	", m[j][i]);
		}
		printf("\n");
	}
}

int main()
{
	int m[5][5];
	int i,j, k=1;

	for (j=0; j<5; j++)
		for (i=0; i<5; i++)
		{
			m[j][i] = k++;
		}

	m[3][3] = 0;
	m[2][1] = 0;

	print(m);

	FillUp(m,5);

	print(m);

	return 0;
}
