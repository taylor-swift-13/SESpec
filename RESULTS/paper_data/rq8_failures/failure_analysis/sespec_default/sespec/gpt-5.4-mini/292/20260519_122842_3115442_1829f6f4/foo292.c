
/*@
  logic integer p_value(int *p, integer i) = p[i];
*/

#include <stdlib.h>


int foo292(int seed) {

		int *p = (int *)malloc(sizeof(int) * (seed + 1));
int p_len = seed + 1;
		p[0] = 0;
		p[1] = 1;
		
            
        /*@
          loop invariant \forall integer i; 0 <= i < count ==> p[i] < 1000000000;
          loop invariant \forall integer i; 2 <= i < count ==>
                           p[i] == (2 * p[i - 1] + p[i - 2]) % 1000000000;
          loop assigns count, p[0 .. seed];
            */
            for (int count = 2; count <= seed; count++) {
			p[count] = (2 * p[count - 1]
					+ p[count - 2]) % 1000000000;
		}
            
		return p[seed];
}
