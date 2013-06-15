#include <stdio.h>
#include <stdlib.h>

void bitSet(unsigned char *data, unsigned int num) {
	unsigned int index_byte;
	unsigned int index_bit;

	if (num >= 4000000000u) return;

	index_byte = num/8;
	index_bit = num%8;

	data[index_byte] |= (1<<index_bit);
}

int isFilled(unsigned char *data, unsigned int num) {
	unsigned int index_byte;
	unsigned int index_bit;

	index_byte = num/8;
	index_bit = num%8;

	if (num >= 4000000000u) return -1;

	return data[index_byte] & (1<<index_bit);
}

unsigned int FindFirst(const char* filename) {

	FILE *file;
	unsigned int readval;
	unsigned char *buf;
	unsigned int i;

	buf = malloc(1000000000u);

	for (i=0; i<1000000000u; ++i) {
		buf[i] = 0;
	}

	file = fopen(filename,"r");

	while (fscanf(file,"%u", &readval) != EOF) {
		bitSet(buf, readval);
	}

	for (i=0; i<4000000000u; ++i)
	{
		if (isFilled(buf, i) == 0) {
			return i;
		}
	}
	return -1;
}

int main() {

	return 0;
}
