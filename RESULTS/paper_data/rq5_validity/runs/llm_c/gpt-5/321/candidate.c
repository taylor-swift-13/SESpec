int lcm(int n, int y);

/*@ predicate divides(integer a, integer b) =
      (a == 0 ? b == 0 : (\exists integer k; b == a * k));

    predicate is_gcd(integer d, integer a, integer b) =
      d >= 1 &&
      divides(d, a) && divides(d, b) &&
      (\forall integer e; e >= 1 && divides(e, a) && divides(e, b) ==> e <= d);

    predicate is_lcm(integer m, integer a, integer b) =
      m >= 0 &&
      ((a == 0 || b == 0) ? m == 0 :
        (divides(a, m) && divides(b, m) &&
         (\forall integer t; t >= 0 && divides(a, t) && divides(b, t) ==> m <= t)));
*/

/*@ requires n >= 0 && y >= 0;
    assigns \nothing;
    ensures is_lcm(\result, n, y);
*/
int lcm(int n, int y) {

		int ret = 1;
		int r = 1;
		if (n > y) {
			int g = n;
			n = y;
			y = g;
		}
		/*@ assert n <= y; */

		/*@
		  loop invariant 1 <= l <= n + 1;
		  loop invariant ret >= 1;
		  loop invariant divides(ret, n) && divides(ret, y);
		  loop invariant \forall integer k; 1 <= k < l ==> (divides(k, n) && divides(k, y) ==> k <= ret);
		  loop invariant n == \at(n, LoopEntry) && y == \at(y, LoopEntry);
		  loop assigns ret, l;
		  loop variant n - l + 1;
		*/
		for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
		/*@ assert is_gcd(ret, n, y); */

		r = (n * y) / ret;
		/*@ assert is_lcm(r, n, y); */
		return r;
}
