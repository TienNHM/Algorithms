#include <stdio.h>

void insertionSort(int A[], int n);
void swap(int &x, int &y);
void show(int A[], int n);

int main(){
	int A[] = {1, -2, 4, 0, 5, 7, 9, 2, 1, 3};
	int n = sizeof(A)/sizeof(A[0]);
	insertionSort(A, n);
	show(A, n);
	return 0;
}

void insertionSort(int A[], int n){
	int key, j;
	for (int i=1; i<n; i++){
		key = A[i];
		
		j = i-1;
		while (j>=0 && A[j] > key){
			A[j+1] = A[j];
			j--;
		}
		
		A[j+1] = key;
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
