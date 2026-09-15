
/*@
  logic integer recur_val(integer m, integer d) =
    d == 0 ? 1
    : d == 1 ? m
    : d == 2 ? m*m
    : (m - 1) * (recur_val(m, d-1) + recur_val(m, d-2));
*/
#include <stdlib.h>

/*@
  requires count >= 2;
*/
int foo270(int count, int m) {

		int w = 1000000007;
		int *div = (int *)malloc(sizeof(int) * (count + 1));
int div_len = count + 1;
		div[0] = 1;
		div[1] = m;
		div[2] = m * m;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 3 <= d <= count + 1;
          loop assigns d, div[0 .. count];
            */
            for (int d = 3; d <= count; d++) {
			div[d] = ((m - 1)
					* (div[d - 1] + div[d - 2])) % w;
		}
            
		return div[count];
}
