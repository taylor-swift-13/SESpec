
#include <stdlib.h>

/*@
  logic integer pell_rec(integer k) =
    k == 0 ? 0
    : k == 1 ? 1
    : (2 * pell_rec(k-1) + pell_rec(k-2)) % 1000000000;
*/

/*@
  predicate pell_array{L}(int *a, integer len, integer upto) =
    0 <= upto <= len &&
    \forall integer j; 0 <= j <= upto ==> a[j] == (int) pell_rec(j);
*/

int foo304(int n) {

        int *pell = (int *)malloc(sizeof(int) * (n + 1));
int pell_len = n + 1;
        pell[0] = 0;
        pell[1] = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i;
          loop assigns i, pell[0..n];
            */
            for (int i = 2; i <= n; i++) {
            pell[i] = (2 * pell[i - 1] + pell[i - 2]) % 1000000000;
        }
            
        return pell[n];
}
