# LINEAR SEARCH

## Ý tưởng
Giả sử hàm trả về biến `answer` lưu vị trí của phần tử có giá trị cần tìm trong mảng A. Lần lượt duyệt qua các phần tử của mảng, nếu phần tử thứ i có giá trị cần tìm thì ta gán `answer = i`.

## Thuật toán

***Procedure*** `LINEAR_SEARCH(A, n, x)`

### Inputs
 - `A`: Mảng đầu vào;
- `n`: số lượng phần tử của mảng A;
- `x`: giá trị cần tìm kiếm.

### Output
- Vị trí index cuối cùng `i`, tại đó `A[i] = x`;
- Giá trị `-1`, nếu không tìm thấy giá trị `x` trong mảng `A`.

### Steps
1. Khởi tạo biến answer = -1.
2. Với mỗi phần tử `A[i]` (i=0..n-1), kiểm tra:
    - Nếu `A[i] = x` thì gán `answer = i`;
3. Trả về giá trị answer.

## Code

```cpp
#include <stdio.h>

int linearSearch(int A[], int n, int x);

int main(){
	int A[] = {1, -4, 5, 0, -2, 5, 8, 1, 7, -2};
	int value = 5;
	// Get number of elements
	int n = sizeof(A)/sizeof(A[0]);
	int pos = linearSearch(A, n, value);
	printf("%d", pos);
	return 0;
}

int linearSearch(int A[], int n, int x){
	int answer = -1;
	for (int i = 0; i < n; i++){
		if (x == A[i]){
			answer = i;
		}
	}
	return answer;
}
```

# BETTER LINEAR SEARCH

## Ý tưởng
Lần lượt duyệt qua các phần tử của mảng, nếu phần tử thứ i có giá trị cần tìm thì trả về giá trị `i`. Nếu đã duyệt qua hết tất cả các phần tử mà vẫn không tìm thấy, trả về giá trị `-1`.

## Thuật toán

***Procedure*** `BETTER_LINEAR_SEARCH(A, n, x)`

### Inputs
- `A`: Mảng đầu vào;
- `n`: số lượng phần tử của mảng A;
- `x`: giá trị cần tìm kiếm.

### Output
- Vị trí index đầu tiên `i`, tại đó `A[i] = x`;
- Giá trị `-1`, nếu không tìm thấy giá trị `x` trong mảng `A`.

### Steps
1. Với mỗi phần tử `A[i]` (i=0..n-1), kiểm tra:
    - Nếu `A[i] = x` thì trả về `i`;
2. Trả về giá trị `-1`.

## Code

```cpp
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
```

# Sentinel Linear Search

## Ý tưởng
Với 2 thuật toán ở trên, ở mỗi vòng lặp ta phải kiểm tra đồng thời 2 điều kiện:
- Đã duyệt hết tất cả phần tử của mảng A hay chưa?
- Phần tử thứ i của mảng A có phải là giá trị cần tìm hay không?
Vì vậy, số lượng câu lệnh thực hiện tăng lên gấp đôi. Và thuật toán Sentinel Linear Search sẽ khắc phục nhược điểm trên.

## Thuật toán

***Procedure*** `SENTINEL_LINEAR_SEARCH(A, n, x)`

### Inputs
- `A`: Mảng đầu vào;
- `n`: số lượng phần tử của mảng A;
- `x`: giá trị cần tìm kiếm.

### Output
- Vị trí index đầu tiên `i`, tại đó `A[i] = x`;
- Giá trị `-1`, nếu không tìm thấy giá trị `x` trong mảng `A`.

### Steps
1. Thêm 1 phần tử có giá trị `x` vào cuối mảng `A`.
2. Khởi tạo biến `i = 0`.
3. Trong khi `A[i] != x`, ta cứ tăng biến `i` để duyệt lần lượt qua các phần tử.
4. Nếu `i < n`, nghĩa là ta đã tìm thấy phần tử mang giá trị `x` ở vị trí `i`. Ta trả về giá trị `i`.
5. Ngược lại, trả về `-1` do không tìm thấy.

## Code

```cpp
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
```

# Recursive Linear Search

## Ý tưởng
Áp dụng để quy vào thuật toán tìm kiếm (Better) Linear Search.

## Thuật toán
***Procedure*** `RECURSIVE_LINEAR_SEARCH(A, n, i, x)`

### Inputs
- `A`: Mảng đầu vào;
- `n`: số lượng phần tử của mảng A;
- `i`: vị trí mảng con bắt đầu tìm kiếm;
- `x`: giá trị cần tìm kiếm.

### Output
- Vị trí index đầu tiên `i`, tại đó `A[i] = x`;
- Giá trị `-1`, nếu không tìm thấy giá trị `x` trong mảng `A`.

### Steps
1. Nếu `i >= n`, trả về `-1`.
2. Ngược lại, nếu `i < n` và `A[i] = x` thì trả về `i`.
3. Ngược lại, nếu `i < n` và `A[i] != x` thì trả về `RECURSIVE_LINEAR_SEARCH(A, n, i+1, x)`.

## Code
```cpp
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
```
