#include <stdlib.h>

int foo49(int count);

int foo49(int count) {

		int *W = (int *)malloc(sizeof(int) * (count + 1));
int W_len = count + 1;
		int *C = (int *)malloc(sizeof(int) * (count + 1));
int C_len = count + 1;
		W[0] = 1;
		W[1] = 0;
		C[0] = 0;
		C[1] = 1;
		for (int w = 2; w <= count; w++) {
			W[w] = W[w - 2]
					+ 2 * C[w - 1];
			C[w] = W[w - 1] + C[w - 2];
		}
		return W[count];
}
