#include <stdio.h>
#include <stdlib.h>

int isDeadEnd(int (*m)[10], int x, int y)
{
	int conn = 0;
	if ((m[y][x] == 0) && (!(x==0 && y==0)) && (!(x==9 && y==9)))	//it is path
	{
		if ((x+1<10) && (m[y][x+1]==0)) conn++;
		if ((y+1<10) && (m[y+1][x]==0)) conn++;
		if ((x-1>=0) && (m[y][x-1]==0)) conn++;
		if ((y-1>=0) && (m[y-1][x]==0)) conn++;

		if (conn < 2)	//This node is dead road
		{
			m[y][x] = 1;
			return 1;
		}

	}
	return 0;
}

void MakeMap(int (*m)[10])
{
	int loop;
	int i,j;
	do
	{
		loop = 0;
		for (i=0; i<10; i++)
		{
			for (j=0; j<10; j++)
				loop = loop + isDeadEnd(m, i, j);
		}
	
	}while(loop);
}

int move (int (*m)[10])
{
	char mode = 0;
	int x = 0;
	int y = 0;
	int prev_x = 0;
	int prev_y = 0;
	int fail_cnt = 0;

	while (fail_cnt<100)
	{
		switch (mode)
		{
		case 0:
			printf("X: %d Y: %d\n", x, y);
			mode = 1;
			break;
		case 1:
			if (((x != prev_x) || (y+1 != prev_y)) && (y + 1 < 10) && (m[y+1][x] == 0))
			{
				prev_x = x; prev_y = y++; mode = 2;
				printf("X: %d Y: %d\n", x, y);
			}
			else if (((x+1 != prev_x) || (y != prev_y)) && (x + 1 < 10) && (m[y][x+1] == 0))
			{
				prev_x = x++; prev_y = y; mode = 1;
				printf("X: %d Y: %d\n", x, y);
			}
			else if (((x != prev_x) || (y-1 != prev_y)) && (y - 1 >= 0) && (m[y-1][x] == 0))
			{
				prev_x = x; prev_y = y--;mode = 4;
				printf("X: %d Y: %d\n", x, y);
			}
			else
			{
				printf("Cannot find exit!\n");
				return -1;
			}
			break;
		case 2:
			if (((x-1 != prev_x) || (y != prev_y)) && (x - 1 >= 0) && (m[y][x-1] == 0))
			{
				prev_x = x--; prev_y = y;++mode; mode = 3;
				printf("X: %d Y: %d\n", x, y);
			}
			else if (((x != prev_x) || (y+1 != prev_y)) && (y + 1 < 10) && (m[y+1][x] == 0))
			{
				prev_x = x; prev_y = y++;++mode; mode = 2;
				printf("X: %d Y: %d\n", x, y);
			}
			else if (((x+1 != prev_x) || (y != prev_y)) && (x + 1 < 10) && (m[y][x+1] == 0))
			{
				prev_x = x++; prev_y = y; mode = 1;
				printf("X: %d Y: %d\n", x, y);
			}
			else
			{
				printf("Cannot find exit!\n");
				return -1;
			}
			break;
		case 3:
			if (((x != prev_x) || (y-1 != prev_y)) && (y - 1 >= 0) && (m[y-1][x] == 0))
			{
				prev_x = x; prev_y = y--;mode = 4;
				printf("X: %d Y: %d\n", x, y);
			}
			else if (((x-1 != prev_x) || (y != prev_y)) && (x - 1 >= 0) && (m[y][x-1] == 0))
			{
				prev_x = x--; prev_y = y;++mode; mode = 3;
				printf("X: %d Y: %d\n", x, y);
			}
			else if (((x != prev_x) || (y+1 != prev_y)) && (y + 1 < 10) && (m[y+1][x] == 0))
			{
				prev_x = x; prev_y = y++;++mode; mode = 2;
				printf("X: %d Y: %d\n", x, y);
			}
			else
			{
				printf("Cannot find exit!\n");
				return -1;
			}
			break;
		case 4:
			if (((x+1 != prev_x) || (y != prev_y)) && (x + 1 < 10) && (m[y][x+1] == 0))
			{
				prev_x = x++; prev_y = y; mode = 1;
				printf("X: %d Y: %d\n", x, y);
			}
			else if (((x != prev_x) || (y-1 != prev_y)) && (y - 1 >= 0) && (m[y-1][x] == 0))
			{
				prev_x = x; prev_y = y--;mode = 4;
				printf("X: %d Y: %d\n", x, y);
			}
			else if (((x-1 != prev_x) || (y != prev_y)) && (x - 1 >= 0) && (m[y][x-1] == 0))
			{
				prev_x = x--; prev_y = y;++mode; mode = 3;
				printf("X: %d Y: %d\n", x, y);
			}
			else
			{
				printf("Cannot find exit!\n");
				return -1;
			}
			break;
		}

		if ((x == 9)&&(y == 9))	
		{
			printf("Succeeded!\n");
			return 1;
		}
		++fail_cnt;
	}
	printf("Cannot find exit!\n");
	return 0;
}

void solveMaze(int (*m)[10])
{
	int i,j;
	MakeMap(m);	//fill the dead ends

	printf("new map without dead ends:\n");
	for (i=0; i<10; i++)	//Print the new map
	{
		for (j=0; j<10; j++)
		{
			printf ("%d ", m[i][j]);
		}
			printf ("\n");

	}
	printf("\nmoving path:\n");
	move(m);	//print the moving path
}


int main()
{
	int m[10][10] =
	{   {0,    1,    1,    0,    1,    1,    1,    1,    0,    1},
	    {0,    1,    0,    0,    0,    0,    1,    1,    1,    1},
	    {0,    1,    0,    0,    1,    0,    1,    1,    1,    1},
	    {0,    0,    0,    1,    1,    0,    1,    1,    1,    1},
	    {0,    1,    1,    1,    0,    0,    1,    0,    0,    1},
	    {1,    1,    1,    1,    0,    1,    1,    0,    0,    1},
	    {1,    1,    0,    1,    0,    0,    0,    0,    0,    1},
	    {1,    1,    0,    0,    1,    1,    1,    1,    0,    1},
	    {0,    1,    1,    0,    1,    1,    1,    1,    0,    1},
	    {0,    1,    1,    1,    1,    1,    1,    1,    0,    0}
	};

	solveMaze(m);

	return 0;
}