/*@ 
  predicate divides(integer d, integer x) = \exists integer k; x == k * d;

  predicate is_gcd(integer g, integer a, integer b) =
    0 < g &&
    divides(g, a) && divides(g, b) &&
    (\forall integer d; 0 < d && divides(d, a) && divides(d, b) ==> d <= g);

  predicate is_lcm(integer L, integer a, integer b) =
    0 < L &&
    divides(a, L) && divides(b, L) &&
    (\forall integer z; 0 < z && divides(a, z) && divides(b, z) ==> L <= z);

  lemma is_lcm_symmetry: \forall integer L,a,b; is_lcm(L,a,b) <==> is_lcm(L,b,a);
*/

int lcm(int n, int y);

/*@ 
  requires n >= 1 && y >= 1;
  assigns \nothing;
  ensures is_lcm(\result, \old(n), \old(y));
*/
int lcm(int n, int y) {

		int ret = 1;
		int g = 1;
		if (n > y) {
			int r = n;
			n = y;
			y = r;
		}
		/*@ assert n <= y; */
		/*@
		  loop invariant 1 <= l <= n + 1;
		  loop invariant n >= 1 && y >= 1;
		  loop invariant divides(ret, n) && divides(ret, y);
		  loop invariant 1 <= ret <= l;
		  loop invariant \forall integer d;
		    0 < d && d <= l && divides(d, n) && divides(d, y) ==> d <= ret;
		  loop assigns ret, l;
		  loop variant n - l + 1;
		*/
		for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
		/*@ assert is_gcd(ret, n, y); */
		/*@ assert divides(ret, n) && divides(ret, y); */
		g = (n * y) / ret;
		/*@ assert is_lcm(g, n, y); */
		return g;
}
