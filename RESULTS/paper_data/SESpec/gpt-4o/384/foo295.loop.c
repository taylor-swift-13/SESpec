
/*@
  logic integer factorial(integer x) =
    x <= 0 ? 1 : x * factorial(x - 1);

  logic integer binomial_coefficient(integer n, integer k) =
    factorial(n) / (factorial(k) * factorial(n - k));

  logic integer partial_binomial_coefficient(integer n, integer i) =
    i <= 0 ? 1 : (n - i + 1) * partial_binomial_coefficient(n, i - 1) / i;
*/

int foo295(int n, int k) {

    if (k > n - k)
        k = n - k;
    int c = 1;

    /*@
      loop invariant k == (\at(k,Pre) > \at(n,Pre) - \at(k,Pre) ? \at(n,Pre) - \at(k,Pre) : \at(k,Pre));
      loop invariant n == \at(n,Pre);
      loop assigns i, c;
    */
    for (int i = 1; i <= k; i++) {
        c = c * (n - i + 1) / i;
    }

    return c;
}
