
/*@ 
  logic integer partial_binom(integer n, integer t) =
    t <= 0 ? 1 : (n - (t - 1)) * partial_binom(n, t - 1) / t;
*/

/*@ 
  logic integer reduced_k(integer k0, integer n0) =
    k0 <= n0 - k0 ? k0 : n0 - k0;
*/

int foo295(int n, int k) {

        if (k > n - k)
            k = n - k;
        int c = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i;
          loop invariant c == partial_binom(n, i - 1);
          loop invariant k == reduced_k(\at(k,Pre), \at(n,Pre));
          loop invariant n == \at(n,Pre);
          loop assigns i, c;
            */
            for (int i = 1; i <= k; i++) {
            c = c * (n - i + 1) / i;
        }
            
        return c;
}
