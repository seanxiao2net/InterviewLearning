#include <stdio.h>
#include <stdlib.h>

char getNum(int num, int pos)
{
	//int i;
	const char *str ="ABCDEFGHIJKLMNOPRSTUVWXYZ";
	if ((num == 0)||(num == 1))
	{
		return ' ';
	}
	else
		return *(str+(num-2)*3+pos - 1);

}

void convert(int * tel, char * str, int strsize, int lvl)
{
	int i;

	if (lvl == strsize)
	{
		printf("%s\n",str);
		return;
	}

	for (i=1;i<4;i++)
	{
		str[lvl] = getNum(tel[lvl],i);
		convert(tel, str, strsize, lvl+1);
		if (tel[lvl] == 0 || tel[lvl] == 1) break;
	}
}

int sumarr(int arr[], int size)
{
	int buffer=0;
	for (;size>0;size--)
	{
		buffer+=arr[size];
	}
	return buffer;
}

void convert2(int * tel, char * str, int strsize)
{
	int i;
	for (i=0;i<strsize;i++)
	{
		str[i] = getNum(tel[i],1);
	}

	while(1)
	{

		printf("%s\n",str);

		for (i=(strsize-1);i>=-1;i--)
		{
			if(i <0)
			{
				//printf("ended\n");
				return;
			}


			if((getNum(tel[i],3)==*(str+i))||tel[i] == 0 || tel[i] == 1)
			{
				*(str+i) = getNum(tel[i],1);
			}
			else if (getNum(tel[i],1)==*(str+i))
			{
				*(str+i) = getNum(tel[i],2);
				break;
			}
			else if (getNum(tel[i],2)==*(str+i))
			{
				*(str+i) = getNum(tel[i],3);
				break;
			}
		}
	}
}

int main()
{
	//int tmp;

	int tel[7] = {9,9,0,8,4,2,1};
	char *res;

	res = malloc(8);
	*(res+8) = '\0';


/*	tmp = getNum(9,2);*/
/*	printf("%c\n",tmp);*/

	convert(tel, res, 7, 0);
	//convert2(tel, res, 7);

	return 0;
}
