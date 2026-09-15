
#include <limits.h>

/*@
  requires 0 <= count;
  requires 2 * count <= INT_MAX;
  requires (2 * count) * (2 * count) <= INT_MAX;
*/
int foo312(int count) {

		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant diameter == 2 * count;
          loop invariant center == diameter * diameter;
          loop invariant ret >= 0;
          loop invariant 1 <= i <= 2 * count + 1;
          loop invariant (i <= 2 * \at(count,Pre)) ==> \true;
          loop invariant (i <= 2 * \at(count,Pre)) ==> (ret >= 0);
          loop assigns i, ret;
            */
            for (int i = 1; i <= 2 * count; i++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= c <= 2 * count + 1;
          loop invariant ret >= 0;
          loop invariant diameter == 2 * count;
          loop invariant center == diameter * diameter;
          loop invariant 1 <= i <= 2 * count;
            */
            for (int c = 1; c <= 2 * count; c++) {
				int diagnalLengthSquare = (i * i + c * c);
				if (diagnalLengthSquare <= center) {
					ret++;
				}
			}
            
		}
            
		return ret;
}
