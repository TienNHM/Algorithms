#include <stdio.h>

int binarySearch(int A[], int n, int value);

int main(){
	int A[] = {-5, -4, -1, 0, 1, 3, 5, 6, 8, 10};
	int value = 5;
	// Get number of elements
	int n = sizeof(A)/sizeof(A[0]);
	int pos = binarySearch(A, n, value);
	printf("%d", pos);
	return 0;
}

int binarySearch(int A[], int n, int value){
	int left = 0, right = n - 1;
	int middle;
	while (left <= right){
		middle = (left + right) / 2;
		if (value == A[middle]){
			return middle;
		}
		else if (value < A[middle]){
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
	}
	return -1;
}
