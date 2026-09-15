
/*@
axiomatic Binomial {
  logic integer binom(integer n, integer k) =
    (k <= 0 ? 1 : binom(n, k - 1) * (n - k + 1) / k);
}
*/
        
int foo368(int n, int r, int p) {

        if (n < r) {
            return 0;
        }

        int ncr = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \true;
          loop invariant 1 <= i;
          loop invariant ncr == binom(n, i - 1);
          loop assigns i, ncr;
            */
            for (int i = 1; i <= r; i++) {
            ncr = (ncr * (n - i + 1)) / i;
        }
            

        return ncr % p;
}
