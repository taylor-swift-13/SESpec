
#include <limits.h>

/*@
  logic integer sum_cubes(integer n) =
    (n <= 0) ? 0 : (n * n * n) + sum_cubes(n - 1);
*/

        
        
/*@
  requires diff >= 0;
*/

int foo330(int diff) {

		int result = 0;
		int max = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= j <= diff + 1;
          loop invariant 0 <= result;
          loop invariant result == sum_cubes(j - 1);
          loop invariant max == 0;
          loop invariant diff == \at(diff,Pre);
          loop assigns j, result;
            */
            for (int j = 1; j <= diff; j++) {
			result += j * j * j;
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= j <= diff + 1;
          loop invariant 0 <= max;
          loop invariant max == (j - 1) * j / 2;
          loop invariant \forall integer k; 1 <= k < j ==> ((k - 1) * k / 2) <= max;
          loop invariant (j <= diff) ==> (max == (j - 1) * j / 2);
          loop invariant (!(j <= diff)) ==> (j == diff + 1 && max == diff * (diff + 1) / 2);
          loop assigns j, max;
            */
            for (int j = 1; j <= diff; j++) {
			max += j;
		}
            
		return result - max;
}
