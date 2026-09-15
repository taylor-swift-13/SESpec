#include <stdlib.h>

int jacobsthalNum(int c);

/*@ logic integer J(integer n) =
      n == 0 ? 0 :
      n == 1 ? 1 :
      J(n-1) + 2*J(n-2);
*/

/*@ requires c >= 1;
    assigns \nothing;
    ensures \result == J(c);
*/
int jacobsthalNum(int c) {

		int *j = (int *)malloc(sizeof(int) * (c + 1));
int j_len = c + 1;
		/*@ assert j != \null; */
		/*@ assert \valid(j + (0..c)); */
		j[0] = 0;
		j[1] = 1;
		/*@ assert j[0] == J(0) && j[1] == J(1); */
		/*@ loop invariant 2 <= p <= c+1;
		    loop invariant \forall integer k; 0 <= k < p ==> j[k] == J(k);
		    loop assigns j[2..c], p;
		    loop variant c - p + 1;
		*/
		for (int p = 2; p <= c; p++) {
			j[p] = j[p - 1]
					+ 2 * j[p - 2];
			/*@ assert j[p] == J(p); */
		}
		return j[c];
}
