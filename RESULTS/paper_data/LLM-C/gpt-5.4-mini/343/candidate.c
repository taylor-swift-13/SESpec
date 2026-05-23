/*@
    requires code != 0;
    requires l <= c;
    requires b >= 0;
    ensures \result == -1 || (l <= \result <= c);
    assigns \nothing;
*/
int countNo(int code, int b, int l, int c) {

		int ret = 0;
		/*@
		    loop invariant l <= loop <= c + 1;
		    loop invariant 0 <= ret <= loop - l + 1;
		    loop invariant ret == \numof(integer i, l <= i < loop && i % code != 0);
		    loop assigns loop, ret;
		    loop variant c - loop + 1;
		*/
		for (int loop = l; loop <= c; loop++) {
			if (loop % code != 0) {
				ret++;
			}
			if (ret == b) {
				return loop;
			}
		}
		return -1;
}
