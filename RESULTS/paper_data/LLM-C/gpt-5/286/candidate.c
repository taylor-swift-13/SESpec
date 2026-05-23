#include <stdlib.h>

/*@ 
  logic integer jacobsthal(integer n) =
    (n <= 0 ? 0 : (n == 1 ? 1 : jacobsthal(n-1) + 2*jacobsthal(n-2)));
*/

/*@ 
  requires j >= 1;
  ensures \result == jacobsthal(j);
*/
int jacobsthalNum(int j);

int jacobsthalNum(int j) {

		int *r = (int *)malloc(sizeof(int) * (j + 1));
/*@ 
  assume r != \null;
  assume \valid(r + (0 .. j));
*/
int r_len = j + 1;
/*@ assert r_len == j + 1; */
		r[0] = 0;
		r[1] = 1;
		/*@
		  loop invariant 2 <= p <= j;
		  loop invariant \valid(r + (0 .. j));
		  loop invariant r[0] == 0 && r[1] == 1;
		  loop invariant \forall integer k; 0 <= k < p ==> r[k] == jacobsthal(k);
		  loop assigns p, r[2 .. j];
		  loop variant j - p;
		*/
		for (int p = 2; p <= j; p++) {
			r[p] = r[p - 1]
					+ 2 * r[p - 2];
		}
		/*@ assert r[j] == jacobsthal(j); */
		return r[j];
}
