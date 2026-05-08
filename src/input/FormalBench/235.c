#include <stdlib.h>

int foo235(int num);

int foo235(int num) {

		int *arr = (int *)malloc(sizeof(int) * (num + 1));
int arr_len = num + 1;
		arr[0] = 0;
		for (int c = 0; c <= num - 1; c++) {
			arr[c + 1] = arr[c] + 6 * c + 1;
		}
		return arr[num];
}
