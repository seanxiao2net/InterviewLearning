#include <stdio.h>

int findk(int k) {
	int buf[k];
	int p = 0;
	int s_3, s_5, s_7;
	int i;

	if (k <= 1) return 1;

	--k;
	buf[0] = 1;

	while (p <= k) {
		for (i=0; i<=p; ++i) {
			if (buf[i]*3 > buf[p]) {
				s_3 = buf[i]*3;
				break;
			}
		}
		for (i=0; i<=p; ++i) {
			if (buf[i]*5 > buf[p]) {
				s_5 = buf[i]*5;
				break;
			}
		}
		for (i=0; i<=p; ++i) {
			if (buf[i]*7 > buf[p]) {
				s_7 = buf[i]*7;
				break;
			}
		}
		buf[p+1] = (s_3<s_5)? s_3:s_5;
		buf[p+1] = (s_7<buf[p+1])? s_7:buf[p+1];

		++p;
	}

	return buf[k];
}


int main() {
	int i;

	for (i=1;i<20;i++)
		printf("%d\n",findk(i));
	
	return 0;
}
