/*@
    requires code != 0;
    requires b >= 0;
    assigns \nothing;
    ensures \result == -1 <==> (\sum integer i; l <= i <= m; (i % code != 0) ? 1 : 0) < b;
    ensures \result != -1 ==>
        l <= \result <= m &&
        (\sum integer i; l <= i <= \result; (i % code != 0) ? 1 : 0) == b &&
        (\forall integer j; l <= j < \result ==> (\sum integer i; l <= i <= j; (i % code != 0) ? 1 : 0) != b);
*/
int countNo(int code, int b, int l, int m);

int countNo(int code, int b, int l, int m) {

		int ret = 0;
		/*@
		    loop invariant l <= c <= m+1;
		    loop invariant ret >= 0;
		    loop invariant ret == (\sum integer i; l <= i < c; (i % code != 0) ? 1 : 0);
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
