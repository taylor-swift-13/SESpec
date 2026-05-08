#include <stdlib.h>

int foo237(int index);

int foo237(int index) {

		int *arr = (int *)malloc(sizeof(int) * (index + 1));
int arr_len = index + 1;
		arr[0] = 0;
		for (int c = 0; c <= index - 1; c++) {
			arr[c + 1] = arr[c] + 6 * c + 1;
		}
		return arr[index];
}
