#include <stdlib.h>

/*@
  logic integer JL(integer n);
  axiomatic JacobsthalLucas {
    axiom JL_0: JL(0) == 2;
    axiom JL_1: JL(1) == 1;
    axiom JL_rec: \forall integer n; n >= 2 ==> JL(n) == JL(n-1) + 2*JL(n-2);
  }
*/

/*@
    requires c >= 1;
    assigns \nothing;
    ensures \result == JL(c);
*/
int jacobsthalLucas(int c);

int jacobsthalLucas(int c) {

		int *N = (int *)malloc(sizeof(int) * (c + 1));
		int N_len = c + 1;
		N[0] = 2;
		N[1] = 1;
		/*@
		  loop invariant 2 <= p <= c + 1;
		  loop invariant \forall integer k; 0 <= k < p ==> N[k] == JL(k);
		  loop assigns p, N[0..c];
		  loop variant c - p + 1;
		*/
		for (int p = 2; p <= c; p++) {
			N[p] = N[p - 1]
					+ 2 * N[p - 2];
		}
		return N[c];
}
