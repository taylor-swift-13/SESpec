
#include <stdlib.h>

/*@
  logic integer upseq_elem(integer idx) = idx + 1;

  logic integer count_init_matches{L}(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : count_init_matches(a, lo, hi - 1)
               + (a[hi - 1] == upseq_elem(hi - 1) ? 1 : 0);
*/



int foo158(int n) {

        if (n <= 2) {
            return n;
        }
        int i = n * 2;
        int *factors = (int *)malloc(sizeof(int) * (n));
        int factors_len = n;

        /*@
          loop invariant 0 <= j <= n;
          loop invariant \forall integer k; 0 <= k < j ==> factors[k] == k + 1;
          loop invariant \forall integer k; j <= k < n ==> \true;
          loop assigns j, factors[0..n-1];
        */
        for (int j = 0; j < n; j++) {
            factors[j] = j + 1;
        }

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant factors_len == n;
          loop invariant \forall integer k; 0 <= k < n ==> factors[k] == k + 1;
          loop assigns \nothing;
            */
            while (1) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= a <= n;
          loop invariant \forall integer k; 0 <= k < n ==> factors[k] == k + 1;
          loop assigns a, i;
            */
            for (int a = 0; a < n; a++) {
                if (i % factors[a] != 0) {
                    i += n;
                    break;
                }
                if (factors[a] == factors[n - 1] && i % factors[a] == 0) {
                    return i;
                }
            }
            
        }
            
}
