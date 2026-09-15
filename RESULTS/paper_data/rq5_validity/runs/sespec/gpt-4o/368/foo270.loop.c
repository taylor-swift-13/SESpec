
/*@
  logic integer factorial(integer x) =
    (x <= 1) ? 1 : x * factorial(x - 1);

  logic integer combination(integer n, integer r) =
    (r > n) ? 0 : factorial(n) / (factorial(r) * factorial(n - r));
*/

/*@
  requires n >= r && r >= 0;
  requires p > 0;
  ensures \result == (combination(n, r) % p);
*/
int foo270(int n, int r, int p) {

    if (n < r) {
        return 0;
    }

    int ncr = 1;

    /*@
      loop invariant 1 <= i <= r + 1;
      loop invariant p == \at(p,Pre);
      loop invariant r == \at(r,Pre);
      loop invariant n == \at(n,Pre);
      loop assigns i, ncr;
    */
    for (int i = 1; i <= r; i++) {
        ncr = (ncr * (n - i + 1)) / i;
    }

    return ncr % p;
}
