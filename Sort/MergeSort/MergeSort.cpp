#include <stdio.h>
#define INF 10000

void mergeSort(int A[], int left, int right);
void merge(int A[], int left, int middle, int right);
void copy(int A[], int B[], int startA, int startB, int n);
void swap(int &x, int &y);
void show(int A[], int n);

int main(){
	int A[] = {1, -2, 4, 0, 5, 7, 9, 2, 1, 3};
	int n = sizeof(A)/sizeof(A[0]);
	mergeSort(A, 0, n);
	show(A, n);
	return 0;
}

void mergeSort(int A[], int left, int right){
	if (left < right){
		int middle = (left + right)/2;
		mergeSort(A, left, middle);
		mergeSort(A, middle+1, right);
		merge(A, left, middle, right);
	}
}

void merge(int A[], int left, int middle, int right){
	int n1 = middle - left + 1;
	int n2 = right - middle;
	
	int B[n1 + 1] = {0}, C[n2 + 1] = {0};
	
	copy(B, A, 0, left, n1);
	copy(C, A, 0, middle, n2);
	
	B[n1 + 1] = INF;
	C[n2 + 1] = INF;
	
	int i=0, j=0;
	for (int k=left; k<right; k++){
		if (B[i] <= C[j]){
			A[k] = B[i];
			i++;
		}
		else {
			A[k] = C[j];
			j++;
		}
	}
}

void copy(int A[], int B[], int startA, int startB, int n){
	for (int i=0; i<n; i++){
		A[startA + i] = B[startB + i];
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
