#include <stdio.h>

int recursiveLinearSearch(int A[], int n, int i, int x);

int main(){
	int A[] = {1, -4, 5, 0, -2, 5, 8, 1, 7, -2};
	int value = 5;
	// Get number of elements
	int n = sizeof(A)/sizeof(A[0]);
	int pos = recursiveLinearSearch(A, n, 0, value);
	printf("%d", pos);
	return 0;
}

int recursiveLinearSearch(int A[], int n, int i, int x){
	if (i >= n) return -1;
	else {
		if (A[i] == x) 
			return i;
		else
			return recursiveLinearSearch(A, n, i+1, x);
	}
}
