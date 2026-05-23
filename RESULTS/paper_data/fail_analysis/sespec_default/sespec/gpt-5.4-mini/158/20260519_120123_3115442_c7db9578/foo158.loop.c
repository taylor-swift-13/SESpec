
/*@
  logic integer factors_prefix_sum(int* factors, integer lo, integer hi) =
    lo >= hi ? 0
             : factors_prefix_sum(factors, lo, hi - 1) + hi;
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
          loop invariant factors_len == n;
          loop invariant \forall integer k; 0 <= k < j ==> factors[k] == k + 1;
          
          loop assigns j, factors[0..n-1];
        */
            for (int j = 0; j < n; j++) {
            factors[j] = j + 1;
        }
            
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant i >= 2 * n;
          loop invariant factors_len == n;
          loop invariant \forall integer k; 0 <= k < n ==> factors[k] == k + 1;
          loop invariant factors[n - 1] == n;
          loop invariant i % factors[n - 1] == 0;
          loop assigns i;
            */
            while (1) {
            
            
        /*@
          loop invariant i >= 2 * n;
          loop invariant factors_len == n;
          loop invariant \forall integer k; 0 <= k < n ==> factors[k] == k + 1;
        */
        
            /*@
          loop invariant i >= 2 * n;
          loop invariant factors_len == n;
          loop invariant \forall integer k; 0 <= k < n ==> factors[k] == k + 1;
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
