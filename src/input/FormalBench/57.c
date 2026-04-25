#include <stdlib.h>

int foo57(int number);

int foo57(int number) {

		int *arr = (int *)malloc(sizeof(int) * (number + 1));
int arr_len = number + 1;
		arr[0] = 1;
		for (int c = 1; c <= number; c++) {
			arr[c] = 0;
			for (int n = 0; n < c; n++) {
				arr[c] += arr[n]
						* arr[c - n - 1];
			}
		}
		return arr[number];
}
