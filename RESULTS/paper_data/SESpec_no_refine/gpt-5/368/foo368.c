
/*@
  assigns \nothing;
  ensures (n < r) ==> (\result == 0);
  ensures (n >= r) ==> (\result == (binom_prefix(n, r) % p));
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
          loop invariant 1 <= i <= r + 1;
          loop invariant ncr == binom_prefix(n, i);
          loop assigns i, ncr;
            */
            for (int i = 1; i <= r; i++) {
            ncr = (ncr * (n - i + 1)) / i;
        }
            

        return ncr % p;
}
