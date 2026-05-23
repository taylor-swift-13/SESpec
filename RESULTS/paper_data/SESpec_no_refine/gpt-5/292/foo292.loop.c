
#include <stdlib.h>

        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        

int foo292(int seed) {

		int *p = (int *)malloc(sizeof(int) * (seed + 1));
int p_len = seed + 1;
		p[0] = 0;
		p[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= count <= seed + 1;
          loop invariant p_len == seed + 1;
          loop invariant \valid(p + (0 .. p_len - 1));
          loop invariant p[0] == 0 && p[1] == 1;
          loop invariant \forall integer k; 2 <= k < count ==> p[k] == (2 * p[k - 1] + p[k - 2]) % 1000000000;
          loop invariant \forall integer k; 0 <= k < count ==> 0 <= p[k] < 1000000000;
          loop assigns count, p[..];
            */
            for (int count = 2; count <= seed; count++) {
			p[count] = (2 * p[count - 1]
					+ p[count - 2]) % 1000000000;
		}
            
		return p[seed];
}
