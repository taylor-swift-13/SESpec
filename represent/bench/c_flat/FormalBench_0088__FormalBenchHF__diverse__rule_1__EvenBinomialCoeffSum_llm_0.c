#include <stdlib.h>

int evenBinomialCoeffSum(int seed);

int evenBinomialCoeffSum(int seed) {

		int result = 0;
		int *arr = (int *)malloc(sizeof(int) * (seed + 1));
int arr_len = seed + 1;
		arr[0] = 1;
		for (int d = 1; d <= seed; d++) {
			for (int c = 0; c < d; c++) {
				arr[d] = arr[d] + arr[c];
			}
		}
		return arr[seed];
}
