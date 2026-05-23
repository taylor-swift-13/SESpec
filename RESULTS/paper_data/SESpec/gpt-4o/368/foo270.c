
/*@
  logic integer factorial(integer x) =
    (x <= 1) ? 1 : x * factorial(x - 1);

  logic integer combination(integer n, integer r) =
    (r > n) ? 0 : factorial(n) / (factorial(r) * factorial(n - r));
*/

/*@
  requires n >= r && r >= 0;
  requires p > 0;
  assigns \nothing;
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
      loop invariant ncr >= 0; // ncr must always be non-negative
      loop assigns i, ncr;
      loop variant r - i;
    */
    for (int i = 1; i <= r; i++) {
        ncr = (ncr * (n - i + 1)) / i;
    }

    return ncr % p;
}
