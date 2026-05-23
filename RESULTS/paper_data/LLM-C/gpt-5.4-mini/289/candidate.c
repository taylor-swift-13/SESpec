#include <stdlib.h>

/*@
    requires c >= 1;
    assigns \nothing;
    ensures \result == j[c];
*/
int jacobsthalLucas(int c);

 /*@
    requires c >= 1;
    assigns \nothing;
    ensures \result == j[c];
*/
int jacobsthalLucas(int c) {

		int *j = (int *)malloc(sizeof(int) * (c + 1));
int j_len = c + 1;
		j[0] = 2;
		j[1] = 1;
		/*@
		    loop invariant 2 <= d <= c + 1;
		    loop invariant j[0] == 2;
		    loop invariant j[1] == 1;
		    loop invariant \forall integer i; 2 <= i < d ==> j[i] == j[i - 1] + 2 * j[i - 2];
		    loop assigns d, j[2..c];
		    loop variant c - d + 1;
		*/
		for (int d = 2; d <= c; d++) {
			j[d] = j[d - 1]
					+ 2 * j[d - 2];
		}
		return j[c];
}
