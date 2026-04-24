#include <stdlib.h>

int evenBinomialCoeffSum(int seed);

int evenBinomialCoeffSum(int seed) {

		int result = 0;
		int *temp = (int *)malloc(sizeof(int) * (seed + 1));
int temp_len = seed + 1;
		temp[0] = 1;
		for (int d = 1; d <= seed; d++) {
			for (int c = 0; c < d; c++) {
				temp[d] = temp[d] + temp[c];
			}
		}
		return temp[seed];
}
