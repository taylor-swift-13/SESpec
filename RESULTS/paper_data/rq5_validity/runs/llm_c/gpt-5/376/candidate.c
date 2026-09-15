/*@ axiomatic Combinatorics {
  logic integer fact(integer n);
  axiom fact0: fact(0) == 1;
  axiom fact_rec: \forall integer n; n > 0 ==> fact(n) == n * fact(n - 1);

  logic integer binom(integer n, integer k) = fact(n) / (fact(k) * fact(n - k));

  lemma binom_base_0: \forall integer n; n >= 0 ==> binom(n,0) == 1;
  lemma binom_base_n: \forall integer n; n >= 0 ==> binom(n,n) == 1;

  lemma binom_step:
    \forall integer n, r; 0 < r <= n ==> binom(n, r) * r == binom(n, r - 1) * (n - r + 1);

  lemma binom_sym:
    \forall integer n, k; 0 <= k <= n ==> binom(n, k) == binom(n, n - k);
} */

int binomialCoeff(int seed, int m);

/*@ 
  requires seed >= 0;
  requires 0 <= m <= seed;

  assigns \nothing;

  ensures \result == binom(seed, \old(m));
  ensures \result >= 0;
*/
int binomialCoeff(int seed, int m) {

		if (m > seed - m)
			m = seed - m;
    /*@ assert 0 <= m <= seed; */
    /*@ assert m <= seed - m; */

		int b = 1;
		/*@
      loop invariant 1 <= r <= m + 1;
      loop invariant b == binom(seed, r - 1);
      loop assigns b, r;
      loop variant m - r + 1;
    */
		for (int r = 1; r <= m; r++) {
      /*@ assert r > 0; */
      /*@ assert (b * (seed - r + 1)) % r == 0; */
			b = b * (seed - r + 1) / r;
      /*@ assert b == binom(seed, r); */
		}
		return b;
}
