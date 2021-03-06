#include <stdio.h>
#include <stdlib.h>

void CheckDuplicates(int arr[], int sz) {
	unsigned char tab[4000];
	int i;
	int i_byte, i_bit;

	for (i=0; i<4000; ++i) {
		tab[i] = 0;
	}

	for (i=0; i<sz; ++i) {
		i_byte = arr[i]/8;
		i_bit = arr[i]%8;
		if (tab[i_byte] & (1<<i_bit)) {
			printf("duplicate number %d\n", arr[i]);
		} else {
			tab[i_byte] |= (1<<i_bit);
		}
	}
}

void CheckDuplicates_slow(int arr[], int sz) {
	int tab[1000];
	int start=0;
	int i;

	for (start=0; start+1000 < sz; start += 1000) {
		for (i=0; i<1000; ++i) tab[i]=0;
		for (i=0; i<sz; ++i) {
			if ((arr[i]<= start+1000) && (arr[i]>= start)) {
				++tab[arr[i]-start];
			}
		}
		for (i=0; i<1000; ++i) {
			if (tab[i]>1)
				printf("number %d appeared for %d times\n", i+start, tab[i]);
		}
	}
}


int main() {
	int nums[32000];
	int i;

	for (i=0; i<32000; ++i) {
		nums[i] = i;
	}
	nums[200] = 32;
	nums[400] = 571;
	nums[12456] = 778;
	nums[12856] = 778;

	//CheckDuplicates(nums, sizeof(nums)/sizeof(int));
	CheckDuplicates_slow(nums, sizeof(nums)/sizeof(int));
	return 0;
}
