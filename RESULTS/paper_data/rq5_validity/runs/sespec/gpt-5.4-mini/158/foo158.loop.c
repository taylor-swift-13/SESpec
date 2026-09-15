
/*@
  logic integer array_all_factors_ok(int* factors, integer n, integer j) =
    j >= n ? 1 :
    ((factors[j] == j + 1) ? array_all_factors_ok(factors, n, j + 1) : 0);
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
          loop invariant i == n * 2;
          loop invariant factors_len == n;
          loop invariant \forall integer k; 0 <= k < j ==> factors[k] == k + 1;
          loop assigns j, factors[0 .. n-1];
            */
            for (int j = 0; j < n; j++) {
            factors[j] = j + 1;
        }
            
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant factors_len == n;
          loop invariant \forall integer k; 0 <= k < n ==> factors[k] == k + 1;
          loop assigns i;
            */
            while (1) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= a <= n;
          loop invariant factors_len == n;
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
