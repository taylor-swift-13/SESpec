
/*@
  logic integer binom(integer n, integer k) =
    k < 0 || k > n ? 0 :
    k == 0 ? 1 :
    k == 1 ? n :
    n * binom(n-1, k-1) / k;
*/

/*@
  requires seed >= 0;
  requires m >= 0;
  requires 2*m <= seed;
  assigns \nothing;
*/
int foo376(int seed, int m) {
    if (m > seed - m)
        m = seed - m;
    int b = 1;
    /*@
      loop invariant 1 <= r <= m + 1;
      loop invariant seed == \at(seed,Pre);
      loop assigns r, b;
      loop variant m - r + 1;
    */
    for (int r = 1; r <= m; r++) {
        b = b * (seed - r + 1) / r;
    }
    return b;
}
