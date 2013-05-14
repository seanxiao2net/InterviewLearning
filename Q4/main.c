#include <stdio.h>
#include <stdlib.h>

typedef struct Coor
{
        int x;
        int y;
} Coordinate;

int m[10][10] ={   0,    1,    1,    0,    1,    1,    1,    1,    0,    1,
   0,    1,    0,    0,    0,    0,    1,    1,    1,    1,
    0,    1,    0,    0,    1,    0,    1,    1,    1,    1,
    0,    0,    0,    1,    1,    0,    1,    1,    1,    1,
    0,    1,    1,    1,    0,    0,    1,    0,    0,    1,
    1,    1,    1,    1,    0,    1,    1,    0,    0,    1,
    1,    1,    0,    1,    0,    0,    0,    0,    0,    1,
    1,    1,    0,    0,    1,    1,    1,    1,    0,    1,
    0,    1,    1,    0,    1,    1,    1,    1,    0,    1,
    0,    1,    1,    1,    1,    1,    1,    1,    0,    0
};

Coordinate last, now;

int move ( int x, int y, int pre_x, int pre_y )
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

		if (((((x+1)!=pre_x)||((y)!=pre_y)))&&((x+1)<10)&&(m[x+1][y]==0))
		{
			return_val = move (x+1,y,x,y);
			if (return_val == 0)
			{
				return 0;
			}
		}
		if (((((x)!=pre_x)||((y+1)!=pre_y)))&&((y+1)<10)&&(m[x][y+1]==0))
		{
			return_val = move (x,y+1,x,y);
			if (return_val == 0)
			{
				return 0;
			}
		}
		if (((((x-1)!=pre_x)||((y)!=pre_y)))&&(x > 0)&&(m[x-1][y]==0))
		{
			return_val = move (x-1,y,x,y);
			if (return_val == 0)
			{
				return 0;
			}
		}
		if (((((x)!=pre_x)||((y-1)!=pre_y)))&&(y > 0)&&(m[x][y-1]==0))
		{
			return_val = move (x,y-1,x,y);
			if (return_val == 0)
			{
				return 0;
			}
		}

	}
	return -1;
}

int main()
{
	move(0,0,0,0);

	getchar();

	return 0;

}