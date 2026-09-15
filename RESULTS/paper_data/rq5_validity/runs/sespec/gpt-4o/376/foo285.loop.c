
/*@
  logic integer factorial(integer n) =
    n <= 0 ? 1 : n * factorial(n - 1);
*/

/*@
  logic integer combination(integer n, integer r) =
    r > n || r < 0 ? 0 : factorial(n) / (factorial(r) * factorial(n - r));
*/

/*@
  requires \at(m,Pre) <= \at(seed,Pre) - \at(m,Pre) || \at(m,Pre) > \at(seed,Pre) - \at(m,Pre);
  requires m >= 0 && seed >= 0;
  assigns \nothing;
*/
int foo285(int seed, int m) {

    if (m > seed - m)
        m = seed - m;
    int b = 1;

    /*@
      loop invariant m == \at(m,Pre) || m == seed - \at(m,Pre);
      loop invariant seed == \at(seed,Pre);
      loop assigns r, b;
    */
    for (int r = 1; r <= m; r++) {
        b = b * (seed - r + 1) / r;
    }

    return b;
}
