
#include <limits.h>

/*@
  logic integer binom(integer n, integer k) =
    k <= 0 ? 1 :
    n < 0 || k > n ? 0 :
    binom(n, k - 1) * (n - (k - 1)) / k;
*/

/*@
  requires \true;
*/
int foo286_c377(int seed, int p) {

		if (p > seed - p)
			p = seed - p;
		int b = 1;
		
            
        /*@
          loop invariant 1 <= r <= \at(p,Pre) + 1 ==> 0 <= r;
          loop invariant seed == \at(seed,Pre);
          loop assigns r, b;
        */
            for (int r = 1; r <= p; r++) {
			b = b * (seed - r + 1) / r;
		}
            
		return b;
}
