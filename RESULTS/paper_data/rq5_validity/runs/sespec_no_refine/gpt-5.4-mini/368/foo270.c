
/*@ 
  assigns \nothing;
  ensures n < r ==> \result == 0;
  ensures n >= r ==> \result == factorial(n) / (factorial(r) * factorial(n - r)) % p;
*/
int foo270(int n, int r, int p) {

        if (n < r) {
            return 0;
        }

        int ncr = 1;
        
            
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
