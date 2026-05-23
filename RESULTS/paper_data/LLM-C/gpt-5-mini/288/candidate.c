#include <stdlib.h>

/*@
  logic integer J(integer n) = n == 0 ? 0
                            : n == 1 ? 1
                            : J(n-1) + 2*J(n-2);
*/

/*@
    requires j >= 1;
    assigns \nothing;
    ensures \result == J(j);
*/
int jacobsthalNum(int j) {

		int *ret = (int *)malloc(sizeof(int) * (j + 1));
int ret_len = j + 1;
        /*@ assume ret != \null; */
        /*@ assume \valid(ret + (0..j)); */

		ret[0] = 0;
		ret[1] = 1;
		/*@
		  loop invariant 2 <= p <= j+1;
		  loop invariant \forall integer k; 0 <= k < p ==> ret[k] == J(k);
		  loop assigns p, ret[2..j];
		  loop variant j - p + 1;
		*/
		for (int p = 2; p <= j; p++) {
			ret[p] = ret[p - 1]
					+ 2 * ret[p - 2];
		}
		return ret[j];
}
