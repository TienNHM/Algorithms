#include <stdio.h>

int sentinelLinearSearch(int A[], int n, int x);

int main(){
	int A[] = {1, -4, 5, 0, -2, 5, 8, 1, 7, -2};
	int value = 5;
	// Get number of elements
	int n = sizeof(A)/sizeof(A[0]);
	int pos = sentinelLinearSearch(A, n, value);
	printf("%d", pos);
	return 0;
}

int sentinelLinearSearch(int A[], int n, int x){
	A[n] = x;
	int i = 0;
	while (A[i] != x) i++;
	if (i < n){
		return i;
	}
	return -1;
}
