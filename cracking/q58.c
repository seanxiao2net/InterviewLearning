#include <stdio.h>
#include <stdlib.h>

//array as byte
//width of w pixels, can be divided by 8
//draw line from (x1,y) to (x2,y)
//0<x1<x2<w

/*x1%8 = offset in char*/
/*x1/8 = char offset*/
/*y*8*w = offset for the start of line*/
/*x1%8 = offset in char 2*/
/*x2/8 = char offset 2*/

void draw(unsigned char screen[], int width, int x1, int x2, int y)
{
	int line_offset;
	int start_offset;
	int end_offset;
	int i;
	unsigned char mask_s,mask_e;

	if ((width%8) || (x1<0) || (x2<x1)|| (x2>width)) return;

	line_offset = (width*y)/8;
	start_offset = x1/8+line_offset;
	if (x1%8) ++start_offset;
	end_offset = x2/8+line_offset;
	if (x2%8) --end_offset;

	mask_s = (0xff >> (x1%8));
	mask_e = ~(0xff >> (x2%8+1));


	for (i=start_offset; i<= end_offset; ++i) {
		screen[i]=0xFF;
		printf("set\n");
	}
		
	if (start_offset > end_offset)
	{
		screen[start_offset-1] |= (mask_s & mask_e);
	}
	else {
		if (x1%8)
			screen[start_offset-1] |= mask_s;

		if (x2%8)
			screen[end_offset+1] |= mask_e;
	}
}


int main()
{
	unsigned char screen[1200];
	int i;

	for (i=0;i<1200;i++)
		screen[i]=0;

	draw(screen, 24, 2, 20, 1);

	for (i=0;i<100;i++)
	{
		if (i%3 == 0)
		printf("\n");

		printf("%X\n", screen[i]);
	}

	return 0;
}
