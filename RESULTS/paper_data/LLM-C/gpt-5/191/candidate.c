#include <stdlib.h>

/*@ axiomatic Recurrence {
  logic integer Wf(integer n);
  logic integer Cf(integer n);

  axiom W0: Wf(0) == 1;
  axiom W1: Wf(1) == 0;
  axiom C0: Cf(0) == 0;
  axiom C1: Cf(1) == 1;

  axiom Wrec:
    \forall integer n; n >= 2 ==> Wf(n) == Wf(n-2) + 2 * Cf(n-1);
  axiom Crec:
    \forall integer n; n >= 2 ==> Cf(n) == Wf(n-1) + Cf(n-2);
} */

int countWays(int count);

/*@ 
  requires count >= 1;
  ensures \result == Wf(count);
*/
int countWays(int count) {

		int *W = (int *)malloc(sizeof(int) * (count + 1));
/*@ assert W != \null; */
/*@ assert \valid(W + (0..count)); */
int W_len = count + 1;
/*@ assert W_len == count + 1; */
		int *C = (int *)malloc(sizeof(int) * (count + 1));
/*@ assert C != \null; */
/*@ assert \valid(C + (0..count)); */
/*@ assert \separated(W + (0..count), C + (0..count)); */
int C_len = count + 1;
/*@ assert C_len == count + 1; */
		W[0] = 1;
		W[1] = 0;
		C[0] = 0;
		C[1] = 1;
/*@ assert W[0] == Wf(0) && W[1] == Wf(1); */
/*@ assert C[0] == Cf(0) && C[1] == Cf(1); */
		for (int w = 2; w <= count; w++) {
			/*@ 
        loop invariant 2 <= w <= count + 1;
        loop invariant \valid(W + (0..count)) && \valid(C + (0..count));
        loop invariant \separated(W + (0..count), C + (0..count));
        loop invariant \forall integer k; 0 <= k <= 1 ==> (W[k] == Wf(k) && C[k] == Cf(k));
        loop invariant \forall integer k; 2 <= k < w ==> (W[k] == Wf(k) && C[k] == Cf(k));
        loop assigns W[2..count], C[2..count];
        loop variant count - w + 1;
      */
			W[w] = W[w - 2]
					+ 2 * C[w - 1];
			C[w] = W[w - 1] + C[w - 2];
		}
/*@ assert W[count] == Wf(count); */
		return W[count];
}
