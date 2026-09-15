#include <stdlib.h>

/*@
    requires c >= 1;
    requires \valid((int *)malloc(sizeof(int) * (c + 1)));
    assigns \nothing;
    ensures \result >= 0;
*/
int jacobsthalLucas(int c);

int jacobsthalLucas(int c) {

		int *N = (int *)malloc(sizeof(int) * (c + 1));
int N_len = c + 1;
		N[0] = 2;
		N[1] = 1;
		/*@
		    loop invariant 2 <= p <= c + 1;
		    loop invariant \valid(N + (0 .. c));
		    loop invariant N[0] == 2;
		    loop invariant N[1] == 1;
		    loop invariant \forall integer i; 2 <= i < p ==> N[i] == N[i - 1] + 2 * N[i - 2];
		    loop assigns p, N[2 .. c];
		    loop variant c - p + 1;
		*/
		for (int p = 2; p <= c; p++) {
			N[p] = N[p - 1]
					+ 2 * N[p - 2];
		}
		return N[c];
}
