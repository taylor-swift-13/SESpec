/*@ axiomatic Binomial {
  logic integer binom(integer n, integer k);

  axiom binom_outside:
    \forall integer n,k; k < 0 || k > n ==> binom(n,k) == 0;

  axiom binom_base0:
    \forall integer n; n >= 0 ==> binom(n,0) == 1;

  axiom binom_basen:
    \forall integer n; n >= 0 ==> binom(n,n) == 1;

  axiom binom_recur:
    \forall integer n,k; 0 < k < n ==> binom(n,k) == binom(n-1,k-1) + binom(n-1,k);

  lemma binom_sym:
    \forall integer n,k; 0 <= k <= n ==> binom(n,k) == binom(n,n-k);

  lemma binom_step:
    \forall integer n,r; 1 <= r <= n ==> r * binom(n,r) == (n - r + 1) * binom(n, r-1);
} */

int binomialCoeff(int seed, int p);

/*@ 
  requires 0 <= seed;
  requires 0 <= p <= seed;

  // Safe intermediate products and result (no signed overflow during computation):
  requires \let k = (p <= seed - p ? p : seed - p);
           (\forall integer r; 1 <= r <= k ==> binom(seed, r-1) * (seed - r + 1) <= INT_MAX);
  requires binom(seed, (p <= seed - p ? p : seed - p)) <= INT_MAX;

  assigns \nothing;

  ensures \result == binom(seed, (\old(p) <= seed - \old(p) ? \old(p) : seed - \old(p)));
  ensures 0 <= \result;
*/
int binomialCoeff(int seed, int p) {

		if (p > seed - p)
			p = seed - p;
    /*@ assert p == (\at(p,Pre) <= seed - \at(p,Pre) ? \at(p,Pre) : seed - \at(p,Pre)); */

		int b = 1;
    /*@
      loop invariant 1 <= r <= p + 1;
      loop invariant 0 <= b <= binom(seed, p);
      loop invariant b == binom(seed, r - 1);
      loop invariant r <= p ==> (b * (seed - r + 1)) % r == 0;
      loop invariant r <= p ==> b * (seed - r + 1) <= INT_MAX;
      loop assigns r, b;
      loop variant p - r + 1;
    */
		for (int r = 1; r <= p; r++) {
			b = b * (seed - r + 1) / r;
		}
    /*@ assert b == binom(seed, p); */
		return b;
}
