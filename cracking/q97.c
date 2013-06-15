#include <stdio.h>

enum Color {white, black, red , yellow, blue};

void paintFill(Color (*screen)[], int x_d, int y_d ,int x, int y, Color src, Color dest) {

	if (x<0 || x>=x_d)||(y<0 || y >= y_d) return;
	if (screen[y][x] != src) return;

	screen[y][x] = dest;
	paintFill(screen, x_d, y_d ,x+1, y, src, dest);
	paintFill(screen, x_d, y_d ,x-1, y, src, dest);
	paintFill(screen, x_d, y_d ,x, y+1, src, dest);
	paintFill(screen, x_d, y_d ,x, y-1, src, dest);
}
