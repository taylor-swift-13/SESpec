#include <stdlib.h>

int foo185(int seed);

int foo185(int seed) {

		int *arr = (int *)malloc(sizeof(int) * (seed + 1));
int arr_len = seed + 1;
		arr[0] = 0;
		arr[1] = 1;
		for (int p = 2; p <= seed; p++) {
			arr[p] = (2 * arr[p - 1]
					+ arr[p - 2]) % 1000000000;
		}
		return arr[seed];
}
