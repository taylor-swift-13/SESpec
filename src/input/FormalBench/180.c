#include <stdlib.h>

int foo180(int j);

int foo180(int j) {

		int *ret = (int *)malloc(sizeof(int) * (j + 1));
int ret_len = j + 1;
		ret[0] = 0;
		ret[1] = 1;
		for (int p = 2; p <= j; p++) {
			ret[p] = ret[p - 1]
					+ 2 * ret[p - 2];
		}
		return ret[j];
}
