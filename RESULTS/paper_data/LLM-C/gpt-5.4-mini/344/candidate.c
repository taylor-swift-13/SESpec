/*@
    requires code != 0;
    requires l <= m;
    requires b >= 0;
    assigns \nothing;
    ensures \result == -1 || (l <= \result <= m);
    ensures \result != -1 ==> (
        (\numof integer c; l <= c <= \result && c % code != 0) == b
    );
    ensures \result == -1 ==> (
        (\numof integer c; l <= c <= m && c % code != 0) < b
    );
*/
int countNo(int code, int b, int l, int m);

int countNo(int code, int b, int l, int m) {

		int ret = 0;
		/*@
		    loop invariant l <= c <= m + 1;
		    loop invariant 0 <= ret;
		    loop invariant ret == (\numof integer k; l <= k < c && k % code != 0);
		    loop invariant ret <= b;
		    loop assigns c, ret;
		    loop variant m - c + 1;
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
