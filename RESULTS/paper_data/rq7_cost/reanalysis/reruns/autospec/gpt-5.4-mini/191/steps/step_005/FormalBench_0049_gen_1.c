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
		loop invariant \forall integer i; 2 <= i < w ==> W[i] == W[i - 2] + 2 * C[i - 1];
		loop invariant \forall integer i; 2 <= i < w ==> C[i] == W[i - 1] + C[i - 2];
		loop invariant \forall integer i; 0 <= i < w && i < W_len ==> 0 <= W[i];
		loop invariant \forall integer i; 0 <= i < w && i < C_len ==> 0 <= C[i];
		loop invariant \forall integer i; 0 <= i < w ==> W[i] == 0 || W[i] > 0;
		loop invariant \forall integer i; 0 <= i < w ==> C[i] == 0 || C[i] > 0;
		loop invariant w <= count + 1;
		loop invariant \forall integer k; 2 <= k < w ==> W[k] == W[k - 2] + 2 * C[k - 1];
		loop invariant \forall integer k; 2 <= k < w ==> W[k] == W[k - 2] + 2 * C[k - 1] && C[k] == W[k - 1] + C[k - 2];
		loop invariant \forall integer k; 2 <= k < w ==> C[k] == W[k - 1] + C[k - 2];
		loop invariant \forall integer k; 2 <= k < w ==> (W[k] == W[k - 2] + 2 * C[k - 1] && C[k] == W[k - 1] + C[k - 2]);
		loop invariant \forall integer k; 0 <= k < w ==> W[k] >= 0;
		loop invariant \forall integer k; 0 <= k < w ==> W[k] >= 0 && C[k] >= 0;
		loop invariant \forall integer k; 0 <= k < w ==> W[k] == 0 || W[k] > 0;
		loop invariant \forall integer k; 0 <= k < w ==> C[k] >= 0;
		loop invariant \forall integer k; 0 <= k < w ==> C[k] == 0 || C[k] > 0;
		loop invariant \forall integer k; 0 <= k < w ==> 0 <= W[k];
		loop invariant \forall integer k; 0 <= k < w ==> 0 <= W[k] && 0 <= C[k];
		loop invariant \forall integer k; 0 <= k < w ==> 0 <= C[k];
		loop invariant \forall integer k; 0 <= k < w && k < W_len ==> W[k] >= 0;
		loop invariant \forall integer k; 0 <= k < w && k < W_len ==> W[k] >= 0 && C[k] >= 0;
		loop invariant \forall integer k; 0 <= k < w && k < C_len ==> C[k] >= 0;
		loop invariant \forall integer i; 2 <= i < w ==> W[i] == W[i - 2] + 2 * C[i - 1];
		loop invariant \forall integer i; 2 <= i < w ==> W[i] == W[i - 2] + 2 * C[i - 1] && C[i] == W[i - 1] + C[i - 2];
		loop invariant \forall integer i; 2 <= i < w ==> C[i] == W[i - 1] + C[i - 2];
		loop invariant \forall integer i; 0 <= i < w ==> W[i] >= 0;
		loop invariant \forall integer i; 0 <= i < w ==> W[i] >= 0 && C[i] >= 0;
		loop invariant \forall integer i; 0 <= i < w ==> W[i] == W[i];
		loop invariant \forall integer i; 0 <= i < w ==> W[i] == 0 || W[i] >= 1;
		loop invariant \forall integer i; 0 <= i < w ==> W[i] == 0 || W[i] > 0;
		loop invariant \forall integer i; 0 <= i < w ==> C[i] >= 0;
		loop invariant \forall integer i; 0 <= i < w ==> C[i] == 0 || C[i] >= 1;
		loop invariant \forall integer i; 0 <= i < w ==> C[i] == 0 || C[i] > 0;
		loop invariant \forall integer i; 0 <= i < w ==> 0 <= W[i];
		loop invariant \forall integer i; 0 <= i < w ==> 0 <= C[i];
		loop invariant \forall integer i; 0 <= i < 2 ==> (i == 0 ==> W[i] == 1) && (i == 1 ==> W[i] == 0);
		loop invariant W[1] == 0;
		loop invariant W[0] == 1;
		loop invariant W[0] == 1 && W[1] == 0;
		loop invariant W[0] == 1 && W[1] == 0 && C[0] == 0 && C[1] == 1;
		loop invariant C[1] == 1;
		loop invariant C[0] == 0;
		loop invariant C[0] == 0 && C[1] == 1;
		loop invariant 2 <= w;
		loop assigns w;
		loop assigns W[2..count];
		loop assigns W[0..count];
		loop assigns C[2..count];
		loop assigns C[0..count];
		*/
		for (int w = 2; w <= count; w++) {
			W[w] = W[w - 2]
					+ 2 * C[w - 1];
			C[w] = W[w - 1] + C[w - 2];
		}
		return W[count];
}
