#include <stdlib.h>

/*@
    logic integer JL(integer n) = (n == 0 ? 2 :
                                   n == 1 ? 1 :
                                   JL(n-1) + 2 * JL(n-2));

    requires c >= 1;
    assigns \nothing;
    ensures \result == JL(c);
*/
int jacobsthalLucas(int c) {

		int *j = (int *)malloc(sizeof(int) * (c + 1));
int j_len = c + 1;
        /*@ assert j != \null; */
        /*@ assert \valid(j + (0 .. j_len-1)); */
		j[0] = 2;
		j[1] = 1;
		/*@
		    loop invariant 2 <= d <= c+1;
		    loop invariant \forall integer k; 0 <= k < d ==> j[k] == JL(k);
		    loop assigns d, j[2 .. c];
		    loop variant c - d + 1;
		*/
		for (int d = 2; d <= c; d++) {
			j[d] = j[d - 1]
					+ 2 * j[d - 2];
		}
		return j[c];
}
