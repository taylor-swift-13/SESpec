
/*@ axiomatic Binom {
  logic integer binom(integer n, integer r);
} */

/*@
  requires p != 0;
  assigns \result \from n, r, p;

  behavior less:
    assumes n < r;
    ensures \result == 0;

  behavior nonpos:
    assumes n >= r && r <= 0;
    ensures \true;

  behavior pos:
    assumes n >= r && r > 0;
    ensures \true;

  complete behaviors;
  disjoint behaviors;
*/
int foo368(int n, int r, int p) {

    if (n < r) {
        return 0;
    }

    int ncr = 1;

    /*@
      loop invariant 1 <= i;
      loop assigns i, ncr;
      loop variant r - i + 1;
    */
    for (int i = 1; i <= r; i++) {
        ncr = (ncr * (n - i + 1)) / i;
    }

    return ncr % p;
}
