
#include <stdlib.h>

/*@
*/
        

int foo289(int c) {

		int *j = (int *)malloc(sizeof(int) * (c + 1));
int j_len = c + 1;
		j[0] = 2;
		j[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 2 <= d <= c + 1;
              loop invariant \valid(j + (0 .. j_len - 1));
              loop invariant j_len == c + 1;
              loop invariant \forall integer k; 2 <= k < d ==> j[k] == j[k - 1] + 2 * j[k - 2];
              loop assigns d, j[..];
            */
            for (int d = 2; d <= c; d++) {
			j[d] = j[d - 1]
					+ 2 * j[d - 2];
		}
            
		return j[c];
}
