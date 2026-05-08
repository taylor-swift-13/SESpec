#include <stdlib.h>

int foo55(int n);

int foo55(int n) {

		int *arr = (int *)malloc(sizeof(int) * (n + 1));
int arr_len = n + 1;
		arr[0] = 1;
		for (int c = 1; c <= n; c++) {
			arr[c] = 0;
			for (int k = 0; k < c; k++) {
				arr[c] += arr[k]
						* arr[c - k - 1];
			}
		}
		return arr[n];
}
