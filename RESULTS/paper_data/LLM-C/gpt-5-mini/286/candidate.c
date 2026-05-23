#include <stdlib.h>

 /*@ 
     logic integer J(integer n) = 
         (n == 0 ? 0 :
           (n == 1 ? 1 :
             J(n-1) + 2 * J(n-2)));
 */

int jacobsthalNum(int j);

 /*@
     requires j >= 1;
     assigns \nothing;
     ensures \result == J(j);
 */
int jacobsthalNum(int j) {

		int *r = (int *)malloc(sizeof(int) * (j + 1));
		/*@ assert r != \null; */
		/*@ assert \valid(r + (0 .. j)); */

		int r_len = j + 1;
		r[0] = 0;
		r[1] = 1;
		/*@
		    loop invariant 2 <= p <= j+1;
		    loop invariant \forall integer k; 0 <= k < p ==> r[k] == J(k);
		    loop assigns p, r[0 .. j];
		    loop variant j - p + 1;
		*/
		for (int p = 2; p <= j; p++) {
			r[p] = r[p - 1]
					+ 2 * r[p - 2];
		}
		return r[j];
}
