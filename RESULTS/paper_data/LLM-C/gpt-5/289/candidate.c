#include <stdlib.h>

/*@ axiomatic JacobsthalLucas {
  logic integer J(integer n);

  axiom J_base0: J(0) == 2;
  axiom J_base1: J(1) == 1;
  axiom J_rec: \forall integer n; n >= 2 ==> J(n) == J(n-1) + 2*J(n-2);
} */

/*@ 
  requires c >= 1;
  assigns \nothing;
  ensures \result == J(c);
*/
int jacobsthalLucas(int c);

int jacobsthalLucas(int c) {

		int *j = (int *)malloc(sizeof(int) * (c + 1));
/*@ assume j != \null; */
/*@ assume \valid(j+(0..c)); */
int j_len = c + 1;
/*@ assert j_len == c + 1; */
		j[0] = 2;
		j[1] = 1;
/*@ assert j[0] == J(0) && j[1] == J(1); */
		for (int d = 2; d <= c; d++) {
			/*@ 
			  loop invariant 2 <= d <= c+1;
			  loop invariant \forall integer k; 0 <= k < d ==> j[k] == J(k);
			  loop assigns j[2..c], d;
			  loop variant c - d + 1;
			*/
			j[d] = j[d - 1]
					+ 2 * j[d - 2];
		}
/*@ assert j[c] == J(c); */
		return j[c];
}
