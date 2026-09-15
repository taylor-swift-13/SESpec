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
		loop invariant W[0] == 1;
		loop invariant W[1] == 0;
		loop invariant C[0] == 0;
		loop invariant C[1] == 1;
		loop invariant \forall integer i; 2 <= i < w ==> W[i] == W[i - 2] + 2 * C[i - 1];
		loop invariant \forall integer i; 2 <= i < w ==> C[i] == W[i - 1] + C[i - 2];
		loop assigns w;
		loop assigns W[0..count];
		loop assigns C[0..count];
		*/
		for (int w = 2; w <= count; w++) {
			W[w] = W[w - 2]
					+ 2 * C[w - 1];
			C[w] = W[w - 1] + C[w - 2];
		}
		return W[count];
}
