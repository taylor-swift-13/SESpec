
/*@ 
  logic integer partial_ncr(integer n, integer i) =
    i <= 0 ? 1 : (partial_ncr(n, i-1) * (n - i + 1)) / i;
*/

/*@
  requires \at(n,Pre) >= \at(r,Pre);
  requires r >= 0;
  assigns \nothing;
  ensures \at(n,Pre) < \at(r,Pre) ==> \result == 0;
  ensures \at(n,Pre) >= \at(r,Pre) ==> \result == (partial_ncr(\at(n,Pre), \at(r,Pre)) % \at(p,Pre));
*/
int foo368(int n, int r, int p) {

        if (n < r) {
            return 0;
        }

        int ncr = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i && i <= r + 1;
          loop invariant 0 <= r;
          loop invariant partial_ncr(n, i-1) == ncr;
          loop invariant ncr >= 0;
          loop invariant (\forall integer k; 1 <= k && k <= i-1 ==> partial_ncr(n, k) * 1 == partial_ncr(n, k)); 
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
