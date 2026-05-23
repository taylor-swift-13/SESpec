
/*@
  logic integer factorial(integer n) =
    n <= 0 ? 1 : n * factorial(n - 1);
*/

/*@
  logic integer combination(integer n, integer r) =
    r > n || r < 0 ? 0 : factorial(n) / (factorial(r) * factorial(n - r));
*/

/*@
  requires seed >= 0 && m >= 0;
  requires m <= seed; // Ensure m is within valid bounds
  assigns \nothing;
*/
int foo285(int seed, int m) {
    if (m > seed - m)
        m = seed - m;
    int b = 1;

    /*@
      loop invariant 1 <= r <= m + 1;
      loop invariant m == \at(m, Pre) || m == seed - \at(m, Pre);
      loop invariant seed == \at(seed, Pre);
      loop assigns r, b;
      loop variant m - r;
    */
    for (int r = 1; r <= m; r++) {
        b = b * (seed - r + 1) / r;
    }

    return b;
}
