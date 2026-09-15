
/*@
  logic integer factorial(integer n) =
    n <= 0 ? 1 : n * factorial(n - 1);
*/

/*@
  logic integer combination(integer n, integer r) =
    factorial(n) / (factorial(r) * factorial(n - r));
*/

/*@
  logic integer product_range(integer start, integer end) =
    start > end ? 1 : start * product_range(start + 1, end);
*/

/*@
  logic integer binomial_coefficient(integer seed, integer r) =
    product_range(seed - r + 1, seed) / factorial(r);
*/

int foo285(int seed, int m) {

    if (m > seed - m)
        m = seed - m;
    int b = 1;

    /*@
      loop invariant seed == \at(seed,Pre);
      loop assigns r, b;
    */
    for (int r = 1; r <= m; r++) {
        b = b * (seed - r + 1) / r;
    }

    return b;
}
