
#include <limits.h>

/*@
  requires n > 0 && y > 0;
  assigns \nothing;
  ensures (n <= 0 || y <= 0) ==> \result == n * y;
  ensures (n > 0 && y > 0) ==> \result > 0;
  ensures (n > 0 && y > 0) ==> \result >= 1;
  ensures (n > 0 && y > 0) ==> \result >= 1;
*/
int foo321(int n, int y) {

		int ret = 1;
		int r = 1;
		if (n > y) {
			int g = n;
			n = y;
			y = g;
		}
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= l;
          loop invariant ret >= 1;
          loop invariant ret <= l;
          loop invariant n % ret == 0 && y % ret == 0;
          loop invariant \forall integer k; 1 <= k < l && n % k == 0 && y % k == 0 ==> k <= ret;
          loop invariant \exists integer k; 1 <= k <= ret && n % k == 0 && y % k == 0;
          loop invariant n <= y;
          loop invariant n == \at(n,Pre) || n == \at(y,Pre);
          loop invariant y == \at(n,Pre) || y == \at(y,Pre);
          loop assigns l, ret;
            */
            for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
            
		r = (n * y) / ret;
		return r;
}
