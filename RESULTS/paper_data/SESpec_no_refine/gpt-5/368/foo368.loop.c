
/*@
  logic integer binom_prefix(integer n0, integer i0) =
    (i0 <= 1) ? 1 : ( (binom_prefix(n0, i0 - 1) * (n0 - (i0 - 1)) ) / (i0 - 1) );
*/

int foo368(int n, int r, int p) {

        if (n < r) {
            return 0;
        }

        int ncr = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant p == \at(p,Pre);
          loop invariant r == \at(r,Pre);
          loop invariant n == \at(n,Pre);
          loop assigns i, ncr;
            */
            for (int i = 1; i <= r; i++) {
            ncr = (ncr * (n - i + 1)) / i;
        }
            

        return ncr % p;
}
