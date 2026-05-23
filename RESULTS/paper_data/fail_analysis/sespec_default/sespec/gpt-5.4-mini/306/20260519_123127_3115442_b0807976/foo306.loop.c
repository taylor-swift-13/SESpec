
/*@
  logic integer lucas_term(integer k) =
    k == 0 ? 2 :
    k == 1 ? 1 :
    lucas_term(k - 1) + lucas_term(k - 2);
*/

#include <stdlib.h>

int foo306(int n) {

        int *lucas = (int *)malloc(sizeof(int) * (n + 1));
        int lucas_len = n + 1;
        lucas[0] = 2;
        lucas[1] = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop assigns i, lucas[0..n];
            */
            for (int i = 2; i <= n; i++) {
            lucas[i] = lucas[i - 1] + lucas[i - 2];
        }
            
        return lucas[n];
}
