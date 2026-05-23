
/*@ 
  logic integer seq(integer n) =
    n == 0 ? 2
  : n == 1 ? 1
  : seq(n-1) + 2*seq(n-2);
*/

/*@ 
  logic integer count_defined(integer lo, integer hi) = lo >= hi ? 0 : 1 + count_defined(lo+1, hi);
*/

#include <stdlib.h>

/*@
  requires c >= 1;
  assigns \nothing;
*/
int foo289(int c) {

		int *j = (int *)malloc(sizeof(int) * (c + 1));
int j_len = c + 1;
		j[0] = 2;
		j[1] = 1;
		
            
        /*@
          loop invariant 2 <= d <= c+1 ? (\forall integer k; 0 <= k < d ==> j[k] == seq(k)) : (d >= 0);
          loop assigns j[0..c];
        */
            for (int d = 2; d <= c; d++) {
			j[d] = j[d - 1]
					+ 2 * j[d - 2];
		}
            
		return j[c];
}
