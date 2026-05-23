
#include <stdlib.h>

/*@
  logic integer fibseq(integer k) =
    k == 0 ? 2
    : k == 1 ? 1
    : fibseq(k-1) + fibseq(k-2);
*/

/*@
  requires seed >= 1;
  assigns \nothing;
*/
int foo297(int seed) {

		int *result = (int *)malloc(sizeof(int) * (seed + 1));
int result_len = seed + 1;
		result[0] = 2;
		result[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= l <= seed + 1;
          loop assigns l, result[0..seed];
            */
            for (int l = 2; l <= seed; l++) {
			result[l] = result[l - 1]
					+ result[l - 2];
		}
            
		return result[seed];
}
