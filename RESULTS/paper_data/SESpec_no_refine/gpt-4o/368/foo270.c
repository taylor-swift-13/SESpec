
/*@
  requires n >= 0 && r >= 0 && p > 0;
  assigns \nothing;
  ensures (n < r) ==> (\result == 0);
  ensures (n >= r) ==> (\result == combination(n, r) % p);
*/
int foo270(int n, int r, int p) {

    if (n < r) {
        return 0;
    }

    int ncr = 1;

    /*@
      loop invariant p == \at(p,Pre);
      loop invariant r == \at(r,Pre);
      loop invariant n == \at(n,Pre);
      loop invariant ncr == combination(n, i - 1);
      loop invariant 1 <= i <= r + 1;
      loop assigns i, ncr;
      loop variant r - i + 1;
    */
    for (int i = 1; i <= r; i++) {
        ncr = (ncr * (n - i + 1)) / i;
    }

    return ncr % p;
}
