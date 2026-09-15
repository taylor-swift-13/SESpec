
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
  requires m >= 0;
  requires seed >= 0;
  assigns m, \nothing;
  ensures \result == binomial_coefficient(seed, m);
*/
int foo285(int seed, int m) {

    if (m > seed - m)
        m = seed - m;
    int b = 1;

    /*@
      loop invariant 1 <= r <= m;
      loop assigns r, b;
    */
    for (int r = 1; r <= m; r++) {
        b = b * (seed - r + 1) / r;
    }

    return b;
}
