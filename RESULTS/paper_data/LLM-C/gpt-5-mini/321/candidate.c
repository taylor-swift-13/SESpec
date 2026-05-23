int lcm(int n, int y);

/*@
    requires n >= 0 && y >= 0;
    assigns \nothing;
    behavior zero_present:
        assumes \old(n) == 0 || \old(y) == 0;
        ensures \result == 0;
    behavior both_non_zero:
        assumes \old(n) > 0 && \old(y) > 0;
        ensures \result % \old(n) == 0 && \result % \old(y) == 0;
        ensures \forall integer k; k > 0 && k % \old(n) == 0 && k % \old(y) == 0 ==> k >= \result;
        ensures 0 <= \result && \result <= \old(n) * \old(y);
    complete behaviors zero_present, both_non_zero;
    disjoint behaviors zero_present, both_non_zero;
*/
int lcm(int n, int y) {

		int ret = 1;
		int r = 1;
		if (n > y) {
			int g = n;
			n = y;
			y = g;
		}
		/*@
		    loop invariant 1 <= l && l <= n+1;
		    loop invariant ret >= 1 && ret <= l;
		    loop invariant n % ret == 0 && y % ret == 0;
		    loop assigns ret, l;
		    loop variant n - l + 1;
		*/
		for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
		r = (n * y) / ret;
		return r;
}
