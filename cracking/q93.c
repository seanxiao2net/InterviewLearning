#include <stdio.h>

/*int FindMagic(int token, int arr[], int sz)*/
/*{*/
/*	if (token == arr[token]) return token;*/
/*	else if ((token +1 < sz)&&(arr[token] < token)) return FindMagic(token+1, arr, sz);*/
/*	else return -1;*/
/*}*/

int FindMagic(int begin, int end, int arr[]) {
	int mid = (begin+end)/2;
	if (begin > end) return -1;

	if (arr[mid] == mid) return mid;
	else if (arr[mid] < mid) return FindMagic(mid+1, end, arr);
	else return FindMagic(begin, mid-1, arr);
}

int FindMagicExt(int begin, int end, int arr) {
	int mid = (begin+end)/2;
	int left, right;

	if (begin > end) return -1;

	if (mid = arr[mid]) return mid;
	
	left = FindMagicExt(begin, mid-1, arr);
	if (left >= 0) return left;

	right = FindMagicExt(mid+1, end, arr);
	if (right >= 0) return right;
}

int main() {


	return 0;
}
