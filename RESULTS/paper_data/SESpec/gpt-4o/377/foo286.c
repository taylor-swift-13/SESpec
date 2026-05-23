
/*@ 
  logic integer factorial(integer n) = 
    (n <= 1) ? 1 : n * factorial(n - 1);
*/

/*@ 
  logic integer binomial_coefficient(integer n, integer k) = 
    (k < 0 || k > n) ? 0 : factorial(n) / (factorial(k) * factorial(n - k));
*/

/*@
  requires seed >= 0;
  requires p >= 0 && p <= seed;
  assigns \nothing;
*/
int foo286(int seed, int p) {

    if (p > seed - p)
        p = seed - p;
    int b = 1;

    /*@
      loop invariant 1 <= r <= p + 1;
      loop invariant p == (\at(p,Pre) <= \at(seed,Pre) - \at(p,Pre) ? \at(p,Pre) : \at(seed,Pre) - \at(p,Pre));
      loop invariant seed == \at(seed,Pre);
      loop assigns r, b;
      loop variant p - r + 1;
    */
    for (int r = 1; r <= p; r++) {
        b = b * (seed - r + 1) / r;
    }

    return b;
}
