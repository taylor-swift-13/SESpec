#include <stdlib.h>

int findLucas(int seed);

int findLucas(int seed) {

		int *result = (int *)malloc(sizeof(int) * (seed + 1));
int result_len = seed + 1;
		result[0] = 2;
		result[1] = 1;
		for (int c = 2; c <= seed; c++) {
			result[c] = result[c - 1]
					+ result[c - 2];
		}
		return result[seed];
}
