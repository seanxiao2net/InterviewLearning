#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

int f(const char* str, char res, int s, int e) {
	int count = 0;
	int i;
	char op;
	if (s == e) {
		if(str[s] == '1' && res == true)	return 1;
		else if(str[s] == '0' && res == false)	return 1;
		else	return 0;
	}

	if (res == true) {
		for (i=s+1; i<=e; i = i+2) {
			op = str[i];

			if (op =='&') {
				count+= f(str, true, s, i-1)*f(str,true,i+1,e);
			} else if (op == '|') {
				count+= f(str, true, s, i-1)*f(str, false, i+1,e);
				count+= f(str, false, s, i-1)*f(str, true, i+1,e);
				count+= f(str, true, s, i-1)*f(str, true, i+1,e);
			} else if (op == '^') {
				count+= f(str, true, s, i-1)*f(str, false, i+1,e);
				count+= f(str, false, s, i-1)*f(str, true, i+1,e);
			}
		}

	} else {
		for (i=s+1; i<=e; i+=2) {
			op = str[i];

			if (op =='&') {
				count+= f(str, true, s, i-1)*f(str,false,i+1,e);
				count+= f(str, false, s, i-1)*f(str,true,i+1,e);
				count+= f(str, false, s, i-1)*f(str,false,i+1,e);
			} else if (op == '|') {
				count+= f(str, false, s, i-1)*f(str, false, i+1,e);
			} else if (op == '^') {
				count+= f(str, true, s, i-1)*f(str, true, i+1,e);
				count+= f(str, false, s, i-1)*f(str, false, i+1,e);
			}
		}
	}
	return count;
}



int main() {
	char *eq = "1&0|1^0";
	char res = true;
	int result;

	result = f(eq, res, 0, 6);

	printf("result is %d\n", result);

	return 0;
}
