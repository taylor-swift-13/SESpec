#include <stdlib.h>

int foo241(int p);

int foo241(int p) {

		int *arr = (int *)malloc(sizeof(int) * (p + 1));
int arr_len = p + 1;
		arr[0] = 0;
		for (int c = 0; c <= p - 1; c++) {
			arr[c + 1] = arr[c] + 7 * c + 1;
		}
		return arr[p];
}
