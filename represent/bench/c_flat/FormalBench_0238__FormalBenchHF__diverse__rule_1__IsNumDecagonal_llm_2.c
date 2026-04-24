#include <stdlib.h>

int isNumDecagonal(int number);

int isNumDecagonal(int number) {

		int *arr = (int *)malloc(sizeof(int) * (number + 1));
int arr_len = number + 1;
		arr[0] = 0;
		for (int c = 0; c <= number - 1; c++) {
			arr[c + 1] = arr[c] + 8 * c + 1;
		}
		return arr[number];
}
