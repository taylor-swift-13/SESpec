
/*@
  logic integer factorial(integer x) =
    (x <= 1) ? 1 : x * factorial(x - 1);

  logic integer combination(integer n, integer k) =
    (k == 0 || k == n) ? 1 : factorial(n) / (factorial(k) * factorial(n - k));
*/

int foo295(int n, int k) {

    if (k > n - k)
        k = n - k;
    int c = 1;

    /*@
      loop invariant n == \at(n,Pre);
      loop assigns i, c;
    */
    for (int i = 1; i <= k; i++) {
        c = c * (n - i + 1) / i;
    }

    return c;
}
