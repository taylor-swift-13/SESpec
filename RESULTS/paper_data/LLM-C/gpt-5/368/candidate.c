/*@ axiomatic Binomial {
      logic integer binom(integer n, integer k);

      axiom binom_out_of_range:
        \forall integer n, k; k < 0 || k > n ==> binom(n, k) == 0;

      axiom binom_base0:
        \forall integer n; n >= 0 ==> binom(n, 0) == 1;

      axiom binom_base_eq:
        \forall integer n; n >= 0 ==> binom(n, n) == 1;

      axiom binom_pascal:
        \forall integer n, k; n >= 1 && 1 <= k <= n - 1 ==>
          binom(n, k) == binom(n - 1, k - 1) + binom(n - 1, k);

      lemma binom_mult_identity:
        \forall integer n, k; n >= 0 && 1 <= k <= n ==>
          k * binom(n, k) == (n - k + 1) * binom(n, k - 1);
  }
*/

/*@ requires 0 <= n;
    requires 0 <= r <= n;
    requires p > 0;

    assigns \nothing;

    ensures 0 <= \result < p;
    ensures \exists integer k; \result == binom(n, r) - k * p;
*/
int ncrModP(int n, int r, int p);

int ncrModP(int n, int r, int p) {

        if (n < r) {
            return 0;
        }

        int ncr = 1;
        /*@
          loop invariant 1 <= i <= r + 1;
          loop invariant 0 <= r <= n;
          loop invariant ncr == binom(n, i - 1);
          loop invariant ncr >= 0;
          loop assigns ncr, i;
          loop variant r - i + 1;
        */
        for (int i = 1; i <= r; i++) {
            /*@ assert i >= 1; */
            /*@ assert ncr == binom(n, i - 1); */
            /*@ assert i * binom(n, i) == (n - i + 1) * binom(n, i - 1); */
            /*@ assert ncr * (n - i + 1) == i * binom(n, i); */
            ncr = (ncr * (n - i + 1)) / i;
            /*@ assert ncr == binom(n, i); */
        }

        /*@ assert ncr == binom(n, r); */
        return ncr % p;
}
