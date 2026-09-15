#include <stdlib.h>

/*@ 
    logic integer J(int n) = 
        n == 0 ? 2 :
        n == 1 ? 1 :
        J(n-1) + 2 * J(n-2);

    requires c >= 1;
    assigns \nothing;
    ensures \result == J(c);
*/
int jacobsthalLucas(int c);

int jacobsthalLucas(int c) {

		int *j = (int *)malloc(sizeof(int) * (c + 1));
        /*@ assert \valid(j + (0 .. c)); */
int j_len = c + 1;
		j[0] = 2;
		j[1] = 1;
		/*@ 
		    loop invariant 2 <= p <= c+1;
		    loop invariant \forall integer k; 0 <= k < p ==> j[k] == J(k);
		    loop assigns p, j[0 .. c];
		    loop variant c - p + 1;
		*/
		for (int p = 2; p <= c; p++) {
			j[p] = j[p - 1]
					+ 2 * j[p - 2];
		}
		return j[c];
}
