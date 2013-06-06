#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

struct s
{
	int x;
	int y;
	int a;
};

/*struct s* get_s_ptr(int *a_ptr)*/
/*{*/
/*	return (struct s*)((char*)a_ptr - (int)&((struct s*)0)->a);*/
/*}*/

struct s* get_s_ptr(int *a_ptr)
{
	return (struct s*)((char*)a_ptr - offsetof(struct s, a));
}

int main()
{
	struct s test;
	struct s* testp, *testp2;
	int *p;

	p = &(test.a);
	testp = &test;

	testp2 = get_s_ptr(p);

	if (testp == testp2)
		printf("good\n");

	return 0;

}
