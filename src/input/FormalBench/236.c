#include <stdlib.h>

int foo236(int index);

int foo236(int index) {

		int *arr = (int *)malloc(sizeof(int) * (index + 1));
int arr_len = index + 1;
		arr[0] = 0;
		for (int j = 0; j <= index - 1; j++) {
			arr[j + 1] = arr[j] + 6 * j + 1;
		}
		return arr[index];
}
