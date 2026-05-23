/*@ predicate divides(integer a, integer b) = \exists integer k; b == a * k; */

/*@ predicate is_gcd(integer g, integer a, integer b) =
      g > 0 &&
      divides(g, a) && divides(g, b) &&
      \forall integer d; d > 0 && divides(d, a) && divides(d, b) ==> d <= g;
*/

/*@ predicate is_lcm(integer L, integer a, integer b) =
      a > 0 && b > 0 &&
      L > 0 &&
      divides(a, L) && divides(b, L) &&
      \forall integer m; m > 0 && divides(a, m) && divides(b, m) ==> L <= m;
*/

int lcm(int n, int y);

/*@ requires n > 0 && y > 0;
    assigns \nothing;
    ensures is_lcm(\result, \old(n), \old(y));
*/
int lcm(int n, int y) {

		int ret = 1;
		int l = 1;
		if (n > y) {
			int g = n;
			n = y;
			y = g;
		}
		//@ assert n <= y;
		/*@
		  loop invariant n > 0 && y > 0 && n <= y;
		  loop invariant 1 <= j <= n + 1;
		  loop invariant 1 <= ret <= n;
		  loop invariant divides(ret, n) && divides(ret, y);
		  loop invariant \forall integer d; 1 <= d < j ==> (divides(d, n) && divides(d, y) ==> d <= ret);
		  loop assigns ret, j;
		  loop variant n - j + 1;
		*/
		for (int j = 1; j <= n; j++) {
			if (n % j == 0 && y % j == 0) {
				ret = j;
			}
		}
		//@ assert is_gcd(ret, n, y);
		l = (n * y) / ret;
		return l;
}
