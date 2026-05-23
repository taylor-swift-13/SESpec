/*@ 
    requires code != 0;
    requires l <= m;
    ensures \result == -1 || (l <= \result <= m && \let count = (\numof integer c; l <= c <= \result && c % code != 0); count == b);
    assigns \nothing;
*/
int countNo(int code, int b, int l, int m) {

		int ret = 0;
		/*@
		loop invariant l <= c <= m + 1;
		loop invariant 0 <= ret <= b;
		loop invariant \forall integer k; l <= k < c ==> (k % code != 0 ==> \let count = (\numof integer x; l <= x <= k && x % code != 0); count == ret);
		loop assigns c, ret;
		loop variant m - c;
		*/
		for (int c = l; c <= m; c++) {
			if (c % code != 0) {
				ret++;
			}
			if (ret == b) {
				return c;
			}
		}
		return -1;
}
