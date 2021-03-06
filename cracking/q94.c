#include <stdio.h>
#include <string.h>

void Subset(char* set, char* buff,  int sz, int token, int lvl) {
	int i;
	for (i=token; i<sz; ++i) {
		*(buff+lvl) = set[i];
		*(buff+lvl+1) = '\0';
		printf("%s\n", buff);

		if (i<sz-1) Subset(set, buff, sz, i+1, lvl+1);
	}
}


int main() {
	char set[] = "ABCD";
	int sz = strlen(set);
	char buff[sz+1];

	Subset(set, buff, sz, 0, 0);

	return 0;
}
