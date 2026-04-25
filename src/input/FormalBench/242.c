#include <stdlib.h>

int foo242(int num);

int foo242(int num) {

		int *arr = (int *)malloc(sizeof(int) * (num + 1));
int arr_len = num + 1;
		arr[0] = 0;
		for (int p = 0; p <= num - 1; p++) {
			arr[p + 1] = arr[p] + 7 * p + 1;
		}
		return arr[num];
}
