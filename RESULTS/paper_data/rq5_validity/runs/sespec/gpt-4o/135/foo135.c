
/*@ 
  logic integer power(integer base, integer exp) = 
    (exp == 0) ? 1 : base * power(base, exp - 1);
*/

/*@
  requires n >= 0; // Strengthened precondition to ensure n is non-negative
  assigns \nothing;
  ensures n <= 0 ==> \result == 1;
  ensures n > 0 ==> \result == power(x, n);
*/
int foo135(int x, int n) {

        int res = 1;
        /*@
          loop invariant 0 <= i <= n; // i is always within bounds
          loop invariant n >= 0; // Ensure n is non-negative
          loop invariant res == power(x, i); // res correctly represents x^i
          loop assigns i, res; // Variables modified in the loop
          loop variant n - i; // Decreasing variant ensures termination
        */
        for(int i = 0; i < n; i++)
            res = res * x;
        return res;
}
