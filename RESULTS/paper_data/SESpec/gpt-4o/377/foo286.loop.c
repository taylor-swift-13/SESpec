
/*@
  logic integer factorial(integer n) =
    n <= 0 ? 1 : n * factorial(n - 1);

  logic integer binomial_coefficient(integer n, integer k) =
    k == 0 || k == n ? 1 : factorial(n) / (factorial(k) * factorial(n - k));
*/

int foo286(int seed, int p) {

    if (p > seed - p)
        p = seed - p;
    int b = 1;

    /*@
      loop invariant p == (\at(p,Pre) <= \at(seed,Pre) - \at(p,Pre) ? \at(p,Pre) : \at(seed,Pre) - \at(p,Pre));
      loop invariant seed == \at(seed,Pre);
      loop assigns r, b;
    */
    for (int r = 1; r <= p; r++) {
        b = b * (seed - r + 1) / r;
    }

    return b;
}
