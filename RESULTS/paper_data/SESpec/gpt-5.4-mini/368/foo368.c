
/*@
  requires p != 0;
  requires r <= 0;
  assigns \nothing;
  ensures n < r ==> \result == 0;
  ensures n >= r && r <= 0 ==> \result >= 0;
  
*/
int foo368(int n, int r, int p) {

        if (n < r) {
            return 0;
        }

        int ncr = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant i >= 1;
          loop invariant ncr >= 0;
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
