#include <stdlib.h>

/*@
    requires c >= 1;
    requires \valid(((int *)malloc(sizeof(int) * (c + 1))) + (0 .. c));
    assigns \nothing;
    ensures \result == 2 || \result >= 0;
*/
int jacobsthalLucas(int c);

int jacobsthalLucas(int c) {

		int *j = (int *)malloc(sizeof(int) * (c + 1));
int j_len = c + 1;
		j[0] = 2;
		j[1] = 1;
		/*@
		    loop invariant 2 <= p <= c + 1;
		    loop invariant \valid(j + (0 .. c));
		    loop invariant j[0] == 2;
		    loop invariant j[1] == 1;
		    loop invariant \forall integer k; 2 <= k < p ==> j[k] == j[k - 1] + 2 * j[k - 2];
		    loop assigns p, j[2 .. c];
		    loop variant c - p + 1;
		*/
		for (int p = 2; p <= c; p++) {
			j[p] = j[p - 1]
					+ 2 * j[p - 2];
		}
		return j[c];
}
