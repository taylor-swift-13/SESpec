
/*@
  logic integer binom(integer n, integer k) =
    k < 0 ? 0 :
    (k == 0 ? 1 :
     (k > n ? 0 :
      (binom(n, k - 1) * (n - k + 1)) / k));
*/

/*@
  requires 0 <= seed;
  requires 0 <= m <= seed;
*/
int foo376(int seed, int m) {

    if (m > seed - m)
        m = seed - m;
    int b = 1;

    /*@
      loop invariant 1 <= r <= m + 1;
      loop invariant 0 <= m <= seed;
      loop invariant seed == \at(seed,Pre);

      loop invariant r == 1 ==> b == 1;
      loop assigns r, b;
    */
    for (int r = 1; r <= m; r++) {
        b = b * (seed - r + 1) / r;
    }

    return b;
}
