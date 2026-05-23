#include <stdlib.h>

/*@ axiomatic Ways {
  logic integer ways(integer n, integer m);
  axiom ways_base0: \forall integer m; ways(0,m) == 1;
  axiom ways_base1: \forall integer m; ways(1,m) == m;
  axiom ways_base2: \forall integer m; ways(2,m) == m*m;
  axiom ways_rec: \forall integer n, m; n >= 3 ==> ways(n,m) == ((m - 1) * (ways(n - 1, m) + ways(n - 2, m))) % 1000000007;
} */

int countNoOfWays(int count, int m);

/*@
  requires count >= 2;
  requires 0 <= m <= 2;
  requires count + 1 <= SIZE_MAX / sizeof(int);
  ensures \result == ways(count, m);
  ensures 0 <= \result <= 1000000007 - 1;
*/
int countNoOfWays(int count, int m) {

		int w = 1000000007;
		int *div = (int *)malloc(sizeof(int) * (count + 1));
/*@ assert div != \null; */
/*@ assert \valid(div + (0..count)); */
int div_len = count + 1;
/*@ assert div_len == count + 1; */
		div[0] = 1;
/*@ assert div[0] == ways(0, m); */
		div[1] = m;
/*@ assert div[1] == ways(1, m); */
		div[2] = m * m;
/*@ assert div[2] == ways(2, m); */
/*@ 
  loop invariant 3 <= d <= count + 1;
  loop invariant \valid(div + (0..count));
  loop invariant \forall integer k; 0 <= k < d ==> div[k] == ways(k, m);
  loop invariant \forall integer k; 0 <= k < d ==> 0 <= div[k] <= 1000000007 - 1;
  loop assigns div[3..count], d;
  loop variant count - d;
*/
		for (int d = 3; d <= count; d++) {
			div[d] = ((m - 1)
					* (div[d - 1] + div[d - 2])) % w;
      /*@ assert div[d] == ways(d, m); */
		}
    /*@ assert div[count] == ways(count, m); */
		return div[count];
}
