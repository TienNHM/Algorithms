#include <stdio.h>

void selectionSort(int A[], int n);
void swap(int &x, int &y);
void show(int A[], int n);

int main(){
	int A[] = {1, -2, 4, 0, 5, 7, 9, 2, 1, 3};
	int n = sizeof(A)/sizeof(A[0]);
	selectionSort(A, n);
	show(A, n);
	return 0;
}

void selectionSort(int A[], int n){
	int smallest;
	for (int i=0; i<n-1; i++){
		// Find index of smallest element in subarray A[i..n]
		smallest = i;
		for (int j=i; j<n; j++){
			if (A[j] < A[smallest])
				smallest = j;
		}
		// Move the smallest element to the left of subarray A[i..n]
		swap(A[i], A[smallest]);
	}
}

void swap(int &x, int &y){
	int z = x;
	x = y;
	y = z;
}

void show(int A[], int n){
	for (int i=0; i<n; i++)
		printf("%d ", A[i]);
}
