#include <stdlib.h>

/*@
  logic integer jacobsthal_rec(integer n) =
    n == 0 ? 0 :
    n == 1 ? 1 :
    jacobsthal_rec(n-1) + 2 * jacobsthal_rec(n-2);
*/

/*@
    requires c >= 1;
    assigns \nothing;
    ensures \result == jacobsthal_rec(c);
*/
int jacobsthalNum(int c);

int jacobsthalNum(int c) {

		int *j = (int *)malloc(sizeof(int) * (c + 1));
		/*@ assert j != \null; */
		/*@ assert \valid(j + (0..c)); */
int j_len = c + 1;
		j[0] = 0;
		j[1] = 1;
		/*@
		    loop invariant 2 <= p <= c+1;
		    loop invariant \forall integer k; 0 <= k < p ==> j[k] == jacobsthal_rec(k);
		    loop assigns p, j[0..p-1];
		    loop variant c - p + 1;
		*/
		for (int p = 2; p <= c; p++) {
			j[p] = j[p - 1]
					+ 2 * j[p - 2];
		}
		return j[c];
}
