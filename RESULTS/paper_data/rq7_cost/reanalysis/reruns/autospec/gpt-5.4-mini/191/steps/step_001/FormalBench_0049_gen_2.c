#include <stdlib.h>

int countWays(int count);

int countWays(int count) {

		int *W = (int *)malloc(sizeof(int) * (count + 1));
int W_len = count + 1;
		int *C = (int *)malloc(sizeof(int) * (count + 1));
int C_len = count + 1;
		W[0] = 1;
		W[1] = 0;
		C[0] = 0;
		C[1] = 1;
		/*@
		loop invariant 2 <= w <= count + 1;
		loop invariant W[0] == 1 && W[1] == 0;
		loop invariant C[0] == 0 && C[1] == 1;
		loop invariant \forall integer k; 2 <= k < w ==> W[k] == W[k - 2] + 2 * C[k - 1];
		loop invariant \forall integer k; 2 <= k < w ==> C[k] == W[k - 1] + C[k - 2];
		loop assigns w;
		loop assigns W[2..count];
		loop assigns C[2..count];
		*/
		for (int w = 2; w <= count; w++) {
			W[w] = W[w - 2]
					+ 2 * C[w - 1];
			C[w] = W[w - 1] + C[w - 2];
		}
		return W[count];
}
