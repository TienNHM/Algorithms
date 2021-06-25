#include <stdio.h>

int betterLinearSearch(int A[], int n, int x);

int main(){
	int A[] = {1, -4, 5, 0, -2, 5, 8, 1, 7, -2};
	int value = 5;
	// Get number of elements
	int n = sizeof(A)/sizeof(A[0]);
	int pos = betterLinearSearch(A, n, value);
	printf("%d", pos);
	return 0;
}

int betterLinearSearch(int A[], int n, int x){
	for (int i = 0; i < n; i++){
		if (x == A[i]){
			return i;
		}
	}
	return -1;
}
