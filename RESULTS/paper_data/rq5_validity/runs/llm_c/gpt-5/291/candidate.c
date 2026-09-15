#include <stdlib.h>

/*@ 
  logic integer JLucas(integer n) = 
    (n == 0 ? 2 : (n == 1 ? 1 : JLucas(n - 1) + 2 * JLucas(n - 2)));
*/

/*@ 
  requires sizeof(int) == 4;
  requires c >= 1;
  requires c <= 31;
  assigns \result;
  ensures \result == JLucas(c);
*/
int jacobsthalLucas(int c);

int jacobsthalLucas(int c) {

		int *j = (int *)malloc(sizeof(int) * (c + 1));
/*@ assert j != \null; */
/*@ assert \valid(j + (0..c)); */
int j_len = c + 1;
/*@ assert j_len == c + 1; */
		j[0] = 2;
		j[1] = 1;
/*@ assert j[0] == JLucas(0) && j[1] == JLucas(1); */
		/*@ 
		  loop invariant 2 <= p <= c + 1;
		  loop invariant \valid(j + (0..c));
		  loop invariant j[0] == JLucas(0) && j[1] == JLucas(1);
		  loop invariant \forall integer k; 2 <= k < p ==> j[k] == JLucas(k);
		  loop assigns p, j[2..c];
		  loop variant c - p + 1;
		*/
		for (int p = 2; p <= c; p++) {
			j[p] = j[p - 1]
					+ 2 * j[p - 2];
		}
/*@ assert \forall integer k; 0 <= k <= c ==> j[k] == JLucas(k); */
		return j[c];
}
