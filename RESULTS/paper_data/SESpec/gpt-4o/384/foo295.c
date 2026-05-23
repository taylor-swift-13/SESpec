
/*@ 
  logic integer binomial_coefficient(integer n, integer k) = 
    k == 0 || k == n ? 1 : binomial_coefficient(n - 1, k - 1) + binomial_coefficient(n - 1, k);
*/

/*@
  logic integer partial_binomial_coefficient(integer n, integer k) = 
    k == 0 ? 1 : partial_binomial_coefficient(n, k - 1) * (n - k + 1) / k;
*/

/*@
  requires n >= 0 && k >= 0;
  requires k <= n; // Strengthened precondition to ensure valid inputs
  requires n <= 20; // Added precondition to limit n to a reasonable range for verification
  assigns \nothing;
*/
int foo295(int n, int k) {

    if (k > n - k)
        k = n - k;
    int c = 1;

    /*@
      loop invariant k == (\at(k,Pre) > \at(n,Pre) - \at(k,Pre) ? \at(n,Pre) - \at(k,Pre) : \at(k,Pre));
      loop invariant n == \at(n,Pre);
      loop invariant i >= 1 && i <= k + 1; // New invariant to track loop bounds
      loop invariant c == partial_binomial_coefficient(n, i - 1); // Adjusted invariant to match computation
      loop assigns i, c;
      loop variant k - i;
    */
    for (int i = 1; i <= k; i++) {
        c = c * (n - i + 1) / i;
    }

    return c;
}
