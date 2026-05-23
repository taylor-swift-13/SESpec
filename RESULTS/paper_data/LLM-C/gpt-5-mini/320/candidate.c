int lcm(int n, int y);

/*@
    requires n > 0 && y > 0;
    assigns \nothing;
    ensures \exists integer d;
        1 <= d && d <= \old(n) && d <= \old(y) &&
        \old(n) % d == 0 && \old(y) % d == 0 &&
        (\forall integer k; k > d && k <= \old(n) && k <= \old(y) ==> !(\old(n) % k == 0 && \old(y) % k == 0)) &&
        \result == (\old(n) * \old(y)) / d;
*/
int lcm(int n, int y) {

		int ret = 1;
		int g = 1;
		if (n > y) {
			int r = n;
			n = y;
			y = r;
		}
		/*@
		    loop invariant 1 <= l && l <= n+1;
		    loop invariant 1 <= ret && ret <= n;
		    loop invariant n % ret == 0 && y % ret == 0;
		    loop invariant (\forall integer j; 1 <= j < l ==> ( (n % j == 0 && y % j == 0) ==> j <= ret ));
		    loop assigns l, ret;
		    loop variant n - l + 1;
		*/
		for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
		g = (n * y) / ret;
		return g;
}
