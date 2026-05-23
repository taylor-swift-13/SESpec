/*@ axiomatic Binomial {
  logic integer choose(integer n, integer k);

  axiom choose_base:
    \forall integer n; choose(n, 0) == 1;

  axiom choose_step:
    \forall integer n, k; 1 <= k <= n ==> 
      choose(n, k) == (choose(n, k-1) * (n - k + 1)) / k;

  axiom choose_outside_low:
    \forall integer n, k; k < 0 ==> choose(n, k) == 0;

  axiom choose_outside_high:
    \forall integer n, k; k > n ==> choose(n, k) == 0;

  axiom choose_symmetry:
    \forall integer n, k; 0 <= k <= n ==> choose(n, k) == choose(n, n - k);
} */

int binomialCoeff(int num, int p);

/*@ 
  requires 0 <= num;
  requires 0 <= p <= num;
  assigns \nothing;
  ensures \result == ((\old(p) > num - \old(p)) ? choose(num, num - \old(p)) : choose(num, \old(p)));
  ensures \result == choose(num, \old(p));
  ensures 0 <= \result;
*/
int binomialCoeff(int num, int p) {

		if (p > num - p)
			p = num - p;
    /*@ assert p == ((\at(p,Pre) > num - \at(p,Pre)) ? num - \at(p,Pre) : \at(p,Pre)); */

		int b = 1;
		/*@
      loop invariant 1 <= r <= p + 1;
      loop invariant 0 <= p <= num;
      loop invariant b == choose(num, r - 1);
      loop invariant 0 <= r - 1 <= p;
      loop assigns b, r;
      loop variant p - r + 1;
    */
		for (int r = 1; r <= p; r++) {
			b = b * (num - r + 1) / r;
		}
		return b;
}
