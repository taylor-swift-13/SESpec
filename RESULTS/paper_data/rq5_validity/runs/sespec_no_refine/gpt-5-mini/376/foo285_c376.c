
#include <limits.h>

/*@
  logic integer fact(integer n) =
    n <= 1 ? 1 : n * fact(n - 1);

  logic integer binomial(integer n, integer k) =
    k < 0 || k > n ? 0 :
    k == 0 ? 1 :
    n * binomial(n - 1, k - 1) / k;
*/

/*@
  requires \true;
  assigns \nothing;
  ensures seed == \old(seed);
*/
int foo285_c376(int seed, int m) {

		if (m > seed - m)
			m = seed - m;
		int b = 1;
		
            
        /*@
          loop invariant seed == \at(seed,Pre);
          loop assigns r, b;
        */
            for (int r = 1; r <= m; r++) {
			b = b * (seed - r + 1) / r;
		}
            
		return b;
}
