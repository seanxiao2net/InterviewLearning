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


int move ( int m[10][10], int x, int y, int pre_x, int pre_y )
{
	int return_val;

	printf("X:%d Y:%d\n",x,y);
	if ((x == 9)&&(y == 9))
	{
		printf("succeded\n");
		return 0;
	}
	else
	{

		if ((((x+1)!=pre_x||y!=pre_y))&&(x+1)<10 && m[y][x+1]==0)
		{
			return_val = move (m,x+1,y,x,y);
			if (return_val == 0)	return 0;
		}
		if (((x!=pre_x ||(y+1)!=pre_y))&& (y+1)<10 && m[y+1][x]==0)
		{
			return_val = move (m,x,y+1,x,y);
			if (return_val == 0)	return 0;
		}
		if ((((x-1)!=pre_x||y!=pre_y))&& x > 0 && m[y][x-1]==0)
		{
			return_val = move (m,x-1,y,x,y);
			if (return_val == 0)	return 0;
		}
		if ((( x!=pre_x ||(y-1)!=pre_y))&& y > 0 && m[y-1][x]==0 )
		{
			return_val = move (m,x,y-1,x,y);
			if (return_val == 0)	return 0;
		}

	}
	return -1;
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
	move(m,0,0,0,0);	//Print the moving path
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
