
#include <limits.h>

        /*@
        predicate max_pos_prefix{L}(int *positions, integer n, integer m) =
          \forall integer k; 0 <= k < n ==> positions[k] <= 0 || positions[k] <= m;
        */
        
int foo309(int * positions, int positions_len) {

		int largest = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant largest >= 0;
          loop assigns index, largest;
            */
            for (int index = 0; index < positions_len; index++) {
			if (positions[index] > 0 && positions[index] > largest) {
				largest = positions[index];
			}
		}
            
		return largest;
}
